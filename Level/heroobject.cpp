#include "heroobject.h"

HeroObject::HeroObject(int valX, int valY,
                       unsigned int amountOfMaxHealth, unsigned int borderOfMaxLevel)
{
    setPos(valX, valY);
    heroState = new Hero(amountOfMaxHealth, borderOfMaxLevel);
}
Hero* HeroObject::getHeroState(){
    return heroState;
}
