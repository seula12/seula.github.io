#ifndef QTCP_H
#define QTCP_H
#include <iostream>
#include <QByteArray>
#include <QTcpSocket>
#include <QImage>
#include "include/orbbec/settings/settings.h"

using namespace std;
typedef unsigned char Byte;

class QTcp: public QObject
{
    Q_OBJECT
public:
    explicit QTcp(Settings &settings, QObject *parent = 0);
    ~QTcp();

    QString ip          = "192.168.7.2";
    quint16 port        = 50660;
    QString command     = "";
    QString password    = "";

    QTcpSocket *tcpSocket = new QTcpSocket();
    QByteArray responseArrayByte;

    void appendResponse(QByteArray response);
    void setCommand(QString command);
    bool executeCommandOnServer(int timeout);
    bool executeCommandOnCamera(int timeout);
    void clearResponse();
    int16_t getInt16();
    double getDouble();
    QString getQString();
    bool getBool();
    QByteArray getResponse();
    QByteArray getPicture();
    int16_t getOffset();
    void closeConnection(int timeout);
    void pauseVideo();

    void setIPaddr(QString IPaddr);
    void setPort(int portNumber);
    void setPassword(QString passwd);

    QString getIPaddr();
    int getPort();
    QString getPassword();

    bool setImage(int**);
    bool setImage(QImage, int, int, int, int);

    QTcp* returnQTcp() {return this;}

private:
    Settings &set;

};

#endif // QTCP_H
