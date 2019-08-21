#-------------------------------------------------
#
# Project created by QtCreator 2017-04-05T15:38:38
#
#-------------------------------------------------

QT       += core gui
QT += network
QT += widgets printsupport
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UDP_rec
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    readini.cpp \
    controlparameter.cpp \
    loadconf_sqlit.cpp \
    switchwindow.cpp \
    notepadform.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    readini.h \
    controlparameter.h \
    loadconf_sqlit.h \
    switchwindow.h \
    notepadform.h

FORMS    += mainwindow.ui \
    switchwindow.ui \
    notepadform.ui

DISTFILES += \
    img/sin.png \
    img/slope.png \
    img/triangle.png
