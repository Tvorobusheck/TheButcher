import QtQuick 2.0
import Qt.labs.settings 1.0

Rectangle {
    width: 800
    height: 600

    signal gameStopped

    Button {
        anchors.centerIn: parent
        text: "Тут будут авторы"
        onClicked: parent.gameStopped()
    }
}
