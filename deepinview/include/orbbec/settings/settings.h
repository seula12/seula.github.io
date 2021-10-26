#ifndef SETTINGS_H
#define SETTINGS_H

#include "include/server/settings_server.h"
#include "include/orbbec/settings/settings_camera.h"
#include "include/info.h"

#include <QObject>
#include <QString>
#include <QVector>

class Settings : public QObject {
    Q_OBJECT
public:
    explicit Settings (QObject *parent = 0);

    void setCommand(QString command);
    QString getCommand();
    void setMode(int index);
    int getMode();
    SettingsServer serv;
    SettingsCam cam;

   // USE GRAYSCALE == 0 or AMPLITUDE_BW == 3
    enum Mode {GRAYSCALE, DISTANCE_AMPLITUDE, DISTANCE, AMPLITUDE, AMPLITUDE_BW, AMPLITUDE_LOG, POINT_CLOUD, DCS, DIFDCS, DCS_GRAY, HDR, FLIM};


    static bool checkServerVersion(int16_t serverVersion);
    static int16_t getGUIVersion();


    static const QString VERSION;
    bool isVideoMode();
    bool isRunning();
    void requestStop();
    void requestStart();
    void requestPause();
    void start();
    bool getStatusVideo();
    void pause();
    void stop();
    void stopVideo();
    void startVideo();
    void pauseVideo(bool state);


signals:
    void modeIndexChanged(int);
    void stopRequested();
    void startRequested();
    void pauseRequested();
    void paused();
    void stopped();
    void started();
    void startedVideo();
    void pausedVideo(bool state);



private:
    Mode mode;
    uint16_t serverVersion;

    QString command;
    bool videoMode;
    bool running;
    bool offline;


    uint8_t  icVersion;
    int partVersion;

};




#endif // SETTINGS_H
