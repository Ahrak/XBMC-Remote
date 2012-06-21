#-------------------------------------------------
#
# Project created by QtCreator 2012-06-19T22:55:55
#
#-------------------------------------------------

QT       += core gui network

TARGET = QXbmcRemote
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    QtWebSocket/QWsSocket.cpp \
    QtWebSocket/QWsServer.cpp \
    remotebutton.cpp

HEADERS  += mainwindow.h \
    QtWebSocket/QWsSocket.h \
    QtWebSocket/QWsServer.h \
    remotebutton.h

FORMS    += mainwindow.ui

RESOURCES += \
    buttonIcons.qrc
