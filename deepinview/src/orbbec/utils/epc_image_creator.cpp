#include "include/orbbec/utils/epc_image_creator.h"
#include "include/orbbec/utils/image_colorizer.h"
#include <inttypes.h>
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QImageWriter>
#include <QList>
#include <QTransform>

/// \addtogroup EpcImageCreator
/// @{


EpcImageCreator::EpcImageCreator(Settings &settings, QObject *parent) :
QObject(parent),
set(settings),
image(set.cam.getImageWidth(), set.cam.getImageHeight(), QImage::Format_ARGB32_Premultiplied) {
    image3D = new double*[set.cam.getImageWidth()];
    for (int i = 0; i < set.cam.getImageWidth(); i++) {
        image3D[i] = new double[set.cam.getImageHeight()];
    }
}

EpcImageCreator::~EpcImageCreator(){
    qDebug() << "***EpcImageCreator destroyed";
}

QImage& EpcImageCreator::pixelFieldToImage(int **data, const int valueMin, const int valueMax, ImageColorizer::ColorSpace colorspace){
    imageColorizer.setRange(valueMin, valueMax);
    legend = imageColorizer.getLegend(colorspace);
    return createImage(data, valueMin, valueMax, colorspace);
}

QImage& EpcImageCreator::createImage(int **data, const int valueMinCreateImage, const int valueMaxCreateImage, ImageColorizer::ColorSpace colorspace){
    for (int x = 0; x < set.cam.getImageWidth(); x++){
        for (int y = 0; y < set.cam.getImageHeight(); y++){
            // MODIFY THIS!!!
            // if(     (data[x][y] > valueMaxCreateImage) &&
            //         (data[x][y] != LOW_AMPLITUDE) &&
            //         (data[x][y] != SATURATION) &&
            //         (data[x][y] != ADC_OVERFLOW)

            // ){
            if (    (data[x][y] > valueMaxCreateImage) //||
//                    (data[x][y] == SATURATION) ||
//                    (data[x][y] == ADC_OVERFLOW)
                ) {
                image.setPixel(x, y,imageColorizer.getColor(valueMaxCreateImage, colorspace).rgb());
//            } else if (data[x][y] == LOW_AMPLITUDE)  {
//                image.setPixel(x, y,imageColorizer.getColor(valueMinCreateImage, colorspace).rgb());
            } else if (data[x][y] < valueMinCreateImage)  {
                image.setPixel(x, y,imageColorizer.getColor(valueMinCreateImage, colorspace).rgb());
            }else{                
                image.setPixel(x, y,imageColorizer.getColor(data[x][y], colorspace).rgb());
            }
        }
    }
    return image;
}

QImage& EpcImageCreator::createDummyImage(){
    image.fill(Qt::white);
    return image;
}

QImage& EpcImageCreator::createModifiedImage(int **data, ImageColorizer::ColorSpace colorspace){
//    int redY = set.red.getRowDivider();
//    if (set.red.getBinningHorizontal() && set.red.getBinningVertical()){
//        for (int x = 0; x < set.cam.getWidth() / 2; x++){
//            for (int y = 0; y < set.cam.getHeight() / redY; y++){
//                image.setPixel(2*x,redY*y,imageColorizer.getColor(data[x][y], colorspace).rgb());
//                image.setPixel(2*x+1,redY*y,imageColorizer.getColor(data[x][y], colorspace).rgb());
//                image.setPixel(2*x,redY*y+1,imageColorizer.getColor(data[x][y], colorspace).rgb());
//                image.setPixel(2*x+1,redY*y+1,imageColorizer.getColor(data[x][y], colorspace).rgb());
//            }
//        }
//    }else if (set.red.getBinningVertical()){
//        for (int x = 0; x < set.cam.getWidth(); x++){
//            for (int y = 0; y < set.cam.getHeight() / redY; y++){
//                image.setPixel(x,redY*y,imageColorizer.getColor(data[x][y], colorspace).rgb());
//                image.setPixel(x,redY*y+1,imageColorizer.getColor(data[x][y], colorspace).rgb());
//            }
//        }
//    }else if (set.red.getBinningHorizontal()){
//        for (int x = 0; x < set.cam.getWidth() / 2; x++){    //always / 2 -> only allowed value with horizontal binning
//            for (int y = 0; y < set.cam.getHeight() / redY; y++){    // ROI height / divider
//                image.setPixel(2*x,redY*y,imageColorizer.getColor(data[x][y], colorspace).rgb());
//                image.setPixel(2*x+1,redY*y,imageColorizer.getColor(data[x][y], colorspace).rgb());
//            }
//        }
//    }
    return image;
}

double** EpcImageCreator::getImage3D(){
    return image3D;
}

QImage& EpcImageCreator::getImage(){
    return image;
}

QImage& EpcImageCreator::getLegend(){
    return legend;
}

void EpcImageCreator::update(){
    image = QImage(set.cam.getImageWidth(), set.cam.getImageHeight(), QImage::Format_ARGB32_Premultiplied);

    delete image3D;
    image3D = new double*[set.cam.getImageWidth()];
    for (int i = 0; i < set.cam.getImageWidth(); i++) {
        image3D[i] = new double[set.cam.getImageHeight()];
    }
}
