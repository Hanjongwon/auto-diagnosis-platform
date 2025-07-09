#-------------------------------------------------
#
# Project created by QtCreator 2021-07-30T13:19:02
#
#-------------------------------------------------

QT       += core gui sql webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kwix_project
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
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui
INCLUDEPATH +=/usr/local/include/opencv4/
INCLUDEPATH +=/usr/local/include/raspicam/
INCLUDEPATH +=/usr/local/include/
LIBS += -L/usr/local/lib -lopencv_videoio -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lraspicam -lraspicam_cv -lopencv_imgproc -lopencv_objdetect
LIBS += -L/opt/vc/lib -lmmal -lmmal_core -lmmal_util

LIBS += -lwiringPi

LIBS += -lpigpio -lrt -lpthread


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
