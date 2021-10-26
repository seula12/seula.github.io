#ifndef DATA_PIXELFIELD_H
#define DATA_PIXELFIELD_H


#include "include/orbbec/settings/settings.h"
#include <array>
#include <QByteArray>
#include <QObject>

class DataPixelfield : public QObject {
    Q_OBJECT
public:
    explicit DataPixelfield(Settings &settings, QObject *parent = 0);
    DataPixelfield(int** data, Settings &settings, QObject *parent = 0);
    ~DataPixelfield();
    void getData(int **data);
    void setOffset(int offset);
    void appendToLogFile(QString logfile);
    int** getPixelField();
    int getPixelData(int x, int y);
    void setPixelData(int x, int y, int value);
    int calcPixel(QByteArray& data, int i);
    void copyData(DataPixelfield& data);

signals:
    void finished();

public slots:
    void updateData(QByteArray &data);

private:
    Settings &set;
    int** dataPixelfield;
    int offset;
    void clearData();
    double logBase;
};


#endif // DATA_PIXELFIELD_H
