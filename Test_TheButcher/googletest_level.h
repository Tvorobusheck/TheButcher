#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Level/level.h"
using namespace std;



TEST(TheButcherCaseLevel, TheButcherSet_VerificationOfCreationLevel)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
    if (a == NULL)
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHero, TheButcherSet_CheckHeroLevelStart)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroLevel();
  // cout << hl << endl;
    if (hl != 0) // the first level of the hero is zero
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHero, TheButcherSet_CheckHeroExpStart)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroExp();
   // cout << hl << endl;
    if (hl != 0) // the first Exp of the hero is zero
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHero, TheButcherSet_CheckBaseDamage)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroBaseDamage();
    cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}




TEST(TheButcherCaseHeroGun, TheButcherSet_CheckHeroGunLevel)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroGunLevel();
   // cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHeroGun, TheButcherSet_CheckGunExp)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroGunExp();
   // cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHeroMage, TheButcherSet_CheckMageLevel)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroMageLevel();
   // cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHeroMage, TheButcherSet_CheckMageExp)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroMageExp();
   // cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}



TEST(TheButcherCaseHeroMelee, TheButcherSet_CheckMeleeLevel)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroMeleeLevel();
   // cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHeroMelee, TheButcherSet_CheckMeleeExp)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroMeleeExp();
   // cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}

TEST(TheButcherCaseHeroRaised, TheButcherSet_CheckRaisedDamage)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   int hl =a->getHeroRaisedDamage();
   // cout << hl << endl;
    if (hl != 0)
         FAIL();
    else
         SUCCEED();
}


TEST(TheButcherCasePotion, TheButcherSet_CheckBuyAndUse)
{
    Level *a = new Level{1,1,1,1,1,1,1,1,1,1};
   if(a->getHeroAmountOfPotions()!=0)
         FAIL();
    else
         SUCCEED();
   a->heroBuysPotion();

   if(a->getHeroAmountOfPotions()!=1)
         FAIL();
    else
         SUCCEED();
   a->heroDrinksPotion();


   if(a->getHeroAmountOfPotions()!=0)
         FAIL();
    else
         SUCCEED();
   if(a->heroAbilityToBuyWeapon()!=1)
       FAIL();
  else
       SUCCEED();;
}

TEST(Hero, Health)
{

    Level *a = new Level{1,1,1,1,1,1,100,1,1,1};

 ASSERT_EQ(a->getHeroHealth(), 100);
  ASSERT_EQ(a->getHeroMaxHealth(), 100);
}

TEST(Hero, TakeMove)
{
    Level *a = new Level(0, 100, 100, 0, 50, 50, 100, 30, 10, 10);
    a -> takeMove(a -> getMainHeroObject(),Level::Point{1,1});
    if(a -> getPos(a -> getMainHeroObject()) == Level::Point{51, 51})
        SUCCEED();
    else
        FAIL();
}
TEST(Signum, SignumTest){
    Level *a = new Level(0, 100, 100, 0, 50, 50, 100, 30, 10, 10);
    ASSERT_EQ(a -> signum(228), 1);
    ASSERT_EQ(a -> signum(-228), -1);
    ASSERT_EQ(a -> signum(0), 0);
}

TEST(Monsters, SetMonsterAngry){
    Level *a = new Level(0, 100, 100, 0, 50, 50, 100, 30, 10, 10);
    a -> addMonster(51, 51, 100, 10, Level::Mage, 25, 25);
    a -> addMonster(51, 50, 100, 10, Level::Melee, 25, 25);
    a -> addMonster(53, 50, 100, 10, Level::Gun, 25, 25);
    a -> checkArea(1);
    ASSERT_EQ(a -> getListOfAttackingMonsters().size(), 1);
    a -> checkArea(2);
    ASSERT_EQ(a -> getListOfAttackingMonsters().size(), 2);
    a -> checkArea(3);
    ASSERT_EQ(a -> getListOfAttackingMonsters().size(), 3);

}

TEST(Monsters, MonstersAttackHero){
    Level *a = new Level(0, 100, 100, 0, 50, 50, 50, 30, 10, 10);
    a -> addMonster(51, 51, 100, 10, Level::Mage, 25, 25);
    a -> addMonster(51, 50, 100, 10, Level::Melee, 25, 25);
    a -> addMonster(53, 50, 100, 10, Level::Gun, 25, 25);
    a -> checkArea(1);
    ASSERT_EQ(a -> getListOfAttackingMonsters().size(), 1);
    a -> checkArea(2);
    ASSERT_EQ(a -> getListOfAttackingMonsters().size(), 2);
    a -> checkArea(3);
    ASSERT_EQ(a -> getListOfAttackingMonsters().size(), 3);
    a -> combatMonstersAtackHero();
    for(auto it: a -> getListOfAttackingMonsters())
        a -> monsterAttaksHero(it);
    ASSERT_EQ(a -> getHeroHealth(), 20);
}

TEST(Monsters, CombatMonstersAttackHeroMelee){
    Level *a = new Level(0, 100, 100, 0, 50, 50, 50, 30, 10, 10);
    a -> addMonster(51, 51, 100, 10, Level::Melee, 25, 25);
    a -> checkArea(3);
    a -> combatMonstersAtackHero();
    ASSERT_EQ(a -> getHeroHealth(), a -> getHeroMaxHealth() - 10);
}

TEST(Monsters, CombatMonstersAttackHeroMage){
    Level *a = new Level(0, 100, 100, 0, 50, 50, 50, 30, 10, 10);
    a -> addMonster(51, 51, 100, 10, Level::Mage, 25, 25);
    a -> checkArea(3);
    a -> combatMonstersAtackHero();
    ASSERT_EQ(a -> getListOfShots().size(), 1);
}
TEST(Monsters, CombatMonstersAttackHeroGun){
    Level *a = new Level(0, 100, 100, 0, 50, 50, 50, 30, 10, 10);
    a -> addMonster(51, 51, 100, 10, Level::Gun, 25, 25);
    a -> checkArea(3);
    a -> combatMonstersAtackHero();
    ASSERT_EQ(a -> getListOfShots().size(), 1);
}
