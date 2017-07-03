#-------------------------------------------------
#
# Project created by QtCreator 2017-07-01T15:16:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHomeNew
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    mainwindow.cpp \
    houses.cpp

HEADERS  += login.h \
    mainwindow.h \
    houses.h

FORMS    += login.ui \
    mainwindow.ui \
    houses.ui
