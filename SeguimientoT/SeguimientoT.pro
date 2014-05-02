#-------------------------------------------------
#
# Project created by QtCreator 2014-04-29T19:22:25
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = SeguimientoT
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
LIBS += `pkg-config opencv --cflags --libs`

SOURCES += main.cpp \
    proceso.cpp \
    robot.cpp

HEADERS += \
    proceso.h \
    robot.h
