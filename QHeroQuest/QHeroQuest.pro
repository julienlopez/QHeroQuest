QT += core

include(../QHeroQuest.pri)

TARGET = $$qtLibraryTarget($$TARGET)
TEMPLATE = lib

OBJECTS_DIR = $$QHEROQUEST_OBJ/lib
MOC_DIR = $$QHEROQUEST_OBJ/lib

INCLUDEPATH += .

SOURCES += utils/json.cpp \ 
    message/message.cpp \
    commande/statusupdate.cpp \
    commande/status.cpp \
    commande/shutdown.cpp \
    commande/commande.cpp \
    utils/exception.cpp

HEADERS  += \
    utils/json.hpp \
    utils/singleton.hpp \
    utils/factory.hpp \
    utils/defaultfactoryerrorpolicy.hpp \
    utils/traits/parametertrait.hpp \
    message/message.hpp \
    commande/statusupdate.hpp \
    commande/status.hpp \
    commande/shutdown.hpp \
    commande/commande.hpp \
    graph/graph.hpp \
    utils/plainstorage.hpp \
    utils/exception.hpp \
    utils/traits/various.hpp
