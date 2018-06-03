#ifndef GOOGLETEST_WEAPON_H
#define GOOGLETEST_WEAPON_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Characters/weapon.h"
using namespace std;



TEST(WeaponCase, WeaponConstructor)
{
    Weapon *wp = new Weapon(1, Weapon::TypeOfWeapon::Melee);

    if(wp == NULL)
        FAIL();
    else
        SUCCEED();
}


TEST(WeaponCase, WeaponDamageGetSet)
{
    Weapon *wp = new Weapon(0, Weapon::TypeOfWeapon::Melee);
    const unsigned int someDamage = 999;
    wp -> setDamage(someDamage);
    ASSERT_EQ(someDamage, wp -> getDamage());
}
TEST(WeaponCase, WeaponTypeGetSet)
{
    Weapon *wp = new Weapon(0, Weapon::TypeOfWeapon::Melee);
    const Weapon::TypeOfWeapon someType = Weapon::TypeOfWeapon::Gun;
    wp -> setType(someType);
    ASSERT_EQ(someType, wp -> getWeaponType());
}
#endif // GOOGLETEST_WEAPON_H
