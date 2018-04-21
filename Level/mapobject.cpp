#include "mapobject.h"

void MapObject::setPos(int xVal, int yVal){
    pos.x = xVal;
    pos.y = yVal;
}
int MapObject::getPosX(){
    return pos.x;
}
int MapObject::getPosY(){
    return pos.y;
}
void MapObject::takeMovement(int up, int right){
    setPos(getPosX() + up, getPosY());
    setPos(getPosX(), getPosY() + right);
}
