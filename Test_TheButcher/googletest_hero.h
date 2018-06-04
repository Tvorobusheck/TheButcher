#ifndef GOOGLETEST_HERO_H
#define GOOGLETEST_HERO_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Characters/weapon.h"
#include "../TheButcher/Characters/hero.h"

using namespace std;

TEST(HeroCase, HeroGetExp){
    Hero *hr = new Hero(100, 100);
    hr -> takeExp(1);
    ASSERT_EQ(1, hr -> getExp());
}

TEST(HeroCase, GunSetTest){
    Hero *hr = new Hero(100, 100);
    hr -> setWeapon(new Weapon(100, Weapon::TypeOfWeapon::Gun));
    ASSERT_EQ(Weapon::TypeOfWeapon::Gun, hr -> getWeaponType());
}

TEST(HeroCase, MageSetTest){
    Hero *hr = new Hero(100, 100);
    hr -> setWeapon(new Weapon(100, Weapon::TypeOfWeapon::Mage));
    ASSERT_EQ(Weapon::TypeOfWeapon::Mage, hr -> getWeaponType());
}
TEST(HeroCase, MeleeSetTest){
    Hero *hr = new Hero(100, 100);
    hr -> setWeapon(new Weapon(100, Weapon::TypeOfWeapon::Melee));
    ASSERT_EQ(Weapon::TypeOfWeapon::Melee, hr -> getWeaponType());
}

TEST(HeroCase, GunDamageTest){
    Hero *hr = new Hero(100, 100);
    hr -> setWeapon(new Weapon(100, Weapon::TypeOfWeapon::Gun));
    hr -> takeGunSkillExp(100 * 100);
    ASSERT_EQ(hr -> getGunSkillLevel(), 100);
    ASSERT_EQ(hr -> getDamage() * 2, hr -> getHeroicDamage());
}

TEST(HeroCase, MageDamageTest){
    Hero *hr = new Hero(100, 100);
    hr -> setWeapon(new Weapon(100, Weapon::TypeOfWeapon::Mage));
    hr -> takeMageSkillExp(100 * 100);
    ASSERT_EQ(hr -> getMageSkillLevel(), 100);
    ASSERT_EQ(hr -> getDamage() * 2, hr -> getHeroicDamage());
}
TEST(HeroCase, MeleeDamageTest){
    Hero *hr = new Hero(100, 100);
    hr -> setWeapon(new Weapon(100, Weapon::TypeOfWeapon::Melee));
    hr -> takeMeleeSkillExp(100 * 100);
    ASSERT_EQ(hr -> getMeleeSkillLevel(), 100);
    ASSERT_EQ(hr -> getDamage() * 2, hr -> getHeroicDamage());
}
#endif // GOOGLETEST_HERO_H
