#include "tst_thebutchercase.h"
#include "googletest_level.h"
#include "googletest_experience.h"
#include "googletest_battle.h"
#include "googletest_weapon.h"
#include "googletest_character.h"
#include "googletest_trader.h"
#include "googletest_hero.h"
#include "googletest_mapobject.h"
#include "googletest_monster.h"
#include "googletest_shots.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
