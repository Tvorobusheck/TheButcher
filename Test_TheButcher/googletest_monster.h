#ifndef GOOGLETEST_MONSTER_H
#define GOOGLETEST_MONSTER_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Characters/monster.h"
#include "../TheButcher/Characters/weapon.h"

TEST(MonsterCase, CheckSetExpDrop){
    Monster *mo = new Monster(100, 25, Weapon::TypeOfWeapon::Melee);
    mo -> setExpDrop(25);
    ASSERT_EQ(25, mo -> getExpDrop());
}
TEST(MonsterCase, CheckSetGoldDrop){
    Monster *mo = new Monster(100, 25, Weapon::TypeOfWeapon::Melee);
    mo -> setGoldDrop(25);
    ASSERT_EQ(25, mo -> getGoldDrop());
}
#endif // GOOGLETEST_MONSTER_H
