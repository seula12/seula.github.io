#include "include/server/main_server.h"
#include <QDebug>
#include "include/widget/widget_cam_connect.h"

Server::Server(Settings &settings, QObject *parent) :
    QObject(parent),
    set(settings)
{
    Dialog dialog;
    connect(&dialog,SIGNAL(sendIP(QString)),this,SLOT(setIPaddr(QString)));
    connect(&dialog,SIGNAL(sendPort(int)),this,SLOT(setPort(int)));
    dataPixelfield = new int*[set.serv.getImageWidth()];

    for (int i = 0; i < set.serv.getImageWidth(); i++) {
        dataPixelfield[i] = new int[set.serv.getImageHeight()];
    }

    qDebug()<<"server Start ";
    tcpCon  = new QTcp(set);
}

Server::~Server()
{
}

int Server::calcPixel(QByteArray &data, int  i){
    uint8_t pixelMSB = (uint8_t) data.at(2*i+1);
    uint8_t pixelLSB = (uint8_t) data.at(2*i);
    int pixel = (((int)pixelMSB << 8) + pixelLSB);
    return pixel;
}


void Server::setIPaddr(QString ip){
    qDebug()<<"setIPaddr"<<ip;
    tcpCon->setIPaddr(ip);
}

void Server::setPort(int port){
    qDebug()<<"setport"<<port;
    tcpCon->setPort(port);  
}

void Server::setPassword(QString passwd){
    tcpCon->setPassword(passwd);
}

void Server::getAmpPixField(int** data){
//    qDebug() << data;
    dataPixelfield = data;
    tcpCon->setImage(data);
}

void Server::getAmpPixField(QImage img, int height, int width, int minval, int maxval){
    tcpCon->setImage(img, height, width, minval, maxval);
}

bool Server::startConnect(){
    tcpCon->setCommand(tcpCon->getPassword());
    tcpCon->executeCommandOnServer(300);
    return tcpCon->getBool();
}

void Server::sendImageServer(QImage img){
	qDebug() << "tcpCon.setImage(img)";
//    tcpCon.setImage(img);
}

void Server::getFaceData(vector<int>& data){

    //qDebug() << 1;
    QByteArray response = tcpCon->getResponse();
    //qDebug() << 2;
    for (int i = 0; i < (response.size() / 2); i++) {
//        qDebug()<< calcPixel(response,i);
        data.push_back(calcPixel(response,i));
    }
    //qDebug() << 3;
    tcpCon->clearResponse();
    //qDebug() << 4;
//    
}

