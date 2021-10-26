#ifndef SETTINGS_CAMERA_H
#define SETTINGS_CAMERA_H

#include <QObject>

class SettingsCam : public QObject {
    Q_OBJECT
public:
    explicit SettingsCam();
    ~SettingsCam();

    int getImageHeight();
    int getImageWidth();
    void setImageHeight(int);
    void setImageWidth(int);

    int getMaxAmp();
    int getMinAmp();

private:
    int imageHeight;
    int imageWidth;
    int maxAmp;
    int minAmp;

};

#endif // SETTINGS_CAMERA_H
