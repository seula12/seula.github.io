#include "include/widget/widget_statusdisplay.h"
#include <QDebug>
WidgetStatusDisplay::WidgetStatusDisplay()
{
    x=237;
    y=40;
    gap = 18;
}

WidgetStatusDisplay::~WidgetStatusDisplay()
{
    delete p;
}

void WidgetStatusDisplay::statusDisplay(QPixmap &buf, vector<bool>status,int w)
{
    p = new QPainter(&buf);

    p->setPen(Qt::gray);
    p->setFont(QFont("Arial",11,QFont::Bold));
    p->drawText(w-130,y-gap,"Status Display");
    if (status[0])
        p->setPen(Qt::yellow);
    else
        p->setPen(Qt::gray);
    p->setFont(QFont("Arial",9));
    p->drawText(w-130,y,u8"\u25CF "+txtAlert);

    if (status[1])
        p->setPen(Qt::yellow);
    else
        p->setPen(Qt::gray);
    p->setFont(QFont("Arial",9));
    p->drawText(w-130,y+gap,u8"\u25CF "+txtDrowsy);

    if (status[2])
        p->setPen(Qt::yellow);
    else
        p->setPen(Qt::gray);
    p->setFont(QFont("Arial",9));
    p->drawText(w-130,y + 2 * gap,u8"\u25CF "+txtCellphone);

    if (status[3])
        p->setPen(Qt::yellow);
    else
        p->setPen(Qt::gray);
    p->setFont(QFont("Arial",9));
    p->drawText(w-130,y + 3 * gap,u8"\u25CF "+txtSmoking);

    if (status[4])
        p->setPen(Qt::yellow);
    else
        p->setPen(Qt::gray);
    p->setFont(QFont("Arial",9));
    p->drawText(w-130,y + 4 * gap,u8"\u25CF "+txtAttentionLoss);

    p->end();
}

void WidgetStatusDisplay::faceDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int rotate, double ratioW,double ratioH)
{
    p = new QPainter(&buf);

    int xc = (x1*ratioW)+((x2-x1)*ratioW)/2;
    int yc = (y1*ratioH)+((y2-y1)*ratioH)/2;
     p->translate(xc,yc);
    if(rotate>=300)
    {
        rotate=rotate*(-1)+300;
    }

    p->rotate(rotate);
    p->translate(-xc,-yc);
    p->setPen(QPen(QColor(234, 53, 115),2));
    p->drawRect(x1*ratioW,y1*ratioH,(x2-x1)*ratioW,(y2-y1)*ratioH);
    p->setFont(QFont(":/font/font/verdanab.ttf",15,QFont::Bold));
    p->drawText(x1*ratioW,(y1)*ratioH-5,QString::number(rotate));
    p->end();
}

void WidgetStatusDisplay::leftEyesDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int rotate,double ratioW,double ratioH)
{
    p = new QPainter(&buf);

    p->setPen(QPen(QColor(53, 234, 171),2));
    int xc1 = (x1*ratioW)+((x2-x1)*ratioW)/2;
    int yc1 = (y1*ratioH)+((y2-y1)*ratioH)/2;

    p->translate(xc1,yc1);
    if(rotate>=300)
    {
        rotate=rotate*(-1)+300;
    }

    p->rotate(rotate);
    p->translate(-xc1,-yc1);
    p->drawRect(x1*ratioW,y1*ratioH,(x2-x1)*ratioW,(y2-y1)*ratioH);

    p->end();
}

void WidgetStatusDisplay::rightEyesDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int rotate,double ratioW,double ratioH)
{
    p = new QPainter(&buf);
    p->setPen(QPen(QColor(53, 234, 171),2));
    int xc1 = (x1*ratioW)+((x2-x1)*ratioW)/2;
    int yc1 = (y1*ratioH)+((y2-y1)*ratioH)/2;

    p->translate(xc1,yc1);
    if(rotate>=300)
    {
        rotate=rotate*(-1)+300;
    }
    p->rotate(rotate);
    p->translate(-xc1,-yc1);
    p->drawRect(x1*ratioW,y1*ratioH,(x2-x1)*ratioW,(y2-y1)*ratioH);
    p->end();
}

void WidgetStatusDisplay::lipsDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int rotate,double ratioW,double ratioH)
{
    p = new QPainter(&buf);
    int xc = (x1*ratioW)+((x2-x1)*ratioW)/2;
    int yc = (y1*ratioH)+((y2-y1)*ratioH)/2;
     p->translate(xc,yc);
    if(rotate>=300)
    {
        rotate=rotate*(-1)+300;
    }
    p->rotate(rotate);
    p->translate(-xc,-yc);
    p->setPen(QPen(QColor(207, 234, 53),2));
    p->drawRect(x1*ratioW,y3*ratioH,(x2-x1)*ratioW,(y4-y3)*ratioH);
    p->end();
}

void WidgetStatusDisplay::testDisplay(QPixmap &buf, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6,double ratioW,double ratioH)
{
    p = new QPainter(&buf);
    p->setPen(QPen(QColor(Qt::red),4));
    p->drawText(x1*ratioW,y1*ratioH,"1,2");
    p->drawText(x2*ratioW,y2*ratioH,"3,4");
    p->drawText(x3*ratioW,y3*ratioH,"5,6");
    p->drawText(x4*ratioW,y4*ratioH,"7,8");
    p->drawText(x5*ratioW,y5*ratioH,"9,10");
    p->drawText(x6*ratioW,y6*ratioH,"11,12");
    p->drawPoint(x1*ratioW,y1*ratioH);
    p->drawPoint(x2*ratioW,y2*ratioH);
    p->drawPoint(x3*ratioW,y3*ratioH);
    p->drawPoint(x4*ratioW,y4*ratioH);
    p->drawPoint(x5*ratioW,y5*ratioH);
    p->drawPoint(x6*ratioW,y6*ratioH);

    p->end();
}



