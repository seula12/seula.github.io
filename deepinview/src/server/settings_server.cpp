#include "include/server/settings_server.h"

SettingsServer::SettingsServer()
{
    imageHeight = 240;
    imageWidth = 320;
}

SettingsServer::~SettingsServer(){
}

int SettingsServer::getImageHeight(){
    return imageHeight;
}

int SettingsServer::getImageWidth(){
    return imageWidth;
}

void SettingsServer::setImageHeight(int arg){
    imageHeight = arg;
}

void SettingsServer::setImageWidth(int arg){
    imageWidth = arg;
}
