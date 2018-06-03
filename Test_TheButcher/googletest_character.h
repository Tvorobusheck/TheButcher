#ifndef GOOGLETEST_CHARACTER_H
#define GOOGLETEST_CHARACTER_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Characters/character.h"
using namespace std;



TEST(CharacterCase, CharacterGetDamageAndDie)
{
    Character *chr = new Character();
    if(chr -> takeDamage(123)) FAIL();
}

TEST(CharacterCase, CharacterGetDamageAndAlive)
{
    Character *chr = new Character();
    if(chr -> takeDamage(0)) SUCCEED();
}

TEST(CharacterCase, CharacterGetHeal)
{
    Character *chr = new Character();
    chr -> takeHealth(123);
    ASSERT_EQ(chr -> getCurHealth(), chr -> getMaxHealth());
}
TEST(CharacterCase, CharacterGetKilled)
{
    Character *chr = new Character();
    chr -> killCharacter();
}
#endif // GOOGLETEST_CHARACTER_H
