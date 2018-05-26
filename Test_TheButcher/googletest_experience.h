#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Level/level.h"
using namespace std;
#ifndef GOOGLETEST_EXPERIENCE_H
#define GOOGLETEST_EXPERIENCE_H

TEST(Experience, ExperienceCreating)
{
    Experience *exp = new Experience(30, 100, 1.25);
    if(exp == NULL)
        FAIL();
    SUCCEED();
}

TEST(Experience, ExperienceExisting)
{
    Experience *exp = new Experience(30, 100, 1.25);
    ASSERT_EQ(exp -> getCurrentLevel(), 0);
    ASSERT_EQ(exp -> getMaxLevel(), 30);
    ASSERT_EQ(exp -> getThresholdCoefficient(), 1.25);
    ASSERT_EQ(exp -> getThreshold(), 100);
    SUCCEED();
}
TEST(Experience, ExperienceRaising)
{
    Experience *exp = new Experience(30, 100, 1.25, 0);
    exp -> incLevel();
    ASSERT_EQ(exp -> getCurrentLevel(), 1);
    SUCCEED();
}
TEST(Experience, ExperienceLevelOverflow)
{
    Experience *exp = new Experience(30, 100, 1.25, 0);
    for(unsigned int i = 0; i < exp -> getMaxLevel() + 1; i++)
        exp -> incLevel();
    ASSERT_EQ(exp -> getCurrentLevel(), exp -> getMaxLevel());
    SUCCEED();
}

#endif // GOOGLETEST_EXPERIENCE_H
