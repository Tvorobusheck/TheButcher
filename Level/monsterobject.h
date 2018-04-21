#ifndef MONSTEROBJECT_H
#define MONSTEROBJECT_H
#include "../Characters/monster.h"
#include "mapobject.h"
#include "../Characters/weapon.h"

class MonsterObject: public MapObject
{
private:
    Monster* monster;
public:
    MonsterObject(int valX, int valY,
                  unsigned int amountOfMaxHealth, unsigned int amountOfDamage,
                  Weapon::TypeOfWeapon typeOfWeapon,
                  unsigned int amountOfDropExp = 0, unsigned int amountOfDropGold = 0);
    Monster* getMonsterState();
};

#endif // MONSTEROBJECT_H
