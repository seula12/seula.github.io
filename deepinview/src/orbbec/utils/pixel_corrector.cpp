#include "include/orbbec/utils/pixel_corrector.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/// \addtogroup PixelCorrector
/// @{

PixelCorrector::PixelCorrector(Settings &settings) :
set(settings){
}

void PixelCorrector::loadPixelPositionsFromFile(QString filePath){

}

void PixelCorrector::parseFile(QString path){

}

void PixelCorrector::correctPixels(DataPixelfield &pixelField){
//    for(Pixel pixel : set.calibration.getPixelPositions()){
//        if (pixel.x > set.roi.getTopLeftX() &&
//            pixel.y >= set.roi.getTopLeftY() &&
//            pixel.x <= set.roi.getBottomRightX() &&
//            pixel.y <= set.roi.getBottomRightY()){
//             int pixelLeft = pixelField.getPixelData(pixel.x-1,pixel.y);
//             pixelField.setPixelData(pixel.x,pixel.y,pixelLeft);
//        }else if (pixel.x >= set.roi.getTopLeftX() &&
//                  pixel.y > set.roi.getTopLeftY() &&
//                  pixel.x <= set.roi.getBottomRightX() &&
//                  pixel.y <= set.roi.getBottomRightY()){
//            int pixelAbove = pixelField.getPixelData(pixel.x,pixel.y-1);
//            pixelField.setPixelData(pixel.x,pixel.y,pixelAbove);
//        }else if (pixel.x >= set.roi.getTopLeftX() &&
//                  pixel.y >= set.roi.getTopLeftY() &&
//                  pixel.x < set.roi.getBottomRightX() &&
//                  pixel.y <= set.roi.getBottomRightY()){
//            int pixelRight = pixelField.getPixelData(pixel.x+1,pixel.y);
//            pixelField.setPixelData(pixel.x,pixel.y,pixelRight);
//        }
//    }
}

void PixelCorrector::setPixelToColor(QImage &image, QRgb rgb){
//    for(Pixel pixel : set.calibration.getPixelPositions()){
//        image.setPixel(pixel.x, pixel.y, rgb);
//    }
}


void PixelCorrector::getComparedHDRAmplitudeImage(int** amp, int** dist){

//    if(set.calc.isHDRMaxAmplitude()){

//        int highAmpThreshold = 2000;

//        for(int i= set.roi.getTopLeftX(); i<=set.roi.getBottomRightX(); i++){
//            for(int j= set.roi.getTopLeftY(); j<=set.roi.getBottomRightY(); j+=2){
//                int amp1 = amp[i][j];
//                int amp2 = amp[i][j+1];
//                int ampCase = 1;

//                if(amp1 < highAmpThreshold && amp2 < highAmpThreshold){ // both amplitudes in range
//                    if(amp2 > amp1) ampCase = 2;
//                    else            ampCase = 1;
//                }else if(amp1 >= highAmpThreshold && amp2 <= highAmpThreshold){ //one amplitude in range or both amplitudes LOW_AMPLITUDE
//                    ampCase = 2;
//                }else if(amp1 <= highAmpThreshold && amp2 >= highAmpThreshold){ //one amplitude in range or both amplitudes LOW_AMPLITUDE
//                    ampCase = 1;
//                }else{ //both amplitudes out of range
//                    if(amp2 < amp1) ampCase = 1;
//                    else            ampCase = 2;
//                }

//                if(ampCase == 1){
//                    if(dist!=0){
//                        dist[i][j+1] = dist[i][j];
//                    }
//                    amp[i][j+1] = amp[i][j];
//                }else{
//                    if(dist!=0){
//                        dist[i][j] = dist[i][j+1];
//                    }
//                    amp[i][j] = amp[i][j+1];
//                }
//            }
//        }
//    }
}

//============================================================================

