import QtQuick 2.0
import QtQuick.Layouts 1.1
import Qt.labs.settings 1.0

Rectangle {
    width: 800
    height: 600

       signal gameStopped

    property int speed: settings.speed
   // property int x: settings.x
   // property int y: settings.y


    ColumnLayout {
        anchors.centerIn: parent
        anchors.verticalCenterOffset: parent.height / 4
        spacing: 5
        Text{
        text:qsTr("Rounds to win:")
        }

        TextInput {
            id: input
            text: options.speed
            //text: qsTr("Rounds to win:")
            onTextChanged: {
                options.speed = number
            }
        }


    }
    Button {
            anchors.centerIn: parent
            text: "Вернуться в Меню"
           onClicked: parent.gameStopped()
        }


    Settings {
        id: settings
        property int speed: 3
        property int x: 0
        property int y: 0
    }
    Component.onDestruction: {
        settings.speed = speed
        settings.x = 0
        settings.y = 0
    }

    onSpeedChanged: {
        input.number = speed
        settings.x = 0
        settings.y = 0
    }
}
