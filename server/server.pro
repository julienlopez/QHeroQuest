include(../QHeroQuest.pri)

TARGET = QHeroQuestServer

QT -= gui
QT += network
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += $$QQHEROQUEST_INCLUDE

LIBS += -L$$QHEROQUEST_BIN
LIBS += -lQHeroQuest

HEADERS += \
    client.hpp \
    messagehandler.hpp

SOURCES += \
    main.cpp \
    client.cpp \
    messagehandler.cpp
