import QtQuick 2.0
import Qt.labs.settings 1.0
import QtQuick.Window 2.0
import QtMultimedia 5.5

Rectangle {
     id:gameplay
    width: 800
    height: 600

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

Actor{
    focus:true

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

}
}
