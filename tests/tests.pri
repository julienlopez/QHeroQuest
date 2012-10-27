include(../QHeroQuest.pri)

TARGET = tests

CONFIG -= gui
QT += testlib
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += $$QHEROQUEST_INCLUDE

OBJECTS_DIR = $$QHEROQUEST_OBJ/tests
MOC_DIR = $$QHEROQUEST_OBJ/tests

LIBS += -L$$QHEROQUEST_BIN
LIBS += -lQHeroQuest
