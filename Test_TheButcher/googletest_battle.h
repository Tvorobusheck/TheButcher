#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Level/level.h"
using namespace std;
#ifndef GOOGLETEST_BATTLE_H
#define GOOGLETEST_BATTLE_H

TEST(Monster, monsterCreating)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
    a->addMonster(10,10,40,5,Level::WeaponTypes::Gun,12,12);
    list <MonsterObject*> monst = a->getListOfMonsters();
   // list<MonsterObject*>::iterator it =monst.begin();
    for (auto i : monst){
        ASSERT_EQ(i->getPosX(), 10);
        ASSERT_EQ(i->getPosY(), 10);
        ASSERT_EQ(i->isAttacks(), false);

    }
}

#endif // GOOGLETEST_BATTLE_H
