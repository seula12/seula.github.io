#include "include/orbbec/utils/pixel_edgefilter.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

PixelEdgeFilter::PixelEdgeFilter(Settings &settings):
    set(settings),dX(settings),dY(settings),dXY(settings){
}

void PixelEdgeFilter::edgeFilterPixels(DataPixelfield &dist, DataPixelfield &amp){

//    if(set.getEdgeDetection()){
//        //int maxEdgeAmpDiff = 80;
//        int maxEdgeAmpDiff= set.getMaxEdgeAmpDiff(true); //get phase
//        int minPhase =  set.view.getDistanceMin();
//        //minPhase=3000;
//        int diffX = 0;
//        int diffY = 0;
//        //int diffXY = 0;
//        int edgeXdetect = 0;
//        int edgeYdetect = 0;
//        //int edgeXYdetect = 0;
//        int amplTest=0;

//        maxEdgeAmpDiff = maxEdgeAmpDiff  * ((double)set.mod.getModulationFrequency() / (double)set.mod.getModulationFrequencyByIndex(0));

//        if(amplTest==1){
//            for(int i= set.roi.getTopLeftX(); i<set.roi.getBottomRightX(); i++){
//                for(int j= set.roi.getTopLeftY(); j<set.roi.getBottomRightY(); j++){
//                    diffY = abs(amp.getPixelData(i,j)-amp.getPixelData(i,j+1));
//                    dY.setPixelData(i,j,diffY);

//                    if(maxEdgeAmpDiff < diffY){
//                           edgeYdetect++;
//                    }else{
//                        edgeYdetect=0;
//                    }

//                    if((maxEdgeAmpDiff < diffY) && edgeYdetect!=1){
//                        dist.setPixelData(i,j,minPhase);
//                    }
//                }
//            }
//            for(int j= set.roi.getTopLeftY(); j<set.roi.getBottomRightY(); j++){
//                for(int i= set.roi.getTopLeftX(); i<set.roi.getBottomRightX(); i++){
//                    diffX = abs(amp.getPixelData(i,j)-amp.getPixelData(i+1,j));
//                    dX.setPixelData(i,j,diffX);

//                    if(maxEdgeAmpDiff < diffX){
//                           edgeXdetect++;
//                    }else{
//                        edgeXdetect=0;
//                    }

//                    if((maxEdgeAmpDiff < diffX) && edgeXdetect!=1){
//                        dist.setPixelData(i,j,minPhase);
//                    }
//                }
//            }

//        }else{
//            for(int i= set.roi.getTopLeftX(); i<set.roi.getBottomRightX(); i++){
//                for(int j= set.roi.getTopLeftY(); j<set.roi.getBottomRightY(); j++){
//                    diffY = abs(dist.getPixelData(i,j)-dist.getPixelData(i,j+1));
//                    dY.setPixelData(i,j,diffY);

//                    if(maxEdgeAmpDiff < diffY){
//                           edgeYdetect++;
//                    }else{
//                        edgeYdetect=0;
//                    }

//                    if((maxEdgeAmpDiff < diffY) && edgeYdetect!=1){
//                        dist.setPixelData(i,j,minPhase);
//                    }
//                }
//            }
//            for(int j= set.roi.getTopLeftY(); j<set.roi.getBottomRightY(); j++){
//                for(int i= set.roi.getTopLeftX(); i<set.roi.getBottomRightX(); i++){
//                    diffX = abs(dist.getPixelData(i,j)-dist.getPixelData(i+1,j));
//                    dX.setPixelData(i,j,diffX);

//                    if(maxEdgeAmpDiff < diffX){
//                           edgeXdetect++;
//                    }else{
//                        edgeXdetect=0;
//                    }

//                    if((maxEdgeAmpDiff < diffX) && edgeXdetect!=1){
//                        dist.setPixelData(i,j,minPhase);
//                    }
//                }
//            }
//        }
//    }
}




