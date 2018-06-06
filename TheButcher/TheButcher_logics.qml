import QtQuick 2.2
import QtQuick.Window 2.0

Window {
    width: 800
    height: 600
    visible: true

    Item {
        anchors.fill: parent

        Menu {
            id: menu
            onGameStarted: parent.state = "gameplay"
            onAuthor: parent.state = "author"
            onSettings: parent.state = "settings"
            onDeadhero: parent.state = "deadhero"
        }

        Author {
            id: author
            onGameStopped: parent.state = "menu"
        }
        GamePlay {
            id: gameplay
            onGameStopped: parent.state = "menu"
              onDeadhero: parent.state = "deadhero"
        }
        Settings {
            id: settings
           onGameStopped: parent.state = "menu"
        }
        DeadHero{
        id: deadhero

        }
     /*  Actor {
        id: h
        onDeadhero: parent.state = "menu"
        }*/
      /* DeadHero {
        id: deadhero
        onGameStopped: parent.state = "menu"
        }*/

        states: [
            State {
                name: "menu"
                PropertyChanges {
                    target: menu
                    visible: true
                }
                PropertyChanges {
                    target: author
                    visible: false
                }

                PropertyChanges {
                    target: gameplay
                    visible: false
                }
                PropertyChanges {
                    target: settings
                    visible: false
                }
                PropertyChanges {
                    target: deadhero
                    visible: false
                }
            },
            State {
                name: "author"
                PropertyChanges {
                    target: menu
                    visible: false
                }
                PropertyChanges {
                    target: author
                    visible: true
                }

                PropertyChanges {
                    target: gameplay
                    visible: false
                }
                PropertyChanges {
                    target: settings
                    visible: false
                }
                PropertyChanges {
                    target: deadhero
                    visible: false
                }

            },
            State {
                name: "gameplay"
                PropertyChanges {
                    target: menu
                    visible: false
                }
                PropertyChanges {
                    target: author
                    visible: false
                }

                PropertyChanges {
                    target: gameplay
                    visible: true
                }
                PropertyChanges {
                    target: settings
                    visible: false
                }
                PropertyChanges {
                    target: deadhero
                    visible: false
                }

            },
            State {
                name: "settings"
                PropertyChanges {
                    target: menu
                    visible: false
                }
                PropertyChanges {
                    target: author
                    visible: false
                }

                PropertyChanges {
                    target: gameplay
                    visible: false
                }
                PropertyChanges {
                    target: settings
                    visible: true
                }
                PropertyChanges {
                    target: deadhero
                    visible: false
                }

            },
            State {
                name: "deadhero"
                PropertyChanges {
                    target: menu
                    visible: false
                }
                PropertyChanges {
                    target: author
                    visible: false
                }

                PropertyChanges {
                    target: gameplay
                    visible: false
                }
                PropertyChanges {
                    target: settings
                    visible: false
                }
                PropertyChanges {
                    target: deadhero
                    visible: true
                }
            }
        ]

        state: "menu"

    }

    //Component.onCompleted: console.log("ksjksdhfkjs")
}


