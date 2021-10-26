#ifndef EPC_IMAGE_CREATOR_H
#define EPC_IMAGE_CREATOR_H

#include "include/orbbec/utils/image_colorizer.h"
#include "include/orbbec/utils/pixel.h"
#include "include/orbbec/settings/settings.h"
#include <QImage>
#include <QImageWriter>
#include <QObject>
#include <vector>

class EpcImageCreator : public QObject {
    Q_OBJECT
public:
    explicit EpcImageCreator (Settings &settings, QObject *parent = 0);
    ~EpcImageCreator();
    QImage& pixelFieldToImage(int **data, const int valueMin, const int valueMax, ImageColorizer::ColorSpace colorspace);
    QImage& createDummyImage();
    double** getImage3D();
    QImage& getImage();
    QImage& getLegend();
    void update();

private:
    double **image3D;
    Settings &set;
    QImage image;
    QImage legend;
    ImageColorizer imageColorizer;
    QImage& createImage(int **data, const int valueMinCreateImage, const int valueMaxCreateImage, ImageColorizer::ColorSpace colorspace);
    QImage& createModifiedImage(int **data, ImageColorizer::ColorSpace colorspace);
};

#endif // EPC_IMAGE_CREATOR_H
