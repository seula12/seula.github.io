#include "include/widget/widget_screenshot.h"
#include "ui_widget_screenshot.h"
#include <QDebug>
#include <QString>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QFileDialog>

Screenshot::Screenshot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screenshot)
{
    ui->setupUi(this);
    attach();

}

Screenshot::~Screenshot()
{
    delete ui;
    delete p;
}

void Screenshot::violationsHistory(QImage image,int num, QString date)
{

    switch (num) {
    case 1:
        ui->screen01->clear();
        h=ui->screen01->height();
        w=ui->screen01->width();
        ui->screen01->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen01->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen01->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image1 = image.copy();
        date1 = date;break;
    case 2:
        ui->screen02->clear();
        ui->screen02->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen02->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen02->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image2 = image.copy();
        date2 = date;break;
    case 3:
        ui->screen03->clear();
        ui->screen03->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen03->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen03->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image3 = image.copy();
        date3 = date;break;
    case 4:
        ui->screen04->clear();
        ui->screen04->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen04->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen04->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image4 = image.copy();
        date4 = date;break;
    case 5:
        ui->screen05->clear();
        ui->screen05->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen05->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen05->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image5 = image.copy();
        date5 = date;break;
    case 6:
        ui->screen06->clear();
        ui->screen06->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen06->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen06->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image6 = image.copy();
        date6 = date;break;
    case 7:
        ui->screen07->clear();
        ui->screen07->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen07->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen07->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image7 = image.copy();
        date7 = date;break;
    case 8:
        ui->screen08->clear();
        ui->screen08->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen08->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen08->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image8 = image.copy();
        date8 = date;break;
    case 9:
        ui->screen09->clear();
        ui->screen09->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen09->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen09->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image9 = image.copy();
        date9 = date;break;
    case 10:
        ui->screen10->clear();
        ui->screen10->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen10->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen10->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image10 = image.copy();
        date10 = date;break;
    case 11:
        ui->screen11->clear();
        ui->screen11->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen11->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen11->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image11 = image.copy();
        date11 = date;break;
    case 12:
        ui->screen12->clear();
        ui->screen12->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen12->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen12->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image12 = image.copy();
        date12 = date;break;
    case 13:
        ui->screen13->clear();
        ui->screen13->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen13->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen13->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image13 = image.copy();
        date13 = date;break;
    case 14:
        ui->screen14->clear();
        ui->screen14->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen14->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen14->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image14 = image.copy();
        date14 = date;break;
    case 15:
        ui->screen15->clear();
        ui->screen15->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen15->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen15->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image15 = image.copy();
        date15 = date;break;
    case 16:
        ui->screen16->clear();
        ui->screen16->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->screen16->setPixmap(QPixmap::fromImage(image).scaled(w,h));
        ui->screen16->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
        image16 = image.copy();
        date16 = date;break;
    }

}

void Screenshot::changeviolation(int num)
{
    switch (num) {
    case 1:
    {
        ui->screen01->clear();
        img_copy=image1.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date1);
        ui->screen01->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen01->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 2:
    {
        ui->screen02->clear();
        img_copy=image2.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date2);
        ui->screen02->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen02->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 3:
    {
        ui->screen03->clear();
        img_copy=image3.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date3);
        ui->screen03->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen03->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 4:
    {
        ui->screen04->clear();
        img_copy=image4.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date4);
        ui->screen04->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen04->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 5:
    {
        ui->screen05->clear();
        img_copy=image5.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date5);
        ui->screen05->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen05->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 6:
    {
        ui->screen06->clear();
        img_copy=image6.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date6);
        ui->screen06->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen06->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 7:
    {
        ui->screen07->clear();
        img_copy=image7.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date1);
        ui->screen07->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen07->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 8:
    {
        ui->screen08->clear();
        img_copy=image8.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date8);
        ui->screen08->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen08->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 9:
    {
        ui->screen09->clear();
        img_copy=image9.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date9);
        ui->screen09->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen09->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 10:
    {
        ui->screen10->clear();
        img_copy=image10.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date10);
        ui->screen10->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen10->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 11:
    {
        ui->screen11->clear();
        img_copy=image11.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date11);
        ui->screen11->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen11->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 12:
    {
        ui->screen12->clear();
        img_copy=image12.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date12);
        ui->screen12->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen12->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 13:
    {
        ui->screen13->clear();
        img_copy=image13.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date13);
        ui->screen13->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen13->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 14:
    {
        ui->screen14->clear();
        img_copy=image14.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date14);
        ui->screen14->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen14->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 15:
    {
        ui->screen15->clear();
        img_copy=image15.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date15);
        ui->screen15->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen15->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    case 16:
    {
        ui->screen16->clear();
        img_copy=image16.scaled(QSize(w,h));
        p = new QPainter(&img_copy);
        p->setPen(Qt::white);
        p->setFont(QFont("Arial",7));
        p->drawText(img_copy.rect(),Qt::AlignCenter,date16);
        ui->screen16->setPixmap(QPixmap::fromImage(img_copy));
        ui->screen16->setStyleSheet("border: 2px solid rgb(234, 53, 115);");
        p->end();break;
    }
    }

}

