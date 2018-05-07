

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../../Level/level.h"
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
}
