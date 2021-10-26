#include "include/orbbec/utils/data_pixelfield.h"


#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <math.h>

DataPixelfield::DataPixelfield(Settings &settings, QObject *parent) :
    QObject(parent),
    set(settings){
    dataPixelfield = new int*[set.cam.getImageWidth()];
    for (int i = 0; i < set.cam.getImageWidth(); i++) {
        dataPixelfield[i] = new int[set.cam.getImageHeight()]; //
    }
    offset = 0;

}

DataPixelfield::DataPixelfield(int** data, Settings &settings, QObject *parent):
    QObject(parent),
    set(settings) {
    dataPixelfield = data;
}


DataPixelfield::~DataPixelfield(){
}


void DataPixelfield::getData(int** data){
    dataPixelfield = data;
}

void DataPixelfield::clearData(){
    for (int x = 0; x < set.cam.getImageWidth(); x++){
        for (int y = 0; y < set.cam.getImageHeight(); y++){
            dataPixelfield[x][y] = -1;
        }
    }
}

void DataPixelfield::updateData(QByteArray &data){
    int pixel;
    int width = set.cam.getImageWidth();
    int height = set.cam.getImageHeight();

    clearData();

    for (int i = 0; i < (data.size() / 4); i++) {
        pixel = calcPixel(data, data.size() / 4 - 1 - i);
//        dataPixelfield[] = pixel;
//        ???
//        dataPixelfield[] = pixel;
        pixel = calcPixel(data, data.size() / 4 + i);

    }

    emit finished();
}

int DataPixelfield::calcPixel(QByteArray &data, int  i){
    uint8_t pixelMSB = (uint8_t) data.at(2*i+1);
    uint8_t pixelLSB = (uint8_t) data.at(2*i);
    int pixel = (((int)pixelMSB << 8) + pixelLSB);
    if (pixel < 8000){ // no special value like saturation, ADC overflow or too low amplitude
        if (set.getMode() == 4) { // logarithmic amplitude
            pixel = log(pixel) / logBase + 0.5; // +0.5 for proper integer rounding
        }
        return pixel - offset;
    }else {
        return pixel;
    }
}

int** DataPixelfield::getPixelField(){
    return dataPixelfield;
}


int DataPixelfield::getPixelData(int x, int y){
    return dataPixelfield[x][y];
}

void DataPixelfield::setPixelData(int x, int y, int value){
    dataPixelfield[x][y] = value;
}

void DataPixelfield::setOffset(int offset){
    this->offset = offset;
}

void DataPixelfield::copyData(DataPixelfield& data){
    for (int x = 0; x < set.cam.getImageWidth(); x++){
        for (int y = 0; y < set.cam.getImageHeight(); y++){
            dataPixelfield[x][y] = data.getPixelData(x,y);
        }
    }
}
