#include "include/server/qtcp.h"
#include <QByteArray>
#include <QTcpSocket>
#include <QDataStream>

QTcp::QTcp(Settings &settings, QObject *parent) :
    QObject(parent),
    set(settings)
{

}

QTcp::~QTcp(){
    closeConnection(1000);
    qDebug() << "***QTcp destroyed";
}


void QTcp::setCommand(QString command)
{
    this->command = command+'\n';
}

bool QTcp::setImage(int** img) {
    int i,j;
    QByteArray ba;
    QDataStream stream(&ba, QIODevice::WriteOnly);
    QVector<qint16> vec;

    vec.push_back(1); // num of channel
    vec.push_back(set.serv.getImageHeight()); // height
    vec.push_back(set.serv.getImageWidth()); // width
    vec.push_back(set.cam.getMinAmp()); // min amp.
    vec.push_back(set.cam.getMaxAmp()); // max amp.

    for (i = 0; i < set.cam.getImageHeight(); i++)
        for (j = 0; j < set.cam.getImageWidth(); j++)
            vec.push_back(img[j][i]);

    stream << vec;
    tcpSocket->connectToHost(ip, port);
    if(!tcpSocket->waitForConnected(300)){
        tcpSocket->close();
        return false;
    }

    qint64 written = tcpSocket->write(ba);
    tcpSocket->waitForBytesWritten(-1);
//    qDebug() << "written" << written << "of" << ba.size();
    vec.clear();

    clearResponse();
    tcpSocket->waitForReadyRead(300);
    appendResponse(tcpSocket->readAll());
    tcpSocket->close();
    return true;
}


bool QTcp::setImage(QImage img, int height, int width, int minval, int maxval){
   int i,j;
   QByteArray ba;
   QDataStream stream(&ba, QIODevice::WriteOnly);
   QVector<qint16> vec;

   vec.push_back(1); // num of channel
   vec.push_back(height); // height
   vec.push_back(width); // width
   vec.push_back(minval); // min amp.
   vec.push_back(maxval); // max amp.

   for (i = 0; i < height; i++)
       for (j = 0; j < width; j++)
           vec.push_back(img.pixelColor(j,i).red());  // send red only for it is grayscale image

   stream << vec;
   tcpSocket->connectToHost(ip, port);
   if(!tcpSocket->waitForConnected(300)){
       tcpSocket->close();
       return false;
   }

   qint64 written = tcpSocket->write(ba);
   tcpSocket->waitForBytesWritten(-1);
//   qDebug() << "written" << written << "of" << ba.size();
   vec.clear();


   clearResponse();
   tcpSocket->waitForReadyRead(300);
    appendResponse(tcpSocket->readAll());
//    qDebug() << getInt16();
    tcpSocket->close();
   return true;
}



void QTcp::clearResponse() {
    responseArrayByte.clear();
}

void QTcp::appendResponse(QByteArray response) {
    responseArrayByte.append(response);
}



bool QTcp::executeCommandOnServer(int timeout)
{
    tcpSocket->connectToHost(ip, port);
    if(!tcpSocket->waitForConnected(timeout)){
        tcpSocket->close();
        return false;
    }

    clearResponse();
    tcpSocket->write(command.toStdString().c_str());    //python에서 사용하는 encode, c++에서는 이렇게 해야 하는듯
    tcpSocket->waitForReadyRead(timeout);
    qDebug() << "Reading # of bytes: " << tcpSocket->bytesAvailable();

    appendResponse(tcpSocket->readAll());
    qDebug() << responseArrayByte;
    tcpSocket->close();
    return true;
}


bool QTcp::executeCommandOnCamera(int timeout)
{
    tcpSocket->connectToHost(ip, port);
    if(!tcpSocket->waitForConnected(timeout)){
        tcpSocket->close();
        return false;
    }

    clearResponse();
    tcpSocket->write(command.toStdString().c_str());    //python에서 사용하는 encode, c++에서는 이렇게 해야 하는듯ㅡㅡ;
    if(!tcpSocket->waitForDisconnected(timeout)){
      tcpSocket->disconnectFromHost();
      return false;
    }
    appendResponse(tcpSocket->readAll());
    tcpSocket->close();
    return true;
}




int16_t QTcp::getInt16()
{   
    qDebug() << responseArrayByte;
    QDataStream rtn(responseArrayByte);
    rtn.setByteOrder(QDataStream::LittleEndian);
    int16_t rtn16;
    rtn>>rtn16;
    return rtn16;
}

double QTcp::getDouble()
{
    QDataStream rtn(responseArrayByte);
    rtn.setByteOrder(QDataStream::LittleEndian);

    double rtnDouble;
    rtn>>rtnDouble;
    return rtnDouble;
}

QString QTcp::getQString()
{
    return QString(responseArrayByte);
}

bool QTcp::getBool(){
    return bool(getInt16());
}

QByteArray QTcp::getResponse()
{
    return responseArrayByte;   //byteArray로 보내고 나중에 QDataStream으로 처리
}


QByteArray QTcp::getPicture()
{
    return responseArrayByte;   //byteArray로 보내고 나중에 QDataStream으로 처리
}

int16_t QTcp::getOffset()
{
    setCommand("getOffset");
    executeCommandOnServer(100);
    return getInt16();
}

void QTcp::closeConnection(int timeout)
{
    if(tcpSocket->isOpen()){
        tcpSocket->waitForDisconnected(timeout);
        tcpSocket->abort();
    }
}

void QTcp::setIPaddr(QString ipAddr){
    ip = ipAddr;
}

QString QTcp::getIPaddr(){
    return ip;
}

void QTcp::setPort(int portNumber){
    this->port = portNumber;
}

int QTcp::getPort(){
    return port;
}


void QTcp::setPassword(QString passwd){
    this->password = passwd;
}

QString QTcp::getPassword(){
    return password;
}

