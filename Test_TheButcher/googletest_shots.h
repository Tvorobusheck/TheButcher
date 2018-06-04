#ifndef GOOGLETEST_SHOTS_H
#define GOOGLETEST_SHOTS_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Level/level.h"
#include "../TheButcher/Level/monsterobject.h"
#include "../TheButcher/Characters/weapon.h"
#include "math.h"
using namespace std;

TEST(ShotCase, CheckHeroShotOwner){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    Level::Shot *a = new Level::Shot(lev, Level::Point{51, 51});
    ASSERT_EQ(Level::Shot::Owner::Hero, a -> owner);
}

TEST(ShotCase, CheckMonsterShotOwner){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    MonsterObject *mon = new MonsterObject(51, 51, 100, 100, Weapon::Gun, 25, 25);
    Level::Shot *a = new Level::Shot(lev, mon);
    ASSERT_EQ(Level::Shot::Owner::Monster, a -> owner);
}

TEST(ShotCase, CheckHeroShotPosition){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    Level::Shot *a = new Level::Shot(lev, Level::Point{51, 51});
    if(lev -> getPos(lev -> getMainHeroObject()) == a -> getPos())
        SUCCEED();
    else
        FAIL();
}
TEST(ShotCase, CheckMonsterShotPosition){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    MonsterObject *mon = new MonsterObject(51, 51, 100, 100, Weapon::Gun, 25, 25);
    Level::Shot *a = new Level::Shot(lev, mon);
    if(lev -> getPos(mon) == a -> getPos())
        SUCCEED();
    else
        FAIL();
}
TEST(ShotCase, CheckHeroShotCoefficients){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    Level::Shot *a = new Level::Shot(lev, Level::Point{51, 51});
    if(a -> A == - a -> B && a -> C == 0)
        SUCCEED();
    else
        FAIL();
}
TEST(ShotCase, CheckMonsterShotCoefficients){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    MonsterObject *mon = new MonsterObject(51, 51, 100, 100, Weapon::Gun, 25, 25);
    Level::Shot *a = new Level::Shot(lev, mon);
    if(a -> A == - a -> B && a -> C == 0)
        SUCCEED();
    else
        FAIL();
}
TEST(ShotCase, CheckHeroShotMove){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    Level::Shot *a = new Level::Shot(lev, Level::Point{51, 51});
    a -> takeMove(lev);
    if(a -> x == 50 + 1 / sqrt(2) &&
            a -> y == 50 + 1 / sqrt(2))
        SUCCEED();
    else
        FAIL();
}
TEST(ShotCase, CheckMonsterShotMove){
    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    MonsterObject *mon = new MonsterObject(51, 51, 100, 100, Weapon::Gun, 25, 25);
    Level::Shot *a = new Level::Shot(lev, mon);
    a -> takeMove(lev);
    if(a -> x == 51 - 1 / sqrt(2) &&
            a -> y == 51 - 1 / sqrt(2))
        SUCCEED();
    else
        FAIL();
}
TEST(ShotCase, CheckColisionPositive){

    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    Level::Shot *a = new Level::Shot(lev, Level::Point{51, 51});
    if(a -> checkColision(Level::Point{50, 50}))
        SUCCEED();
    else
        FAIL();
}
TEST(ShotCase, CheckColisionNegative){

    Level *lev = new Level(0, 100, 100, 0,
                           50, 50, 100, 30,
                           0, 0);
    Level::Shot *a = new Level::Shot(lev, Level::Point{51, 51});
    if(a -> checkColision(Level::Point{51, 51}))
        FAIL();
    else
        SUCCEED();
}
#endif // GOOGLETEST_SHOTS_H
