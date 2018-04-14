#ifndef LEVEL_H
#define LEVEL_H
#include "heroobject.h"
#include "monsterobject.h"
#include "traderobject.h"
#include "../Characters/monster.h"
#include "../Characters/hero.h"
#include "../Characters/trader.h"
#include <list>
using namespace std;
class Level
{
private:
    struct point
    {
        int x, y;
    } leftUpBorder, rightDownBorder;
    HeroObject* mainHero;
    TraderObject* trader;
    list <MonsterObject*> monsters;
    void setLeftUpBorder(int x, int y);
    void setRightDownBorder(int x, int y);
public:
    enum WeaponTypes{Gun, Mage, Melee};
    Level(int borderXLeftUp, int borderYLeftUp,
          int borderXRightDown, int borderYRightDown,
          int heroX, int heroY,
          unsigned int heroMaxHealth, unsigned int heroMaxLevel,
          int traderX, int traderY);
    void addMonster(int x,  int y,
                    unsigned int amountOfMaxHealth,
                    unsigned int weaponDamage, WeaponTypes typeOfWeapon,
                    unsigned int dropExpAmount, unsigned int dropGoldAmount);
    int getAmountOfMonsters();

};

#endif // LEVEL_H
