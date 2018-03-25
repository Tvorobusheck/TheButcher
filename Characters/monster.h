#ifndef MONSTER_H
#define MONSTER_H
#include "character.h"

class Monster : public Character
{
public:
    /* Create monster */
    Monster(unsigned int amountOfMaxHealth,
            unsigned int weaponDamage, Weapon::TypeOfWeapon weaponType,
            unsigned int dropExp, unsigned int dropGold);
    Monster(unsigned int amountOfMaxHealth, int amountOfCurHealth,
            unsigned int weaponDamage, Weapon::TypeOfWeapon weaponType,
            unsigned int dropExp, unsigned int dropGold);

    void setGoldDrop(unsigned int amountOfGold);
    void setExpDrop(unsigned int amountOfExp);

    unsigned int getGoldDrop();
    unsigned int getExpDrop();

    void killCharacter();
private:
    /* Expirience drop */
    unsigned int expDrop;
    unsigned int goldDrop;
};

#endif // MONSTER_H
