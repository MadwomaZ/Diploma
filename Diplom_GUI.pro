#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T18:05:00
#
#-------------------------------------------------

QT       += core gui xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diplom_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qpaintwidget.cpp \
    ../Diplom_model_poverchnosty_oop/node.cpp \
    ../Diplom_model_poverchnosty_oop/surface.cpp \
    ../Diplom_model_poverchnosty_oop/generator.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qpaintwidget.h \
    ../Diplom_model_poverchnosty_oop/node.h \
    ../Diplom_model_poverchnosty_oop/surface.h \
    ../Diplom_model_poverchnosty_oop/generator.h \
    qcustomplot.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../Diplom_model_poverchnosty_oop/node.h.gch

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../opt/lib/release/ -ltcmalloc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../opt/lib/debug/ -ltcmalloc
else:unix: LIBS += -L$$PWD/../../../../opt/lib/ -ltcmalloc

INCLUDEPATH += $$PWD/../../../../opt/include
DEPENDPATH += $$PWD/../../../../opt/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../opt/lib/release/ -lprofiler
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../opt/lib/debug/ -lprofiler
else:unix: LIBS += -L$$PWD/../../../../opt/lib/ -lprofiler

INCLUDEPATH += $$PWD/../../../../opt/include
DEPENDPATH += $$PWD/../../../../opt/include
