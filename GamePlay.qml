import QtQuick 2.0
import Qt.labs.settings 1.0
import QtQuick.Window 2.0
import QtMultimedia 5.5

Rectangle {
     id:gameplay
    width: 800
    height: 600
    focus:true
    signal gameStopped

     property int speed: settings.speed
     property int hero_x: 400
     property int hero_y: 300
     property int fon_x: 0
     property int fon_y:0
     property int xVelocity: 0
     property int yVelocity: 0
     property int mod_speed: 4
     property int fon_height: 1890
     property int fon_wedth:3070


    Image {
        id: back
        source: "map.jpg"
        width: 3070
        height: 1890

        anchors.left:parent.left
        anchors.top: parent.top
        anchors.leftMargin: fon_x
        anchors.topMargin:fon_y

    }
  Image{

    id:hero
    source: "hero.jpg"
    width: 40
    height: 40


    anchors.left:parent.left
    anchors.top: parent.top
    anchors.leftMargin: hero_x
    anchors.topMargin:hero_y


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
            yVelocity=-1

        break;

    case Qt.Key_S:

         yVelocity=1
        break;

    case Qt.Key_A:
         xVelocity=-1

        break;

    case Qt.Key_D:
       xVelocity=1

        break;
    }
    }


    Keys.onReleased: {
        if (event.isAutoRepeat) {
            return;
        }

    switch (event.key) {

    case Qt.Key_W:
            yVelocity=0

        break;

    case Qt.Key_S:

         yVelocity=0
        break;

    case Qt.Key_A:
      xVelocity=0
        break;

    case Qt.Key_D:
     xVelocity=0
        break;
    }
    }


   Timer {
        interval: 5
        triggeredOnStart: true
        running: true
        repeat: true
        onTriggered: {
        if (yVelocity==1){
            if (hero_y<500)
                hero_y+= yVelocity*mod_speed
            else
            {
                if (fon_y- (yVelocity*mod_speed)>(-fon_height+600))
                fon_y-= yVelocity*mod_speed
            }
        }
            else{
                if (hero_y>100)
                          hero_y+= yVelocity*mod_speed
                    else{
                            if (fon_y- (yVelocity*mod_speed)<0)
                          fon_y-= yVelocity*mod_speed
                       }
            }

         if (xVelocity==1){
            if (hero_x<600)
               hero_x+= xVelocity*mod_speed
            else
                if (fon_x- (xVelocity*mod_speed)>(-fon_wedth+800))
                fon_x-= xVelocity*mod_speed

            }
            else{
                if (hero_x>200)
                        hero_x+= xVelocity*mod_speed
                    else{
                     if (fon_x- (xVelocity*mod_speed)<0)
                        fon_x-= xVelocity*mod_speed
                       }
         }
            back.update()
        }






}
}
