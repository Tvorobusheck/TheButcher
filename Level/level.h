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
public:
    struct Point
    {
        int x, y;
    };
    enum WeaponTypes{Gun, Mage, Melee};
    Level(int borderXLeftUp, int borderYLeftUp,
          int borderXRightDown, int borderYRightDown,
          int heroX, int heroY,
          unsigned int heroMaxHealth, unsigned int heroMaxLevel,
          int traderX, int traderY);
    MonsterObject* addMonster(int x,  int y,
                    unsigned int amountOfMaxHealth,
                    unsigned int weaponDamage, WeaponTypes typeOfWeapon,
                    unsigned int dropExpAmount, unsigned int dropGoldAmount);

    list <MonsterObject*> getListOfMonsters();
    list <MonsterObject*> getListOfAttackingMonsters();
    list <MonsterObject*> getListOfNonAttackingMonsters();
    HeroObject* getMainHeroObject();
    Point getPos(MapObject* character);
    void takeMove(MapObject* character, Point vectorCoordinates);
    int getAmountOfMonsters();

    bool heroPayAbilityToBuyWeapon();
    bool heroPayAbilityToBuyOnePotion();

    void heroBuysPotion();
    void heroBuysNewWeapon(WeaponTypes weaponType);

    unsigned int getHeroLevel();
    unsigned int getHeroExp();

    unsigned int getHeroGunLevel();
    unsigned int getHeroGunExp();

    unsigned int getHeroMageLevel();
    unsigned int getHeroMageExp();

    unsigned int getHeroMeleeLevel();
    unsigned int getHeroMeleeExp();

    unsigned int getHeroBaseDamage();
    unsigned int getHeroRaisedDamage();

    /*!
     * \brief Hero attacks monster and he improves his combat skill
     * \param monster
     * \return if hero killed monster return false,
     * else return true if monster if alive
     */
    bool heroAtacksMonster(MonsterObject* monster);
    /*!
     * \brief Monster take damage to hero
     * \param monster
     * \return true if hero is alive, else return false
     */
    bool monsterAttaksHero(MonsterObject* monster);

    void heroDrinksPotion();
    unsigned int getHeroAmountOfPotions();

    void killMonster(MonsterObject* monster);
    WeaponTypes getCurrentWeaponType();

    /*!
     * \brief Find monsters near hero in given radius
     */
    void checkArea(unsigned int radius);

    void combatMonstersAtackHero(unsigned int dist);
private:
    int signum(int val);
    void heroGetsMonsterDrop(MonsterObject* monster);
    Point leftUpBorder, rightDownBorder;
    HeroObject* mainHero;
    TraderObject* trader;
    list <MonsterObject*> monsters;
    void setLeftUpBorder(int x, int y);
    void setRightDownBorder(int x, int y);

};

#endif // LEVEL_H
