#ifndef WIDGET_MAINWINDOW_H
#define WIDGET_MAINWINDOW_H

#include <QMainWindow>
#include <astra/astra.hpp>
#include <QGraphicsScene>
#include <QVector>
#include <QTimer>
#include "include/widget/widget_screenshot.h"
#include "include/server/main_server.h"
#include "include/orbbec/settings/settings.h"
#include "include/orbbec/startup_manager.h"
#include "include/widget/widget_statusdisplay.h"
#include "include/widget/widget_graph.h"
#include "include/widget/widget_cam_connect.h"

//QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(ApplicationContext &context,StartupManager &startupManager,QWidget *parent=0);
    ~MainWindow();
    QImage qimg;
    void ir(astra::StreamReader readerIR, QImage &qimg);
    void color(astra::StreamReader readerC, QImage &qimg);
    void depth(astra::StreamReader readerD, QImage &qimg);

    Screenshot screenshot;
public slots:
    void startConnect();

private slots:
    void on_minimize_Button_clicked();

    void on_max_Button_clicked();

    void on_exit_Button_clicked();

    void videoRun();

    void timeupdate();

    void on_start_Btn_clicked();

    void on_Setting_Btn_clicked();

    void on_stop_Btn_clicked();

    void setFps();

    void on_ir_Btn_clicked();

    void on_color_Btn_clicked();

    void on_depth_Btn_clicked();

    void setViolations();

    void Init();

    void on_slideExposureVal_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    QPoint mpos;
    bool max=false;
    bool videoPlay=false;
    bool chap=false;
    QPixmap *qpixmap = new QPixmap;
    QGraphicsScene* scene = new QGraphicsScene;
    vector<int> facedata;
    int num=1049;
    int fixW = 640;
    int fixH = 480;
    int mode=1;
    int viewW,viewH;
    double ratioW,ratioH;
    QString time,date;
    QTimer *timer;
    bool check=false;
    int vioNum=0;
    QString logData;
    int exposVal=1024;

    //Screenshot *screenshot;
    int fpsCount=0;
    QTimer *Runtimer;
    vector <bool> Status{0,0,0,0,0};
    bool offline_mode_on=false;
    int elapseTime=0;

    WidgetStatusDisplay w_statusDisplay;
    graph w_distEye;
    Dialog camConnect;

    StartupManager &startupMgr;
    Settings &set;
    //add
    Server *server;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void timedate(QString);
    void capture(QImage,int,QString);
};
#endif // WIDGET_MAINWINDOW_H
