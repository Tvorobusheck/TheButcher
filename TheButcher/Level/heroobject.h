#ifndef HEROOBJECT_H
#define HEROOBJECT_H
#include "../Characters/hero.h"
#include "mapobject.h"

class HeroObject:public MapObject
{
private:
    Hero* heroState;
public:
    HeroObject(int valX, int valY,
               unsigned int amountOfMaxHealth, unsigned int borderOfMaxLevel);
    Hero* getHeroState();
};

#endif // HEROOBJECT_H