void Screenshot::attach()
{
    ui->screen01->setAttribute(Qt::WA_Hover,true);
    ui->screen01->installEventFilter(this);

    ui->screen02->setAttribute(Qt::WA_Hover,true);
    ui->screen02->installEventFilter(this);

    ui->screen03->setAttribute(Qt::WA_Hover,true);
    ui->screen03->installEventFilter(this);

    ui->screen04->setAttribute(Qt::WA_Hover,true);
    ui->screen04->installEventFilter(this);

    ui->screen05->setAttribute(Qt::WA_Hover,true);
    ui->screen05->installEventFilter(this);

    ui->screen06->setAttribute(Qt::WA_Hover,true);
    ui->screen06->installEventFilter(this);

    ui->screen07->setAttribute(Qt::WA_Hover,true);
    ui->screen07->installEventFilter(this);

    ui->screen08->setAttribute(Qt::WA_Hover,true);
    ui->screen08->installEventFilter(this);

    ui->screen09->setAttribute(Qt::WA_Hover,true);
    ui->screen09->installEventFilter(this);

    ui->screen10->setAttribute(Qt::WA_Hover,true);
    ui->screen10->installEventFilter(this);

    ui->screen11->setAttribute(Qt::WA_Hover,true);
    ui->screen11->installEventFilter(this);

    ui->screen12->setAttribute(Qt::WA_Hover,true);
    ui->screen12->installEventFilter(this);

    ui->screen13->setAttribute(Qt::WA_Hover,true);
    ui->screen13->installEventFilter(this);

    ui->screen14->setAttribute(Qt::WA_Hover,true);
    ui->screen14->installEventFilter(this);

    ui->screen15->setAttribute(Qt::WA_Hover,true);
    ui->screen15->installEventFilter(this);

    ui->screen16->setAttribute(Qt::WA_Hover,true);
    ui->screen16->installEventFilter(this);
}

