QT += core

include(../QHeroQuest.pri)

TARGET = $$qtLibraryTarget($$TARGET)
TEMPLATE = lib

OBJECTS_DIR = $$QHEROQUEST_OBJ
MOC_DIR = $$QHEROQUEST_OBJ

INCLUDEPATH += .

SOURCES += utils/json.cpp 

HEADERS  += \
    utils/json.hpp \
    utils/singleton.hpp \
    utils/factory.hpp \
    utils/defaultfactoryerrorpolicy.hpp \
    utils/traits/parametertrait.hpp \

