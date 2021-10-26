QT       += core gui
QT       += network
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/server/settings_server.cpp \
    src/server/main_server.cpp\
    src/server/qtcp.cpp\
    src/orbbec/settings/settings_camera.cpp \
    src/orbbec/settings/settings.cpp \
    src/orbbec/startup_manager.cpp\
    src/orbbec/utils/epc_image_creator.cpp\
    src/orbbec/utils/pixel_corrector.cpp\
    src/orbbec/utils/pixeledge_filter.cpp \
    src/orbbec/utils/pixel.cpp\
    src/orbbec/utils/image_colorizer.cpp\
    src/orbbec/utils/data_pixelfield.cpp \
    src/widget/widget_cam_connect.cpp \
    src/widget/widget_graph.cpp \
    src/widget/widget_mainwindow.cpp \
    src/widget/widget_screenshot.cpp \
    src/widget/widget_statusdisplay.cpp

HEADERS += \
    include/server/qtcp.h \
    include/server/settings_server.h \
    include/server/main_server.h \
    include/orbbec/settings/settings.h \
    include/orbbec/settings/settings_camera.h \
    include/orbbec/application_context.h\
    include/orbbec/startup_manager.h\
    include/orbbec/utils/epc_image_creator.h\
    include/orbbec/utils/pixel_corrector.h\
    include/orbbec/utils/pixel_edgefilter.h\
    include/orbbec/utils/pixel.h\
    include/orbbec/utils/image_colorizer.h\
    include/orbbec/utils/data_pixelfield.h \
    include/widget/widget_cam_connect.h \
    include/widget/widget_graph.h \
    include/widget/widget_mainwindow.h \
    include/widget/widget_screenshot.h \
    include/widget/widget_statusdisplay.h

FORMS += \
    ui/widget_cam_connect.ui \
    ui/widget_mainwindow.ui \
    ui/widget_screenshot.ui

LIBS += -pthread

win32{
    LIBS += \
        -L$$PWD"./lib_win" -lastra -lastra_core -lastra_core_api -lORBBEC -lOpenNI2 \
        -L$$PWD"./lib_win/Plugins" -lopenni_sensor

    INCLUDEPATH += $$PWD/include_win
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

