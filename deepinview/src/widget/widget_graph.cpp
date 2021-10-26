#include "include/widget/widget_graph.h"
#include "ui_widget_mainwindow.h"
#include <QLinearGradient>
graph::graph(QWidget *parent):
    m_axisX(new QValueAxis()),//axis line
    m_axisY(new QValueAxis()),
    m_axisBX(new QValueAxis()),
    m_axisBY(new QValueAxis()),
    m_x(10),//qreal
    m_y(1)//qreal
{
    sp_eyeL = new QSplineSeries(this);
    sp_eyeR = new QSplineSeries(this);
    sp_alert = new QSplineSeries(this);
    sp_drowsy = new QSplineSeries(this);

    QPen p_eyeL(QColor(121,72,188));
    p_eyeL.setWidth(3);
    QPen p_eyeR(QColor(187,68,163));
    p_eyeR.setWidth(3);
    QPen p_arert(QColor(86,178,186));
    p_arert.setWidth(2);
    QPen p_drowsy(QColor(251,183,29));
    p_drowsy.setWidth(2);

    sp_eyeL->setPen(p_eyeL);
    sp_eyeR->setPen(p_eyeR);
    sp_alert->setPen(p_arert);
    sp_drowsy->setPen(p_drowsy);

    sp_eyeL->setName("Left eye");
    sp_eyeR->setName("Right eye");

    sp_alert->setName("Alert");
    sp_drowsy->setName("Drowsy");

    eyeDist->addSeries(sp_eyeL);
    eyeDist->addSeries(sp_eyeR);
    eyebrowDist->addSeries(sp_alert);
    eyebrowDist->addSeries(sp_drowsy);

    eyeDist->legend()->setAlignment(Qt::AlignTop);
    eyeDist->legend()->setLabelColor(QColor(132,132,132));
    eyeDist->setBackgroundBrush(QColor(34,34,34));
    eyebrowDist->legend()->setAlignment(Qt::AlignTop);
    eyebrowDist->legend()->setLabelColor(QColor(132,132,132));
    eyebrowDist->setBackgroundBrush(QColor(34,34,34));

    eyeDist->addAxis(m_axisX,Qt::AlignBottom);
    eyeDist->addAxis(m_axisY,Qt::AlignLeft);
    eyebrowDist->addAxis(m_axisBX,Qt::AlignBottom);
    eyebrowDist->addAxis(m_axisBY,Qt::AlignLeft);

    sp_eyeL->attachAxis(m_axisX);
    sp_eyeL->attachAxis(m_axisY);
    sp_eyeR->attachAxis(m_axisX);
    sp_eyeR->attachAxis(m_axisY);

    sp_alert->attachAxis(m_axisBX);
    sp_alert->attachAxis(m_axisBY);
    sp_drowsy->attachAxis(m_axisBX);
    sp_drowsy->attachAxis(m_axisBY);

    m_axisX->setTickCount(5);
    m_axisY->setTickCount(2);
    m_axisBX->setTickCount(5);
    m_axisBY->setTickCount(2);

    m_axisX->hide();
    m_axisY->hide();
    m_axisBX->hide();
    m_axisBY->hide();

//    m_axisX->setLabelsVisible(false);
//    m_axisY->setLabelsVisible(false);
//    m_axisBX->setLabelsVisible(false);
//    m_axisBY->setLabelsVisible(false);

    m_axisX->setLinePen(QPen(QColor(132,132,132)));
    m_axisY->setLinePen(QPen(QColor(132,132,132)));
    m_axisBX->setLinePen(QPen(QColor(132,132,132)));
    m_axisBY->setLinePen(QPen(QColor(132,132,132)));

    m_axisX->setRange(0, 10);
    m_axisY->setRange(15, 25);
    m_axisBX->setRange(0, 10);
    m_axisBY->setRange(-0.2,1.2);

    eyeDist->layout()->setContentsMargins(5,5,5,5);
    eyeDist->setBackgroundRoundness(false);
    eyebrowDist->layout()->setContentsMargins(5,5,5,5);
    eyebrowDist->setBackgroundRoundness(false);

}
void graph::updateVal(int y1, int y2, bool alert, bool drowsy)
{
    scrollX+=2;
    qreal x = eyeDist->plotArea().width() / m_axisX->tickCount();
    qreal x2 = eyebrowDist->plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    m_y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    sp_eyeL->append(m_x, y1+0.5);
    sp_eyeR->append(m_x, y2-0.5);
    sp_alert->append(m_x, alert);
    sp_drowsy->append(m_x, drowsy);
    eyeDist->scroll(x, 0);
    eyebrowDist->scroll(x2, 0);
}
