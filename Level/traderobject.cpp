#include "traderobject.h"

TraderObject::TraderObject(int valX, int valY)
{
    setPos(valX, valY);
    trader = new Trader();
}
Trader* TraderObject::getTrader(){
    return trader;
}
