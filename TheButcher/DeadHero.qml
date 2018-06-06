import QtQuick 2.0
import QtQuick 2.0
import Qt.labs.settings 1.0
import QtQuick.Layouts 1.0
Rectangle {
    id: deadhero
    width: 800
    height: 600
    signal gameStopped


    Image {
        id: dea
        source: "Image/dead.png"
        width: 800
        height: 600
    }
    Button {
        x: 290
        y:550

            text: "Выйти из игры"
           onClicked:  Qt.quit()
        }

}
