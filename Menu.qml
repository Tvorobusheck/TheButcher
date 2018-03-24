import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    id: menu
    width: 800
    height: 600
    signal author
    signal gameStarted
    signal settings


    Image {
        id: back
        source: "fon1.jpg"
        width: 800
        height: 600
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 5
        Button {
            text: "Начать игру"
            onClicked: menu.gameStarted()
        }
        Button {
            text: "Настройки"
            onClicked: menu.settings()
        }
        Button {
            text: "Авторы"
            onClicked: menu.author()
        }
        Button {
            text: "Выход"
            onClicked: {
                Qt.quit()
            }
        }
    }
}
