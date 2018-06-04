#ifndef GOOGLETEST_MAPOBJECT_H
#define GOOGLETEST_MAPOBJECT_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <iostream>
#include "../TheButcher/Level/mapobject.h"

TEST(MapObjectCase, CheckTakeMove){
    MapObject *mo = new MapObject();
    mo -> setPos(2, 2);
    mo -> takeMovement(1, 1);
    ASSERT_EQ(mo -> getPosX(), 3);
    ASSERT_EQ(mo -> getPosY(), 3);
}
#endif // GOOGLETEST_MAPOBJECT_H
