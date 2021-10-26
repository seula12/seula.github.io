#ifndef WIDGET_GRAPH_H
#define WIDGET_GRAPH_H
#include <QObject>
#include <QWidget>
#include <QtCharts>
#include <QDebug>

namespace Ui {
    class QMainWindow;
}

class graph:public QWidget
{
    Q_OBJECT
public:
    explicit graph(QWidget *parent = nullptr);
    QChart *eyeDist = new QChart();
    QChartView *eyeDistView = new QChartView(eyeDist);
    QChart *eyebrowDist = new QChart();
    QChartView *eyebrowDistView = new QChartView(eyebrowDist);


public slots:
    void updateVal(int x1, int y1, bool arert, bool drowsy);
private:

    QSplineSeries *sp_eyeL;
    QSplineSeries *sp_eyeR;

    QSplineSeries *sp_alert;
    QSplineSeries *sp_drowsy;

    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    QValueAxis *m_axisBX;
    QValueAxis *m_axisBY;
    qreal m_x;
    qreal m_y;
    qreal scrollX = 0;
};

#endif // WIDGET_GRAPH_H
