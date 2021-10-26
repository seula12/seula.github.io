#ifndef WIDGET_STATUSDISPLAY_H
#define WIDGET_STATUSDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QVector>

using namespace std;

class WidgetStatusDisplay :public QWidget
{
    Q_OBJECT
public:
    WidgetStatusDisplay();
    ~WidgetStatusDisplay();
    void statusDisplay(QPixmap &buf, vector<bool>status,int w);
    void faceDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int rotate,double ratioW,double ratioH);
    void rightEyesDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int rotate,double ratioW,double ratioH);
    void leftEyesDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int rotate,double ratioW,double ratioH);
    void lipsDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,int rotate,double ratioW,double ratioH);
    void testDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6,
                     double ratioW,double ratioH);

    QPainter *p;
    QPainter *p_other;
    QString txtAlert = "Alert";
    QString txtDrowsy = "Drowsy";
    QString txtCellphone = "Cellphone";
    QString txtSmoking = "Smoking";
    QString txtAttentionLoss = "Attention loss";

    int x;
    int y;
    int gap;
};

#endif // WIDGET_STATUSDISPLAY_H
