#ifndef IMAGE_COLORIZER_H
#define IMAGE_COLORIZER_H

#include <QColor>
#include <QImage>
#include <QObject>
#include <QVector>

class ImageColorizer : public QObject {
    Q_OBJECT
public:
    explicit ImageColorizer (QObject *parent = 0);
    void setRange(int start, int stop);
    enum ColorSpace {GRAYSCALE, BLUETORED, REDTOBLUE};
    QImage& getLegend(ColorSpace colorspace);
    QColor getColor(int value, ColorSpace colorspace);
    ~ImageColorizer();

private:
    QVector<QColor> colorVector;
    QVector<QColor> bwVector;
    QImage legendRedToBlue;
    QImage legendBlueToRed;
    QImage legendGrayscale;
    int begin;
    int end;
    double indexFactorColor;
    double indexFactorBw;
    QColor getCol(int value);
    QColor getColInverted(int value);
    QColor getBw(int value);
    QImage& getColorLegend();
    QImage& getBwLegend();
    double interpolate( double x, double x0, double y0, double x1, double y1);
    void createColorMapPixel(int numSteps, int indx, unsigned char &red, unsigned char &green, unsigned char &blue);

};

#endif // IMAGE_COLORIZER_H
