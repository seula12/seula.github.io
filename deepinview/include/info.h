#ifndef INFO_H
#define INFO_H

#include <QObject>
class EpcChipInfo: public QObject
{
    Q_OBJECT
public:
    EpcChipInfo();
};

class GuiInfo: public QObject
{
    Q_OBJECT
public:
    GuiInfo();
    ~GuiInfo();

    int getMajor();
    int getMinor();
    int getPatch();
    int getVersion();
    void setMajor(int major);
    void setMinor(int minor);
    void setPatch(int patch);
    void setVersion(int version);


private:
    int8_t version;
    uint8_t major;
    uint8_t minor;
    uint8_t patch;

};


#endif // INFO_H
