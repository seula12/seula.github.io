#include "include/info.h"

GuiInfo::GuiInfo(){
    version = -1;
    major   = 2;
    minor   = 12;
    patch   = 0;
}

GuiInfo::~GuiInfo(){
}

int GuiInfo::getMajor(){
    return major;
}

int GuiInfo::getMinor(){
    return minor;
}

int GuiInfo::getPatch(){
    return patch;
}

int GuiInfo::getVersion(){
    return version;
}


void GuiInfo::setMajor(int major){
    this->major = major;
}
void GuiInfo::setMinor(int minor){
    this->minor = minor;
}
void GuiInfo::setPatch(int patch){
    this->patch = patch;
}
void GuiInfo::setVersion(int version){
    this->version = version;
}
