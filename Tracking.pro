#-------------------------------------------------
#
# Project created by QtCreator 2013-11-27T22:12:15
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Tracking
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += `pkg-config opencv --cflags --libs`
SOURCES += main.cpp \
    FramesperSecond.cpp \
    proceso.cpp \
    robot.cpp

HEADERS += \
    proceso.h \
    robot.h
