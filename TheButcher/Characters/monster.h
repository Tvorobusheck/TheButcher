#ifndef MONSTER_H
#define MONSTER_H
#include "character.h"
#include <gtest/gtest_prod.h>

class Monster : public Character
{
public:
    /* Create monster */
    Monster(unsigned int amountOfMaxHealth,
            unsigned int weaponDamage, Weapon::TypeOfWeapon weaponType,
            unsigned int dropExp = 0, unsigned int dropGold = 0);

    unsigned int getGoldDrop();
    unsigned int getExpDrop();

private:
    /* Expirience drop */
    unsigned int expDrop;
    unsigned int goldDrop;
    FRIEND_TEST(MonsterCase, CheckSetExpDrop);
    FRIEND_TEST(MonsterCase, CheckSetGoldDrop);
    void setGoldDrop(unsigned int amountOfGold);
    void setExpDrop(unsigned int amountOfExp);

};

#endif // MONSTER_H
