#QT += quick
QT  += core gui svg xml qml quick  sql core
CONFIG += c++11
CONFIG += resources_big


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    Characters/weapon.cpp \
    Characters/monster.cpp \
    Characters/hero.cpp \
    Characters/experience.cpp \
    Characters/trader.cpp \
    Level/mapobject.cpp \
    Level/heroobject.cpp \
    Level/traderobject.cpp \
    Level/monsterobject.cpp \
    Level/level.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

SOURCES += \
    Characters/character.cpp

HEADERS += \
    Characters/character.h \
    Characters/weapon.h \
    Characters/monster.h \
    Characters/hero.h \
    Characters/experience.h \
    Characters/trader.h \
    Level/mapobject.h \
    Level/heroobject.h \
    Level/traderobject.h \
    Level/monsterobject.h \
    Level/level.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Sounds/1.mp3 \
    Sounds/2.mp3 \
    Image/123466.jpg \
    Image/aft.jpg \
    Image/fon.jpg \
    Image/fon1.jpg \
    Image/hero.jpg \
    Image/map.jpg \
    Image/fon_for_menu.png \
    Image/hero_spr.png
