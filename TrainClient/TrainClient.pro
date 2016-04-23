QT += core
QT -= gui

TARGET = TrainClient
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    libs/BlackLib/v3_0/BlackCore.cpp \
    libs/BlackLib/v3_0/BlackGPIO/BlackGPIO.cpp

HEADERS += \
    libs/BlackLib/v3_0/BlackCore.h \
    libs/BlackLib/v3_0/BlackDef.h \
    libs/BlackLib/v3_0/BlackErr.h \
    libs/BlackLib/v3_0/BlackGPIO/BlackGPIO.h

