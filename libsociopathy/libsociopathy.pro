#-------------------------------------------------
#
# Project created by QtCreator 2013-06-21T00:24:45
#
#-------------------------------------------------

QT       += widgets qml quick network xml xmlpatterns

TARGET = libsociopathy
TEMPLATE = lib

DEFINES += LIBSOCIOPATHY_LIBRARY

SOURCES += libsociopathy.cpp

HEADERS += libsociopathy.h\
        libsociopathy_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
