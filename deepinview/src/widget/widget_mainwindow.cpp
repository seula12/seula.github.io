#include "include/widget/widget_mainwindow.h"
#include "ui_widget_mainwindow.h"
#include "include/server/main_server.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QMouseEvent>
#include "include/widget/widget_cam_connect.h"

MainWindow::MainWindow(ApplicationContext &context,StartupManager &startupManager,QWidget *parent)
    : QMainWindow(parent,Qt::FramelessWindowHint)
    , ui(new Ui::MainWindow),startupMgr(startupManager),
      set(context.getSettings())
{
    server=new Server(set);
    ui->setupUi(this);
    timer=new QTimer(this);
    Runtimer=new QTimer(this);

    connect(&camConnect,SIGNAL(startConnect()),this,SLOT(startConnect()));
    connect(&camConnect,SIGNAL(sendIP(QString)),server,SLOT(setIPaddr(QString)));
    connect(&camConnect,SIGNAL(sendPort(int)),server,SLOT(setPort(int)));
    connect(timer,SIGNAL(timeout()),this,SLOT(timeupdate()));
    connect(Runtimer,SIGNAL(timeout()),this,SLOT(setFps()));
    Init();
}

void MainWindow::Init()
{
    ui->eyeDist->layout()->setContentsMargins(0,0,0,0);
    ui->eyeDist->addWidget(w_distEye.eyeDistView);
    ui->eyebrowDist->addWidget(w_distEye.eyebrowDistView);   
    ui->screenshot_layout->addWidget(&screenshot);
    ui->time_lbl->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
    ui->date_lbl->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    timer->start(1000);
    ui->title->setPixmap(QPixmap(":/res/DIV_common_top_logo_icon.png"));
    ui->exit_Button->setIcon(QIcon(QPixmap(":/res/DIV_common_top_exit_icon_over.png")));
    ui->minimize_Button->setIcon(QIcon(QPixmap(":/res/DIV_common_top_minimize_icon_over.png")));
    ui->homedsm_Button->setIcon(QIcon(QPixmap(":/res/DIV_home_dsm_btn_off.png")));

    if(QTime::currentTime().toString("hh")<"18"|QTime::currentTime().toString("hh")>"6"){
        ui->timeImageL->setPixmap(QPixmap(":/res/DIV_home_right_graph_sun_icon.png"));
        ui->timeImageL2->setPixmap(QPixmap(":/res/DIV_home_right_graph_sun_icon.png"));
    }else{
        ui->timeImageL->setPixmap(QPixmap(":/res/DIV_home_right_graph_moon_icon.png"));
        ui->timeImageL2->setPixmap(QPixmap(":/res/DIV_home_right_graph_moon_icon.png"));
    }
    if(QTime::currentTime().toString("hh")<"12"&&QTime::currentTime().toString("hh")>="0"){
        ui->startTime->setText(QTime::currentTime().toString("hh:mm")+"AM");
        ui->startTime2->setText(QTime::currentTime().toString("hh:mm")+"AM");
        ui->endTime->setText(QTime::currentTime().toString("hh:mm")+"AM");
        ui->endTime2->setText(QTime::currentTime().toString("hh:mm")+"AM");
    }else{
        ui->startTime->setText(QTime::currentTime().toString("hh:mm")+"PM");
        ui->startTime2->setText(QTime::currentTime().toString("hh:mm")+"PM");
        ui->endTime->setText(QTime::currentTime().toString("hh:mm")+"PM");
        ui->endTime2->setText(QTime::currentTime().toString("hh:mm")+"PM");
    }
    ui->ir_Btn->setChecked(true);
    ui->slideExposureVal->setValue(1024);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete server;
    delete Runtimer;

    astra::terminate();
}

void MainWindow::on_minimize_Button_clicked()
{
    this->showMinimized();
}

void MainWindow::on_max_Button_clicked()
{
    if(max==false){
       this->showFullScreen();
       max=true;}
    else{
       this->showNormal();
       max=false;}
}

void MainWindow::on_exit_Button_clicked()
{
    this->close();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->buttons()==Qt::LeftButton)
        mpos=event->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(mpos.y()<=35){
        if(event->buttons()&Qt::LeftButton){
           QPoint diff=event->pos()-mpos;
           QPoint newpos=this->pos()+diff;
           this->move(newpos);
        }
    }
}

