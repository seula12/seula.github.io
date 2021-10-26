#ifndef APPLICATION_CONTEXT_H
#define APPLICATION_CONTEXT_H

#include "include/orbbec/settings/settings.h"
#include "include/orbbec/utils/epc_image_creator.h"
#include "include/orbbec/utils/pixel_corrector.h"
#include "include/orbbec/utils/pixel_edgefilter.h"
//#include "info.h"
#include <QApplication>
#include <QDebug>

class ApplicationContext{
public:
    ApplicationContext() :
        imgCreator(Settings_),
        pixelCorrector(Settings_),
        pixelEdgeFilter(Settings_)
//        GuiVersion(Settings.guiinfo)
    {
    }

    ~ApplicationContext(){qDebug() << "***ApplicationContext destroyed";}
    Settings& getSettings(){return Settings_;}

//    GuiInfo& getGuiVersion(){return GuiVersion;}

    EpcImageCreator& getImageCreator(){return imgCreator;}
    PixelCorrector& getPixelCorrector(){return pixelCorrector;}
    PixelEdgeFilter& getPixelEdgeFilter(){return pixelEdgeFilter;}

private:
    Settings Settings_;
    EpcImageCreator imgCreator;
    PixelCorrector pixelCorrector;
    PixelEdgeFilter pixelEdgeFilter;
};


#endif // APPLICATION_CONTEXT
