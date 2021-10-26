#ifndef STARTUP_MANAGER_H
#define STARTUP_MANAGER_H

#include "include/application_context.h"
#include "include/orbbec/settings/settings.h"
#include <QObject>
#include <QSettings>
#include <QString>

enum class StartupMode{
    DEFAULT, LAST, OFFLINE
};

class StartupManager : public QObject {
    Q_OBJECT
public:
    explicit StartupManager(ApplicationContext &context, QObject *parent = 0);
    ~StartupManager();
    void setIP(QString ip);
    void setPort(int port);
    void saveIP(QString ip);
    QString loadIP();
    int testConnection();
    QString getServerVersion();
    enum ServerConnection {OK, FAILED, WRONG_VERSION, OLD, OLD_CHIP};
    void revertSettings();
    StartupMode getMode();
    void setMode(StartupMode startupMode);

    bool checkServerVersion(int16_t serverVersion);


private:
    Settings &set;
    QSettings savedSettings;
    StartupMode mode;

};
#endif // STARTUP_MANAGER_H