void MainWindow::videoRun(){
    ui->ir_Btn->setEnabled(!videoPlay);
    ui->color_Btn->setEnabled(!videoPlay);
    ui->depth_Btn->setEnabled(!videoPlay);
    if(videoPlay){
        Runtimer->start(1000);
        ui->homedsm_Button->setIcon(QIcon(QPixmap(":/res/DIV_home_dsm_btn_on.png")));

        astra::initialize();
        astra::ImageStreamMode irMode;
        astra::ImageStreamMode cMode;
        astra::ImageStreamMode dMode;

        astra::StreamSet streamSetIR;
        astra::StreamSet streamSetC;
        astra::StreamSet streamSetD;

        irMode.set_width(fixW);
        irMode.set_height(fixH);
        irMode.set_pixel_format(astra_pixel_formats::ASTRA_PIXEL_FORMAT_GRAY16);
        irMode.set_fps(30);

        cMode.set_width(fixW);
        cMode.set_height(fixH);
        cMode.set_pixel_format(astra_pixel_formats::ASTRA_PIXEL_FORMAT_RGB888);
        cMode.set_fps(30);

        dMode.set_width(fixW);
        dMode.set_height(fixH);
        dMode.set_pixel_format(astra_pixel_formats::ASTRA_PIXEL_FORMAT_DEPTH_MM);
        dMode.set_fps(30);

        astra::StreamReader readerIR    = streamSetIR.create_reader();
        astra::StreamReader readerC     = streamSetC.create_reader();
        astra::StreamReader readerD     = streamSetD.create_reader();

        readerIR.stream<astra::InfraredStream>().set_mode(irMode);
        readerC.stream<astra::ColorStream >().set_mode(cMode);
        readerD.stream<astra::DepthStream>().set_mode(dMode);

        readerIR.stream<astra::InfraredStream>().stop();
        readerC.stream<astra::ColorStream>().stop();
        readerD.stream<astra::DepthStream>().stop();
        switch(mode){
        case 1:
            readerIR.stream<astra::InfraredStream>().start();
            break;
        case 2://Color
           readerC.stream<astra::ColorStream>().start();
           break;
       case 3://Depth
           readerD.stream<astra::DepthStream>().start();
           break;
        }
        qimg = QImage(fixW,fixH, QImage::Format_RGB888);
        ui->imageViewer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->imageViewer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        astra::DeviceController(streamSetIR).set_ir_exposure_value(exposVal);
        qDebug()<<"slide control1";
        do{
            facedata.clear();
            scene->clear();
            astra_update();
            viewH = ui->imageViewer->height();
            viewW = ui->imageViewer->width();
            switch(mode){
            case 1:
                ir(readerIR,qimg);
                break;
            case 2:
                color(readerC,qimg);
                break;
            case 3:
                depth(readerD,qimg);
                break;
            }
            astra::DeviceController(streamSetIR).set_ir_exposure_value(exposVal);
            server->getAmpPixField(qimg.scaled(set.serv.getImageWidth(),set.serv.getImageHeight()),set.serv.getImageHeight() ,set.serv.getImageWidth(), 0, 255);
            server->getFaceData(facedata);
            Status.at(0) = !facedata[21];
            Status.at(1) = facedata[21];
            setViolations();

            QPixmap buf = QPixmap::fromImage(qimg);
            buf = buf.scaled(viewW,viewH);
            ratioW=(double)viewW/320.00;
            ratioH=(double)viewH/240.00;
            if(facedata[22]!=0){//face detection
                w_statusDisplay.statusDisplay(buf, Status,viewW);

                w_statusDisplay.faceDisplay(buf,facedata[1],facedata[2],facedata[3],facedata[4],facedata[23],ratioW,ratioH);
                w_statusDisplay.leftEyesDisplay(buf,facedata[5],facedata[6],facedata[7],facedata[8],facedata[23],ratioW,ratioH);

                w_statusDisplay.rightEyesDisplay(buf,facedata[9],facedata[10],facedata[11],facedata[12],facedata[23],ratioW,ratioH);

                w_distEye.updateVal(facedata[8]-facedata[6],facedata[12]-facedata[10],Status[0],Status[1]);
            }

            if(ui->logDataList->count()>=30){ui->logDataList->clear();}

            scene->addPixmap(buf);
            ui->imageViewer->setScene(scene);
            ui->lblEyeDistL->setText(QString::number(facedata[8]-facedata[6]));
            ui->lblEyeDistR->setText(QString::number(facedata[12]-facedata[10]));

            ui->lblLEyeCenterX->setText(QString::number((int)((facedata[7]-facedata[5])*ratioW/2)));
            ui->lblLEyeCenterY->setText(QString::number((int)((facedata[8]-facedata[6])*ratioH/2)));
            ui->lblREyeCenterX->setText(QString::number((int)((facedata[11]-facedata[9])*ratioW/2)));
            ui->lblREyeCenterY->setText(QString::number((int)((facedata[12]-facedata[10])*ratioH/2)));
            qApp->processEvents();
            fpsCount++;

        }while(videoPlay);
        astra::terminate();
        }
    ui->homedsm_Button->setIcon(QIcon(QPixmap(":/res/DIV_home_dsm_btn_off.png")));
    Runtimer->stop();
}


void MainWindow::timeupdate(){
    ui->time_lbl->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
    ui->date_lbl->setText(QDate::currentDate().toString("yyyy-MM-dd"));
}

