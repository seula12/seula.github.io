#include "include/widget/widget_cam_connect.h"
#include "ui_widget_cam_connect.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->ip_text->setText("10.100.82.59");
    ui->port_text->setText("9999");
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_okbutton_clicked()
{
    QString IP=ui->ip_text->toPlainText();
    int Port=ui->port_text->toPlainText().toInt();
    emit sendIP(IP);
    emit sendPort(Port);
    this->close();
    emit startConnect();

}


void Dialog::on_closebutton_clicked()
{
    this->close();
}

