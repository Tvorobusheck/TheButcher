include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -std=c++11

CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_thebutchercase.h \
    ../TheButcher/Characters/character.h \
    ../TheButcher/Characters/experience.h \
    ../TheButcher/Characters/hero.h \
    ../TheButcher/Characters/monster.h \
    ../TheButcher/Characters/trader.h \
    ../TheButcher/Characters/weapon.h \
    ../TheButcher/Level/heroobject.h \
    ../TheButcher/Level/level.h \
    ../TheButcher/Level/mapobject.h \
    ../TheButcher/Level/monsterobject.h \
    ../TheButcher/Level/traderobject.h \
    googletest_level.h \
    googletest_experience.h

SOURCES +=     main.cpp \
    ../TheButcher/Characters/character.cpp \
    ../TheButcher/Characters/experience.cpp \
    ../TheButcher/Characters/hero.cpp \
    ../TheButcher/Characters/monster.cpp \
    ../TheButcher/Characters/trader.cpp \
    ../TheButcher/Characters/weapon.cpp \
    ../TheButcher/Level/heroobject.cpp \
    ../TheButcher/Level/level.cpp \
    ../TheButcher/Level/mapobject.cpp \
    ../TheButcher/Level/monsterobject.cpp \
    ../TheButcher/Level/traderobject.cpp
