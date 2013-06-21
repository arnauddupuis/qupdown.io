#-------------------------------------------------
#
# Project created by QtCreator 2013-06-14T15:36:06
#
#-------------------------------------------------

QT       += core gui network webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qupdownio-ui
TEMPLATE = app

LIBS += -lqupdownio

# Install directory
isEmpty( INSTALLDIR ) {
    INSTALLDIR = /usr/local/qupdownio/$$TARGET
    win32:INSTALLDIR = "C:\Program Files\qupdownio\$$TARGET"
    macx:INSTALLDIR = "/Applications"
}

INCLUDEPATH += ../libqupdownio

DEPENDPATH += ../libqupdownio

OBJECTS_DIR = ../build
UI_DIR = $$OBJECTS_DIR
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR

SOURCES += main.cpp\
        mainwindow.cpp \
    qupdowniosettings.cpp

HEADERS  += mainwindow.h \
    qupdowniosettings.h

FORMS    += mainwindow.ui \
    qupdowniosettings.ui

target.path = $$INSTALLDIR/bin
win32:target.path = $$INSTALLDIR
maxc:target.path = $$INSTALLDIR


INSTALLS += target

RESOURCES += \
    qupdownio-ui-res.qrc
