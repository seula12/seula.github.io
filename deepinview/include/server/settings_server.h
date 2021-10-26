#ifndef SETTINGS_SERVER_H
#define SETTINGS_SERVER_H

class SettingsServer{
    public:
        explicit SettingsServer();
        ~SettingsServer();
        int getImageHeight();
        int getImageWidth();
        void setImageHeight(int arg);
        void setImageWidth(int arg);
private:
        int imageHeight;
        int imageWidth;
};

#endif // SETTINGS_SERVER_H
