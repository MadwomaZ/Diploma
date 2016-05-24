#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T18:05:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diplom_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qpaintwidget.cpp \
    ../Diplom_model_poverchnosty_oop/node.cpp \
    ../Diplom_model_poverchnosty_oop/surface.cpp \
    ../Diplom_model_poverchnosty_oop/generator.cpp \

HEADERS  += mainwindow.h \
    qpaintwidget.h \
    ../Diplom_model_poverchnosty_oop/node.h \
    ../Diplom_model_poverchnosty_oop/surface.h \
    ../Diplom_model_poverchnosty_oop/generator.h \

FORMS    += mainwindow.ui

DISTFILES += \
    ../Diplom_model_poverchnosty_oop/node.h.gch
