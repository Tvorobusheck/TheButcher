import QtQuick 2.0

Item {
id:hero_game
property int xVelocity: 0
property int yVelocity: 0
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
