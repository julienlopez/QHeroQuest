include(../QHeroQuest.pri)

TARGET = $$QHEROQUEST_BIN/tests

QT -= gui
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

INCLUDEPATH += $$QQHEROQUEST_INCLUDE

LIBS += -L$$QQHEROQUEST_BIN
LIBS += -lQHeroQuest

HEADERS += \
    client.hpp

SOURCES += \
    main.cpp \
    client.cpp

