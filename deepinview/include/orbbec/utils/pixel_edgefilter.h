#ifndef PIXEL_EDGEFILTER_H
#define PIXEL_EDGEFILTER_H

#include "include/orbbec/utils/data_pixelfield.h"
#include "include/orbbec/settings/settings.h"
#include <QImage>
#include <QString>

class PixelEdgeFilter {
public:
    PixelEdgeFilter(Settings &settings);
    void edgeFilterPixels(DataPixelfield &dist, DataPixelfield &amp);

private:
   Settings &set;
   DataPixelfield dX;
   DataPixelfield dY;
   DataPixelfield dXY;
   //void parseFile(QString path);
};

#endif // PIXEL_EDGEFILTER_H
