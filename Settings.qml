import QtQuick 2.0
import QtQuick.Layouts 1.1
import Qt.labs.settings 1.0

Rectangle {
    width: 800
    height: 600
    id: win_set

       signal gameStopped


    property int hero_x: settings.hero_x
    property int hero_y: settings.hero_y
    property int mod_speed:4


    Settings {
        id: settings
        property int mod_speed: 4
        property int hero_x: 400
        property int hero_y: 300
    }
    Component.onDestruction: {
        settings.mod_speed = 4
        settings.hero_x = 400
        settings.hero_y = 300
    }


    ColumnLayout {
        anchors.centerIn: parent
        anchors.verticalCenterOffset: parent.height / 4
        spacing: 5
        Text{
        text:qsTr("Текущии настройки")
        }

        Text{
        text:qsTr("Модификатор скорости:" + mod_speed)
        }
        Button {


                text: "Вернуться в Меню"
               onClicked: win_set.gameStopped()
            }



    }



}



