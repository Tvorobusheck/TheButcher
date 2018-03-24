import QtQuick 2.0
import QtQuick.Layouts 1.1
import Qt.labs.settings 1.0

Rectangle {
    width: 800
    height: 600

       signal gameStopped

    property int speed: settings.speed


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
            text: "скоро подвезут настройки "
           onClicked: parent.gameStopped()
        }


    Settings {
        id: settings
        property int speed: 3
    }
    Component.onDestruction: {
        settings.speed = speed
    }

    onSpeedChanged: {
        input.number = speed
    }
}
