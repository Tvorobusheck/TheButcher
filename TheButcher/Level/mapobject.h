#ifndef MAPOBJECT_H
#define MAPOBJECT_H

class MapObject
{
private:
    struct coordinates
    {
        int x, y;
    }pos;
protected:
    void setPos(int xVal, int yVal);
public:
    int getPosX();
    int getPosY();
    void takeMovement(int up, int right);
};

#endif // MAPOBJECT_H
