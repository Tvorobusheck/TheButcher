import QtQuick 2.0
import Qt.labs.settings 1.0
import QtQuick.Layouts 1.0


Rectangle {
    width: 800
    height: 600
    id:aftor

    signal gameStopped

    Image{
        id:fon
        source:"Image/aft.jpg"
        anchors.centerIn: parent
        width:800
        height:600
    }
    ColumnLayout
    {

        spacing:15
        anchors.left:parent.left
        anchors.top: parent.top
        anchors.leftMargin: parent.width/10
        anchors.topMargin: parent.height/5
        Text{
            text:"Авторы:"
            width: 100
            height:40
            font.family: "Castellar"
            font.pointSize:15
            color:"#b9f0d3"
        }
        Text{
            text:"А. Харковчук"
            width: 100
            height:40
            font.family: "Castellar"
            font.pointSize:15
            color:"#b9f0d3"
        }
        Text{
            text:"К. Владислав"
            width: 100
            height:40
            font.family: "Castellar"
            font.pointSize:15
            color:"#b9f0d3"
        }
        Button {


                text: "Вернуться в Меню"
               onClicked: aftor.gameStopped()
            }


    }

   /* Button {
        anchors.left:parent.left
        anchors.top: parent.top
        anchors.leftMargin: parent.width/2
        anchors.topMargin: parent.height/2


        text: "Вернуться в меню"
        onClicked: parent.gameStopped()
    }*/
    Keys.onPressed: {
        if (event.isAutoRepeat) {
            return;
        }
    switch (event.key) {
    case Qt.Key_Escape:
     gameplay.gameStopped()
    }
    }



}
