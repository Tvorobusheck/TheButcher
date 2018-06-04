#ifndef MAPOBJECT_H
#define MAPOBJECT_H
#include <gtest/gtest_prod.h>
class MapObject
{
private:
    struct coordinates
    {
        int x, y;
    }pos;
protected:
    FRIEND_TEST(MapObjectCase, CheckTakeMove);
    void setPos(int xVal, int yVal);
public:
    int getPosX();
    int getPosY();
    void takeMovement(int up, int right);
};

#endif // MAPOBJECT_H
