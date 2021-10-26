#include "include/orbbec/settings/settings_camera.h"

SettingsCam::SettingsCam()
{
    imageHeight = 480;
    imageWidth  = 640;
    minAmp = 0;
    maxAmp = 255;
}

SettingsCam::~SettingsCam(){
}

int SettingsCam::getImageHeight(){
    return imageHeight;
}

int SettingsCam::getImageWidth(){
    return imageWidth;
}

int SettingsCam::getMaxAmp(){
    return maxAmp;
}

int SettingsCam::getMinAmp(){
    return minAmp;
}

void SettingsCam::setImageHeight(int arg){
    imageHeight = arg;
}

void SettingsCam::setImageWidth(int arg){
    imageWidth = arg;
}
