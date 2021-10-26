#ifndef PIXEL_CORRECTOR_H
#define PIXEL_CORRECTOR_H

#include "include/orbbec/utils/data_pixelfield.h"
#include "include/orbbec/settings/settings.h"
#include <QImage>
#include <QString>

class PixelCorrector {
public:
    PixelCorrector(Settings &settings);
    void loadPixelPositionsFromFile(QString filePath);
    void setPixelToColor(QImage &image, QRgb rgb);
    void correctPixels(DataPixelfield &pixelField);
    void getComparedHDRAmplitudeImage(int** amp, int** dist = 0);
    void medianFilter(DataPixelfield &pixelField);
    void gaussFilter(DataPixelfield &pixelField, bool enableFilter, int numIterations);

private:
   Settings &set;
   void parseFile(QString path);
};

#endif // PIXEL_CORRECTOR_H
