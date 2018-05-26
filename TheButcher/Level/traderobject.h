#ifndef TRADEROBJECT_H
#define TRADEROBJECT_H
#include "../Characters/trader.h"
#include "mapobject.h"

class TraderObject: public MapObject
{
private:
    Trader* trader;
public:
    TraderObject(int valX, int valY);
    Trader* getTrader();
};

#endif // TRADEROBJECT_H
