#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T10:30:25
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wirelessTelemetry
TEMPLATE = app


SOURCES += main.cpp\
        frontend.cpp \
    backend.cpp \
    controller.cpp

HEADERS  += frontend.h \
    backend.h \
    controller.h

FORMS    += frontend.ui \
    backend.ui
