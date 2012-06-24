#-------------------------------------------------
#
# Project created by QtCreator 2012-06-19T22:55:55
#
#-------------------------------------------------

QT       += core gui network script

TARGET = QXbmcRemote
TEMPLATE = app

PRECOMPILED_HEADER = includes.h

SOURCES += main.cpp\
        mainwindow.cpp \
    remotebutton.cpp \
    json.cpp \
    config.cpp \
    interface.cpp \
    jsonparser.cpp

HEADERS  += includes.h \
    mainwindow.h \
    remotebutton.h \
    json.h \
    config.h \
    interface.h \
    jsonparser.h

FORMS  += mainwindow.ui

RESOURCES += \
    buttonIcons.qrc

OTHER_FILES += \
    lib/lib_json/sconscript


