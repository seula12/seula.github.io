#ifndef MAIN_SERVER_H
#define MAIN_SERVER_H
#include <QObject>
#include <QImage>
#include "include/server/qtcp.h"
#include "include/orbbec/settings/settings.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(Settings &settings, QObject *parent = 0);
    ~Server();

    bool startConnect();
public slots:
    void setIPaddr(QString ip);
    void setPort(int port);
    void setPassword(QString passwd);
    void sendImageServer(QImage);
    void getAmpPixField(int**);
    void getAmpPixField(QImage, int, int, int, int);
    void getFaceData(vector<int>&);
    int calcPixel(QByteArray&, int);

private:
    Settings &set;
    QTcp *tcpCon;
    int** dataPixelfield;
};



#endif // MAIN_SERVER_H
