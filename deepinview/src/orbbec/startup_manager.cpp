#include "include/orbbec/startup_manager.h"
#include <QDebug>

StartupManager::StartupManager(ApplicationContext &context, QObject *parent):
    QObject(parent),
    set(context.getSettings()),
//    tcpCon(context.getTcpConnection()),
    savedSettings("<Epc>", "<Evalkitepc660>"){

}

StartupManager::~StartupManager(){
    qDebug() << "***StartupManager destroyed";
}

void StartupManager::saveIP(QString ip){
    savedSettings.setValue("IP", ip);
}

QString StartupManager::loadIP(){
    QString ip = savedSettings.value("IP").toString();
    return ip;
}


void StartupManager::setMode(StartupMode startupMode){
    mode = startupMode;
}

StartupMode StartupManager::getMode(){
    return mode;
}



int StartupManager::testConnection(){

}
