#ifndef MONSTER_H
#define MONSTER_H
#include "character.h"

class Monster : public Character
{
public:
    /* Create monster */
    Monster(unsigned int amountOfMaxHealth,
            unsigned int weaponDamage, Weapon::TypeOfWeapon weaponType,
            unsigned int dropExp = 0, unsigned int dropGold = 0);

    unsigned int getGoldDrop();
    unsigned int getExpDrop();

    void killCharacter();
private:
    /* Expirience drop */
    unsigned int expDrop;
    unsigned int goldDrop;

    void setGoldDrop(unsigned int amountOfGold);
    void setExpDrop(unsigned int amountOfExp);

};

#endif // MONSTER_H