bool Screenshot::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->screen01 && event->type()==QEvent::HoverEnter){
        changeviolation(1);
    }
    else if(watched==ui->screen01 && event->type()==QEvent::HoverLeave){
        ui->screen01->clear();
        ui->screen01->setPixmap(QPixmap::fromImage(image1).scaled(w,h));
        ui->screen01->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen02 && event->type()==QEvent::HoverEnter){
        changeviolation(2);
    }
    else if(watched==ui->screen02 && event->type()==QEvent::HoverLeave){
        ui->screen02->clear();
        ui->screen02->setPixmap(QPixmap::fromImage(image2).scaled(w,h));
        ui->screen02->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen03 && event->type()==QEvent::HoverEnter){
        changeviolation(3);
    }
    else if(watched==ui->screen03 && event->type()==QEvent::HoverLeave){
        ui->screen03->clear();
        ui->screen03->setPixmap(QPixmap::fromImage(image3).scaled(w,h));
        ui->screen03->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    if(watched==ui->screen04 && event->type()==QEvent::HoverEnter){
        changeviolation(4);
    }
    else if(watched==ui->screen04 && event->type()==QEvent::HoverLeave){
        ui->screen04->clear();
        ui->screen04->setPixmap(QPixmap::fromImage(image4).scaled(w,h));
        ui->screen04->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen05 && event->type()==QEvent::HoverEnter){
        changeviolation(5);
    }
    else if(watched==ui->screen05 && event->type()==QEvent::HoverLeave){
        ui->screen05->clear();
        ui->screen05->setPixmap(QPixmap::fromImage(image5).scaled(w,h));
        ui->screen05->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen06 && event->type()==QEvent::HoverEnter){
        changeviolation(6);
    }
    else if(watched==ui->screen06 && event->type()==QEvent::HoverLeave){
        ui->screen06->clear();
        ui->screen06->setPixmap(QPixmap::fromImage(image6).scaled(w,h));
        ui->screen06->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen07 && event->type()==QEvent::HoverEnter){
        changeviolation(7);
    }
    else if(watched==ui->screen07 && event->type()==QEvent::HoverLeave){
        ui->screen07->clear();
        ui->screen07->setPixmap(QPixmap::fromImage(image7).scaled(w,h));
        ui->screen07->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen08 && event->type()==QEvent::HoverEnter){
        changeviolation(8);
    }
    else if(watched==ui->screen08 && event->type()==QEvent::HoverLeave){
        ui->screen08->clear();
        ui->screen08->setPixmap(QPixmap::fromImage(image8).scaled(w,h));
        ui->screen08->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    if(watched==ui->screen09 && event->type()==QEvent::HoverEnter){
        changeviolation(9);
    }
    else if(watched==ui->screen09 && event->type()==QEvent::HoverLeave){
        ui->screen09->clear();
        ui->screen09->setPixmap(QPixmap::fromImage(image9).scaled(w,h));
        ui->screen09->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen10 && event->type()==QEvent::HoverEnter){
        changeviolation(10);
    }
    else if(watched==ui->screen10 && event->type()==QEvent::HoverLeave){
        ui->screen10->clear();
        ui->screen10->setPixmap(QPixmap::fromImage(image10).scaled(w,h));
        ui->screen10->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen11 && event->type()==QEvent::HoverEnter){
        changeviolation(11);
    }
    else if(watched==ui->screen11 && event->type()==QEvent::HoverLeave){
        ui->screen11->clear();
        ui->screen11->setPixmap(QPixmap::fromImage(image11).scaled(w,h));
        ui->screen11->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen12 && event->type()==QEvent::HoverEnter){
        changeviolation(12);
    }
    else if(watched==ui->screen12 && event->type()==QEvent::HoverLeave){
        ui->screen12->clear();
        ui->screen12->setPixmap(QPixmap::fromImage(image12).scaled(w,h));
        ui->screen12->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen13 && event->type()==QEvent::HoverEnter){
        changeviolation(13);
    }
    else if(watched==ui->screen13 && event->type()==QEvent::HoverLeave){
        ui->screen13->clear();
        ui->screen13->setPixmap(QPixmap::fromImage(image13).scaled(w,h));
        ui->screen13->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen14 && event->type()==QEvent::HoverEnter){
        changeviolation(14);
    }
    else if(watched==ui->screen14 && event->type()==QEvent::HoverLeave){
        ui->screen14->clear();
        ui->screen14->setPixmap(QPixmap::fromImage(image14).scaled(w,h));
        ui->screen14->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen15 && event->type()==QEvent::HoverEnter){
        changeviolation(15);
    }
    else if(watched==ui->screen15 && event->type()==QEvent::HoverLeave){
        ui->screen15->clear();
        ui->screen15->setPixmap(QPixmap::fromImage(image15).scaled(w,h));
        ui->screen15->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    else if(watched==ui->screen16 && event->type()==QEvent::HoverEnter){
        changeviolation(16);
    }
    else if(watched==ui->screen16 && event->type()==QEvent::HoverLeave){
        ui->screen16->clear();
        ui->screen16->setPixmap(QPixmap::fromImage(image16).scaled(w,h));
        ui->screen16->setStyleSheet("border: 2px solid rgba(0, 0, 0,0);");
    }
    return false;
}