void MainWindow::ir(astra::StreamReader readerIR, QImage &qimg)
{
    astra::Frame ir = readerIR.get_latest_frame();
    astra::InfraredFrame16 ir16 = ir.get<astra::InfraredFrame16>();
    for (int i = 0; i < fixH; i++){
        for (int j = 0; j < fixW; j++)
            qimg.setPixel(j, i, qRgb(ir16.data()[i*fixW +j] >> 2 , ir16.data()[i*fixW +j] >> 2, ir16.data()[i*fixW +j] >> 2));
    }
}
void MainWindow::color(astra::StreamReader readerC, QImage &qimg){
    astra::Frame C = readerC.get_latest_frame();
    astra::ColorFrame cFrame = C.get<astra::ColorFrame>();

    for (int i = 0; i < fixH; i++){
        for (int j = 0; j < fixW; j++)
            qimg.setPixel(j, i, qRgb(cFrame.data()[i*fixW +j].r, cFrame.data()[i*fixW +j].g, cFrame.data()[i*fixW +j].b));
    }
}
void MainWindow::depth(astra::StreamReader readerD, QImage &qimg){
    astra::Frame D = readerD.get_latest_frame();
    astra::DepthFrame dFrame = D.get<astra::DepthFrame>();

    for (int i = 0; i < fixH; i++){
        for (int j = 0; j < fixW; j++)
            qimg.setPixel(j, i, qRgb(dFrame.data()[i*fixW +j], dFrame.data()[i*fixW +j], dFrame.data()[i*fixW +j]));
    }
}

void MainWindow::on_start_Btn_clicked()
{
    ui->start_Btn->setStyleSheet("background-color:green");
    ui->stop_Btn->setStyleSheet("background-color:white");
    videoPlay=true;
    videoRun();
}


void MainWindow::on_Setting_Btn_clicked()
{
    camConnect.setModal(true);
    camConnect.exec();
}


void MainWindow::on_stop_Btn_clicked()
{
    ui->start_Btn->setStyleSheet("background-color:white");
    ui->stop_Btn->setStyleSheet("background-color:green");
    videoPlay=false;
    videoRun();
}

void MainWindow::setFps(){
    ui->fps_lbl->setText(QString::number(fpsCount));
    fpsCount=0;
    elapseTime++;
    ui->TimeElapsed_lbl->setText(QString::number(elapseTime));

    if(QTime::currentTime().toString("hh")<"18"|QTime::currentTime().toString("hh")>"6"){
        ui->timeImageR->setPixmap(QPixmap(":/res/DIV_home_right_graph_sun_icon.png"));
        ui->timeImageR2->setPixmap(QPixmap(":/res/DIV_home_right_graph_sun_icon.png"));
    }else{
        ui->timeImageR->setPixmap(QPixmap(":/res/DIV_home_right_graph_moon_icon.png"));
        ui->timeImageR2->setPixmap(QPixmap(":/res/DIV_home_right_graph_moon_icon.png"));
    }
    if(QTime::currentTime().toString("hh")<"12"&&QTime::currentTime().toString("hh")>="0"){
        ui->endTime->setText(QTime::currentTime().toString("hh:mm")+"AM");
        ui->endTime2->setText(QTime::currentTime().toString("hh:mm")+"AM");
    }else{
        ui->endTime->setText(QTime::currentTime().toString("hh:mm")+"PM");
        ui->endTime2->setText(QTime::currentTime().toString("hh:mm")+"PM");
    }
}

void MainWindow::on_ir_Btn_clicked(){mode=1;}

void MainWindow::on_color_Btn_clicked(){mode=2;}

void MainWindow::on_depth_Btn_clicked(){mode=3;}

void MainWindow::startConnect(){
    qDebug()<<"startConnect";
    if (!offline_mode_on) {
        ui->start_Btn->setStyleSheet("background-color:green");
        ui->stop_Btn->setStyleSheet("background-color:white");
        videoPlay=true;
        videoRun();
    }
}

void MainWindow::setViolations()
{
    if(facedata[21]){//open : false, close : true
        if(check){//violation발생 시 한번만 출력
            check=false;
            vioNum++;
            if(vioNum>16){vioNum=1;}
            logData = u8"\u25CF "+QDate::currentDate().toString("yyyy.MM.dd")+" "+QDateTime::currentDateTime().toString("hh:mm:ss");
            ui->logDataList->addItem(logData);
            screenshot.violationsHistory(qimg,vioNum,QDate::currentDate().toString("yy.MM.dd")+"\n"+QDateTime::currentDateTime().toString("hh:mm:ss"));
            ui->lblStatus->setText("sleep");
        }
        ui->lblEyeStatL->setText("Closed");
        ui->lblEyeStatR->setText("Closed");
    }
    else{
        check=true;
        ui->lblEyeStatL->setText("Open");
        ui->lblEyeStatR->setText("Open");
        ui->lblStatus->setText("not sleep");
    }
}

void MainWindow::on_slideExposureVal_sliderMoved(int position)
{
    exposVal=position;
    ui->lblExposureVal->setText(QString::number(exposVal));
}
