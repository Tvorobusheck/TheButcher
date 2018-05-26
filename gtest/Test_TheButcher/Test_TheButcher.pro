include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_thebutchercase.h \
    ../../Characters/character.h \
    ../../Characters/experience.h \
    ../../Characters/hero.h \
    ../../Characters/monster.h \
    ../../Characters/trader.h \
    ../../Characters/weapon.h \
    ../../Level/heroobject.h \
    ../../Level/level.h \
    ../../Level/mapobject.h \
    ../../Level/monsterobject.h \
    ../../Level/traderobject.h \
    googletest_level.h \
    googletest_experience.h

SOURCES +=     main.cpp \
    ../../Characters/character.cpp \
    ../../Characters/experience.cpp \
    ../../Characters/hero.cpp \
    ../../Characters/monster.cpp \
    ../../Characters/trader.cpp \
    ../../Characters/weapon.cpp \
    ../../Level/heroobject.cpp \
    ../../Level/level.cpp \
    ../../Level/mapobject.cpp \
    ../../Level/monsterobject.cpp \
    ../../Level/traderobject.cpp
