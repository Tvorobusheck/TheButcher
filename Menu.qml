import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtMultimedia 5.5

Rectangle {
    id: menu
    width: 800
    height: 600
    signal author
    signal gameStarted
    signal settings


    Image {
        id: back
        source: "Image/fon_for_menu.png"
        width: 800
        height: 600
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 5
        Button {
            text: "Начать игру"
            onClicked:{
                menu_audio.stop()
                  game_audio.play()
                menu.gameStarted()
        }
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

    Audio {
        id:menu_audio
        source: "Sounds/1.mp3"
        volume:1
        loops: SoundEffect.Infinite
         autoPlay: true
    }
    Audio {
        id:game_audio
        source: "Sounds/2.mp3"
        volume:1
        loops: SoundEffect.Infinite
    }




}
