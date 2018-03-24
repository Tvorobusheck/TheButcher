import QtQuick 2.0
//import QmlProject 1.1
Rectangle {
    width: 200
    height: 40
    color: "grey"

    radius: 10

    property alias text: text.text
    signal clicked

    Text {
        id: text
        text: "Button"
        anchors.centerIn: parent
        font.pointSize: 20
        color: "white"
    }

    MouseArea {
        anchors.fill: parent
        onPressed: parent.color = "grey"
        onReleased: parent.color = "red"
        onClicked: parent.clicked()
    }
}

