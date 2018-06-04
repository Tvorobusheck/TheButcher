#ifndef GOOGLETEST_TRADER_H
#define GOOGLETEST_TRADER_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Characters/weapon.h"
#include "../TheButcher/Characters/trader.h"
#include "../TheButcher/Characters/hero.h"

using namespace std;

TEST(TraderCase, TraderGetDamageAndDie){
    Trader *tr = new Trader();
    if(tr -> takeDamage(tr -> getCurHealth() + 1))
        SUCCEED();
    else
        FAIL();
}
TEST(TraderCase, HeroCanBuyWeapon){
    Hero *hr = new Hero(100,30);
    hr -> takeGold(10000);
    Trader *tr = new Trader();
    if(tr -> abilityToPayWeapon(hr))
        SUCCEED();
    else
        FAIL();
}
TEST(TraderCase, HeroCantBuyWeapon){
    Hero *hr = new Hero(100,30);
    hr -> takeExp(10000);
    Trader *tr = new Trader();
    if(tr -> abilityToPayWeapon(hr))
        FAIL();
    else
        SUCCEED();
}
TEST(TraderCase, HeroCanBuyPotion){
    Hero *hr = new Hero(100,30);
    hr -> takeGold(10000);
    Trader *tr = new Trader();
    if(tr -> abilityToPayPotion(hr))
        SUCCEED();
    else
        FAIL();
}
TEST(TraderCase, HeroCantBuyPotion){
    Hero *hr = new Hero(100,30);
    hr -> takeExp(10000);
    Trader *tr = new Trader();
    if(tr -> abilityToPayPotion(hr))
        FAIL();
    else
        SUCCEED();
}
TEST(TraderCase, CheckWeaponDamage){
    Hero *hr = new Hero(100,30);
    hr -> takeExp(10000);
    Trader *tr = new Trader();
    ASSERT_EQ(tr -> getDamgeOfNewWeapon(hr), hr -> getLevel() * 5);
}
TEST(TraderCase, CheckWeapon){
    Hero *hr = new Hero(100,30);
    hr -> takeGold(10000);
    Trader *tr = new Trader();
    if(!tr -> abilityToPayWeapon(hr))
        FAIL();

    tr -> heroBuysWeapon(hr, Weapon::TypeOfWeapon::Mage);
    ASSERT_EQ(tr -> getWeaponType(), Weapon::TypeOfWeapon::Melee);
}
#endif // GOOGLETEST_TRADER_H
