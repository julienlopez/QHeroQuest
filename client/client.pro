#-------------------------------------------------
#
# Project created by QtCreator 2012-07-14T20:41:02
#
#-------------------------------------------------

QT       += core gui network

include(../QHeroQuest.pri)

TARGET = QHeroQuestClient
TEMPLATE = app

OBJECTS_DIR = $$QHEROQUEST_OBJ
MOC_DIR = $$QHEROQUEST_OBJ

INCLUDEPATH += .
LIBS += -L$$QHEROQUEST_BIN
LIBS += -lQHeroQuest

SOURCES += main.cpp\
    ui/mainwindow.cpp \
    ui/connexiondialog.cpp

HEADERS  += \
    ui/mainwindow.hpp \
    ui/connexiondialog.hpp
