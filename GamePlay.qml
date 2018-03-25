import QtQuick 2.0
import Qt.labs.settings 1.0
import QtQuick.Window 2.0

Rectangle {
     id:gameplay
    width: 800
    height: 600
focus:true
    signal gameStopped

     property int speed: settings.speed
     property int xxx: 0
    property int yyy: 0

//var x=0
//var y=0
    Image {
        id: back
        source: "fon1.jpg"
        width: 1300
        height: 760

        anchors.left:parent.left
        anchors.top: parent.top
        anchors.leftMargin: yyy
        anchors.topMargin: xxx

    }
    Keys.onPressed: {
        if (event.isAutoRepeat) {
            return;
        }
    switch (event.key) {
    case Qt.Key_Escape:
     gameplay.gameStopped()
        break;
    case Qt.Key_W:
       xxx=xxx+10
        back.update()


        break;



    }
    }


  /*  Button {
        anchors.centerIn: parent
        text: "Играть чтобы жить"
        onClicked: gameplay.gameStopped()
    }*/


}
