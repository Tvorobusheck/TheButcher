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
TEST(Monster, monsterAtack)
{
    Level *a = new Level{1,1,1,1,1,1,100,1,1,1};
    a->addMonster(1,1,40,5,Level::WeaponTypes::Gun,12,12);
     a->addMonster(1,1,40,5,Level::WeaponTypes::Gun,12,12);
    list <MonsterObject*> monst = a->getListOfMonsters();
   // list<MonsterObject*>::iterator it =monst.begin();
    for (auto i : monst){
        i->setCombatState(true);
        ASSERT_EQ(i->getPosX(), 1);
        ASSERT_EQ(i->getPosY(), 1);
        ASSERT_EQ(i->isAttacks(), true);
        a->monsterAttaksHero(i);
        a->combatMonstersAtackHero();
    }
     a->heroAtacksMonster(Level::Point{1,1});
         list <MonsterObject*> monsterattack = a->getListOfAttackingMonsters();
          ASSERT_EQ(monsterattack.size(), 2);
      list <MonsterObject*> nonmonsterattack =a->getListOfNonAttackingMonsters();
       ASSERT_EQ(nonmonsterattack.size(), 2);
              //  cout << a->getHeroHealth() << endl;
}

#endif // GOOGLETEST_BATTLE_H
