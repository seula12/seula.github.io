#include "include/widget/widget_mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include <QTimer>
#include <QPainter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/res/16X16.png"));
    QPixmap pixmap(":/res/DIV_splash_bg.png"); // splash picture

    QPainter *painter = new QPainter(&pixmap);
    painter->setPen("#c7c7c7");
    painter->setFont(QFont("Verdana",7));
    painter->drawText(QPoint(430,175),"Version 0. 9. 8");
    painter->setPen("#838383");
    painter->setFont(QFont("Verdana",8));
    painter->drawText(QPoint(100,315),"Copyright@DEEP-IN-SIGHT Co.,Ltd All Right Reserved");
    painter->setPen("#89898a");
    painter->setFont(QFont("Verdana",10));
    painter->drawText(QPoint(30,200),"Vision");
    painter->drawText(QPoint(120,200),"Disconnected");
    painter->drawText(QPoint(30,220),"MCB");
    painter->drawText(QPoint(120,220),"Disconnected");
    painter->drawText(QPoint(30,240),"VPC");
    painter->drawText(QPoint(120,240),"Initialaized");
    painter->drawText(QPoint(30,260),"Camera");
    painter->drawText(QPoint(120,260),"Initialaized");

    QSplashScreen *splash=new QSplashScreen(pixmap,Qt::WindowStaysOnTopHint);
    splash->show();
    a.thread()->sleep(5);
    painter->end();
    a.processEvents();
    qDebug()<<"splash End";
    ApplicationContext context;
    qDebug()<<"context";
    StartupManager startupManager(context);
    qDebug()<<"startupManager";
    MainWindow w(context, startupManager);
    w.show();
    splash->finish(&w);

    return a.exec();
}
