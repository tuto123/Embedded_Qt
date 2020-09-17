#-------------------------------------------------
#
# Project created by QtCreator 2020-08-21T14:01:38
#
#-------------------------------------------------

QT       += core gui network qmqtt

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4418_home_security
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        common.cpp \
        environmentalmonitor.cpp \
        facerecognition.cpp \
        homecontrol.cpp \
        main.cpp \
        mainwindow.cpp \
        video_device.cpp \
        weatherquery.cpp

HEADERS += \
        common.h \
        environmentalmonitor.h \
        facerecognition.h \
        homecontrol.h \
        mainwindow.h \
        v4l2grab.h \
        video_device.h \
        weatherquery.h

FORMS += \
        environmentalmonitor.ui \
        facerecognition.ui \
        homecontrol.ui \
        mainwindow.ui \
        weatherquery.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += /usr/local/cv_3.1.4-arm_5.10.0/include
LIBS +=/usr/local/cv_3.1.4-arm_5.10.0/lib/libopencv_*.so

RESOURCES += \
    qsrc.qrc
