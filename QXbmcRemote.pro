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
    qjsonparser.cpp \
    json.cpp

HEADERS  += mainwindow.h \
    remotebutton.h \
    qjsonparser.h \
    includes.h \
    json.h

FORMS    += mainwindow.ui

RESOURCES += \
    buttonIcons.qrc

OTHER_FILES += \
    lib/lib_json/sconscript


