#-------------------------------------------------
#
# Project created by QtCreator 2012-07-14T20:41:02
#
#-------------------------------------------------

QT       += core gui

include(../QHeroQuest.pri)

TARGET = $$QHEROQUEST_BIN/QHeroQuestClient
TEMPLATE = app

OBJECTS_DIR = $$QHEROQUEST_OBJ
MOC_DIR = $$QHEROQUEST_OBJ

INCLUDEPATH += .
LIBS += -L$$QHEROQUEST_BIN
LIBS += -lQHeroQuest

SOURCES += main.cpp\
        mainwindow.cpp 

HEADERS  += \
    mainwindow.hpp 

