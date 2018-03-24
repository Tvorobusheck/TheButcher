import QtQuick 2.0
import Qt.labs.settings 1.0

Rectangle {
    width: 800
    height: 600

    signal gameStopped

     property int speed: settings.speed
    // property int speed: settings.x
    // property int speed: settings.y

    Image {
        id: back
        source: "fon1.jpg"
        width: 1300
        height: 760
    }

    Button {
        anchors.centerIn: parent
        text: "Играть чтобы жить"
        onClicked: parent.gameStopped()
    }
}
