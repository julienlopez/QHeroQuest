include(../QHeroQuest.pri)

TARGET = QHeroQuestServer

QT -= gui
QT += network
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

OBJECTS_DIR = $$QHEROQUEST_OBJ/server
MOC_DIR = $$QHEROQUEST_OBJ/server

INCLUDEPATH += $$QQHEROQUEST_INCLUDE

LIBS += -L$$QHEROQUEST_BIN
LIBS += -lQHeroQuest

HEADERS += \
    client.hpp \
    messagehandler.hpp \
    serveur.hpp \
    sutils.hpp \
    localserveur.hpp

SOURCES += \
    main.cpp \
    client.cpp \
    messagehandler.cpp \
    serveur.cpp \
    sutils.cpp \
    localserveur.cpp
