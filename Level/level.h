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
    /*!
     * \brief Level, which is rectangle which given by two points
     * left-up and right-down
     * \param borderXLeftUp left-up point position
     * \param borderYLeftUp left-up point position
     * \param borderXRightDown right-down point position
     * \param borderYRightDown right-down point position
     * \param heroX hero position
     * \param heroY hero position
     * \param heroMaxHealth
     * \param heroMaxLevel
     * \param traderX trader position
     * \param traderY trader position
     */
    Level(int borderXLeftUp, int borderYLeftUp,
          int borderXRightDown, int borderYRightDown,
          int heroX, int heroY,
          unsigned int heroMaxHealth, unsigned int heroMaxLevel,
          int traderX, int traderY);
    /*!
     * \brief addMonster
     * \param x position
     * \param y position
     * \param amountOfMaxHealth
     * \param weaponDamage
     * \param typeOfWeapon
     * \param dropExpAmount
     * \param dropGoldAmount
     * \return
     */
    MonsterObject* addMonster(int x,  int y,
                    unsigned int amountOfMaxHealth,
                    unsigned int weaponDamage, WeaponTypes typeOfWeapon,
                    unsigned int dropExpAmount, unsigned int dropGoldAmount);

    list <MonsterObject*> getListOfMonsters();
    list <MonsterObject*> getListOfAttackingMonsters();
    list <MonsterObject*> getListOfNonAttackingMonsters();
    /*!
     * \brief get main hero object
     * \return reference of main hero as HeroObject
     */
    HeroObject* getMainHeroObject();
    /*!
     * \brief get position of map object
     * \param character
     * \return coordinates of character
     */
    Point getPos(MapObject* character);
    /*!
     * \brief Move character by vectorCoordinates
     * \param character
     * \param vectorCoordinates
     */
    void takeMove(MapObject* character, Point vectorCoordinates);
    int getAmountOfMonsters();

    /*!
     * \brief check can the hero buy new weapon
     * \return  true if hero can, else return false
     */
    bool heroAbilityToBuyWeapon();
    /*!
     * \brief check can the hero buy 1 potion
     * \return  true if hero can, else return false
     */
    bool heroAbilityToBuyOnePotion();

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
    /*!
     * \brief base damage is not raised by hero skills
     * \return hero base damage
     */
    unsigned int getHeroBaseDamage();
    /*!
     * \brief raised damage is raised by hero skills
     * \return hero full damage
     */
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
    /*!
     * \brief Hero drinks 1 potion, which heals him
     */
    void heroDrinksPotion();
    unsigned int getHeroAmountOfPotions();

    /*!
     * \brief delete monster from monsters list
     * \param monster
     */
    void killMonster(MonsterObject* monster);
    WeaponTypes getCurrentWeaponType();

    /*!
     * \brief find monsters near hero in given radius and
     * make them angry if they are in radius
     */
    void checkArea(unsigned int radius);
    /*!
     * \brief angry monsters atack hero if they are near than dist
     * if they not then they take movement in hero's direction
     * \param dist
     */
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
