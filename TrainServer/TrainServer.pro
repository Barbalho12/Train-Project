#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T13:41:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainServer
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    trem.cpp \
    semaforo.cpp

HEADERS  += mainwindow.h \
    trem.h \
    semaforo.h

FORMS    += mainwindow.ui