void PixelCorrector::medianFilter(DataPixelfield &pixelField){
    int i, j, k, x, y, val;
    vector<int> arr;
    int data [328][252];

    int sz = 5;//set.getMedianFilterSize();
    int n = sz/2;
    int pos = (sz*sz)/2;

    //qDebug()<<"PixelCorrector::medianFilter size, iterations:"<< set.getMedianFilter()<< set.getMedianFilterSize()<<set.getMedianFilterIterations();

//    if(set.getMedianFilter()){

//        for(k=0; k< set.getMedianFilterIterations(); k++){

//            //for(y= set.roi.getTopLeftY()+n; y<=set.roi.getBottomRightY()-n; y++){
//            //    for(x= set.roi.getTopLeftX()+n; x<=set.roi.getBottomRightX()-n; x++){
//            for(y= n; y<set.roi.getMaxHeight()-n; y++){
//                for(x= n; x<set.roi.getMaxWidth()-n; x++){

//                    arr.clear();

//                    for(j=y-n; j<=y+n; j++){
//                        for(i=x-n; i<= x+n; i++){
//                            //if(y<set.roi.getTopLeftY() || x<set.roi.getTopLeftX() || y>set.roi.getBottomRightY() || x>set.roi.getBottomRightX() ){
//                            //    val = 0;
//                            //}else{
//                                val = pixelField.getPixelData(i,j);
//                            //}
//                            arr.push_back(val);
//                        }
//                    }
//                    sort(arr.begin(), arr.end());
//                    data[x][y] = arr.at(pos);
//                }
//            }


//            for(x= set.roi.getTopLeftX(); x<=set.roi.getBottomRightX(); x++){
//                for(y= set.roi.getTopLeftY(); y<=set.roi.getBottomRightY(); y++){
//                    pixelField.setPixelData(x, y, data[x][y]);
//                }
//            }
//        }

//    }

}


void PixelCorrector::gaussFilter(DataPixelfield &pixelField, bool enableFilter, int numIterations){
//    int i, x, y;
//    int data [328][252];
//    int val, val2, val3, val4, val5, val6, val7, val8, val9;
//    int minPhase =  set.view.getDistanceMin();

//    if(enableFilter){

//        for(i=0; i< numIterations; i++){

//            for(y= set.roi.getTopLeftY()+1; y<set.roi.getBottomRightY(); y++){
//                for(x= set.roi.getTopLeftX()+1; x<set.roi.getBottomRightX(); x++){

//                    val  = pixelField.getPixelData(x-1, y-1);
//                    val2 = pixelField.getPixelData(x,   y-1);
//                    val3 = pixelField.getPixelData(x+1, y-1);

//                    val4 = pixelField.getPixelData(x-1, y);
//                    val5 = pixelField.getPixelData(x,   y);
//                    val6 = pixelField.getPixelData(x+1, y);

//                    val7 = pixelField.getPixelData(x-1, y+1);
//                    val8 = pixelField.getPixelData(x,   y+1);
//                    val9 = pixelField.getPixelData(x+1, y+1);

//                    if((val  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val2  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val3  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val4  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val5  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val6  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val7  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val8  <LOW_AMPLITUDE && (val>minPhase)) &&
//                       (val9  <LOW_AMPLITUDE && (val>minPhase))){

//                        val += val2 << 1;  // * 2;
//                        val += val3;
//                        val += val4 << 1; // * 2;
//                        val += val5 << 2; // * 4;
//                        val += val6 << 1; // * 2;
//                        val += val7;
//                        val += val8 << 1; // * 2;
//                        val += val9;
//                        val = val>>4;     // /16;
//                        data[x][y] = val;

//                    }else{
//                        data[x][y] = val5;
//                    }

//                }
//            }


//            for(x= set.roi.getTopLeftX()+1; x<set.roi.getBottomRightX(); x++){
//                for(y= set.roi.getTopLeftY()+1; y<set.roi.getBottomRightY(); y++){
//                    pixelField.setPixelData(x, y, data[x][y]);
//                }
//            }

//        }
//    }

}
