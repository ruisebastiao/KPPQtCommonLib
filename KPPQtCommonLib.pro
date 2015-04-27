#-------------------------------------------------
#
# Project created by QtCreator 2015-04-24T23:24:12
#
#-------------------------------------------------

QT       += widgets declarative network webkit multimedia

TARGET = KPPQtCommonLib
TEMPLATE = lib

DEFINES += KPPQTCOMMONLIB_LIBRARY

SOURCES += kppqtcommonlib.cpp \
    kppqtthread.cpp

HEADERS += kppqtcommonlib.h\
        kppqtcommonlib_global.h \
    kppqtthread.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}


include(KPPQtCommonLib.pri)
