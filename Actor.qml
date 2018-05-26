import QtQuick 2.0
import CustomComponents 1.0

Item {
id:hero_game
property int xVelocity: 0
property int yVelocity: 0

Image {
     id: back
     source: "Image/map.jpg"
     width: 3070
     height: 1890

     anchors.left:parent.left
     anchors.top: parent.top
     anchors.leftMargin: fon_x
     anchors.topMargin:fon_y

 }
Image{

id:hero
source: "Image/hero.jpg"
width: 40
height: 40
 focus:true

anchors.left:parent.left
anchors.top: parent.top
anchors.leftMargin: hero_x
anchors.topMargin:hero_y


}
Level{
id: level_first
}



Rectangle {
    id:helf1
    y: 35
    x: 0
    width: level_first.getHeroMaxHealth()+10
    height: 30
    color: "white"
    border.color: "black"
    border.width: 5
    radius: 5
}
Rectangle {
    id:helf
    color: "red"
    y: 40
    x: 5
    width:  level_first.getHeroHealth()
    height: 20
}



    Timer {
        interval: 5
        triggeredOnStart: true
        running: true
        repeat: true
        onTriggered: {
           //  level_first.takeHeroGold(10)
          // console.log ( level_first.getHeroGold())
         //   console.log ( level_first.getHeroHealth())
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

