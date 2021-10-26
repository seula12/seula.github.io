#ifndef WIDGET_SCREENSHOT_H
#define WIDGET_SCREENSHOT_H

#include <QWidget>
#include <astra/astra.hpp>
#include <QGraphicsScene>

namespace Ui {
class Screenshot;
}

class Screenshot : public QWidget
{
    Q_OBJECT

public:
    explicit Screenshot(QWidget *parent = nullptr);
    ~Screenshot();
    void violationsHistory(QImage image,int num, QString date);
    void changeviolation(int num);
private:
    Ui::Screenshot *ui;
    void attach();
    bool eventFilter(QObject *watched, QEvent *event);

    int w=64;
    int h=48;
    QImage img_copy;

    QPainter* p;
};

static QImage image1,image2,image3,image4,image5,image6,image7,image8,
              image9,image10,image11,image12,image13,image14,image15,image16;
static QString date1,date2,date3,date4,date5,date6,date7,date8,
               date9,date10,date11,date12,date13,date14,date15,date16;

#endif // WIDGET_SCREENSHOT_H
