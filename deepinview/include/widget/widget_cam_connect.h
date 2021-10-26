#ifndef WIDGET_CAM_CONNECT_H
#define WIDGET_CAM_CONNECT_H

#include <QDialog>
#include "include/server/main_server.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_okbutton_clicked();

    void on_closebutton_clicked();

signals:
    void sendIP(QString IP);
    void sendPort(int Port);
    void startConnect();
private:
    Ui::Dialog *ui;
};

#endif // WIDGET_CAM_CONNECT_H
