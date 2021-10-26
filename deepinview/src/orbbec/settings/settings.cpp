#include "include/orbbec/settings/settings.h"
#include <QDebug>

static const uint8_t major = 2;
static const uint8_t minor = 12;
static const uint8_t patch = 0;
//static const int chip660Version = 6;

Settings::Settings(QObject *parent) :
QObject(parent)
{

    mode = DISTANCE;
    videoMode = false;
    running = false;
    offline = false;
    serverVersion = 0;



}

void Settings::setMode(int index){
    mode = (Mode) index;
    emit modeIndexChanged(index);
}

int Settings::getMode(){
    return mode;
}

bool Settings::isVideoMode(){
    return videoMode;
}

bool Settings::isRunning(){
    return running;
}

void Settings::requestStop(){
    emit stopRequested();
}

void Settings::requestPause(){
    emit pauseRequested();
}

void Settings::start(){
    running = true;
    videoMode = true;
    emit started();
}

bool Settings::getStatusVideo(){
    bool answerVideoStatus=false;
    if(running && videoMode)
        answerVideoStatus=true;

    return answerVideoStatus;
}

void Settings::pause(){
    running = false;
    videoMode = true;
    emit paused();
}


void Settings::stop(){
    videoMode = false;
    emit stopped();
}

void Settings::stopVideo(){
    emit stopped();
}

void Settings::startVideo(){
    emit startedVideo();
}

void Settings::pauseVideo(bool state){
    emit pausedVideo(state);
}



int16_t Settings::getGUIVersion(){
    return major * 10000 + minor * 100 + patch;
}
