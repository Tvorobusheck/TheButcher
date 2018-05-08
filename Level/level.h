#ifndef LEVEL_H
#define LEVEL_H
#include "heroobject.h"
#include "monsterobject.h"
#include "traderobject.h"
#include "../Characters/monster.h"
#include "../Characters/hero.h"
#include "../Characters/trader.h"
#include <list>
#include <math.h>
#define EPSILON 0.05
#define MELEE_RADIUS 2
#define DISTANCE_WEAPON_RADIUS 10
#define SIGHT_RADIUS 20

using namespace std;
class Level
{
public:
    enum WeaponTypes{Gun, Mage, Melee};
    struct Point
    {
        int x, y;
        Point operator -(const Point &second){
            return Point{this -> x - second.x, this -> y - second.y};
        }
        Point operator +(const Point &second){
            return Point{this -> x + second.x, this -> y + second.y};
        }
        bool operator <=(const Point &sec){
            return  this -> x * this -> x + this -> y * this -> y <= sec.x * sec.x + sec.y * sec.y;
        }
        bool operator ==(const Point &sec){
            return  this -> x == sec.x && this -> y == sec.y;
        }
    };

    struct Shot
    {
    public:
        enum Owner{Hero, Monster};
        /*!
         * \brief hero's shot
         * \param hero
         * \param monster
         */
        Shot(Level *level, Point vectorCoordinates) {
            lev = level;
            HeroObject* hero = lev -> getMainHeroObject();
            damage = hero -> getHeroState() -> getHeroicDamage();
            owner = Owner::Hero;
            switch (hero -> getHeroState() -> getWeaponType()) {
            case Weapon::Gun:
                shotType = WeaponTypes::Gun;
                break;
            case Weapon::Mage:
                shotType = Mage;
                break;
            default:
                shotType = Melee;
                break;
            }
            Point position = lev -> getPos(hero);
            int a = -vectorCoordinates.y;
            int b = vectorCoordinates.x;
            x = position.x;
            y = position.y;
            if(a == 0 && b == 0)
                A = B = C = 0;
            double dist = sqrt(a * a + b * b);
            A = 1.0 * a / dist;
            B = 1.0 * b / dist;
            C = -(A * position.x + B * position.y);
        }
        /*!
         * \brief monster's shot
         * \param monster
         * \param hero
         */
        Shot(Level *level, MonsterObject* monster){
            lev = level;
            damage = monster -> getMonsterState() -> getDamage();
            owner = Owner::Monster;
            switch (monster -> getMonsterState() -> getWeaponType()) {
            case Weapon::Gun:
                shotType = WeaponTypes::Gun;
                break;
            case Weapon::Mage:
                shotType = Mage;
                break;
            default:
                shotType = Melee;
                break;
            }
            Point position = lev->getPos(monster);
            Point vectorCoordinates = lev->getPos(lev->getMainHeroObject()) - lev -> getPos(monster);
            int a = -vectorCoordinates.y;
            int b = vectorCoordinates.x;
            x = position.x;
            y = position.y;
            if(a == 0 && b == 0)
                A = B = C = 0;
            double dist = sqrt(a * a + b * b);
            A = 1.0 * a / dist;
            B = 1.0 * b / dist;
            C = -(A * position.x + B * position.y);
            if(A == 0 && B == 0)
                deleteShot();
        }
        WeaponTypes getType(){
            return shotType;
        }
        Point getPos(){
            return Point{(int)x, (int)y};
        }
        Owner getOwner(){
            return owner;
        }
        unsigned int getDamage(){
            return damage;
        }
        //не проверено
        /*!
         * \brief move shot by it's trace
         * \param lev level
         */
        void takeMove(Level* lev){
            if(B != 0){
                double k = - A / B;
                double tx = 1.0 / sqrt(1 + k * k);
                double ty = x * k;
                if(lev -> checkBorder(Point{(int)(x + tx), (int)(y + ty)})){
                    x += tx;
                    y += ty;
                }
                else
                    deleteShot();
            }
            else
                y += 1;
        }
        /*!
         * \brief delete shot
         */
        void deleteShot(){
            delete [] this;
        }
        //проверить неявное приведение к int
        //ругается через раз
        /*!
         * \brief check if shot too close
         * \param pos
         * \return true if in epsilon radius
         */
        bool checkColision(Point pos){
            return (fabs(A * pos.x + B * pos.y + C) <= EPSILON &&
                    fabs(pos.x - x) <= EPSILON && fabs(pos.y - y) <= EPSILON);
        }
    private:
        Level* lev;
        double A, B, C;
        double x, y;
        WeaponTypes shotType;
        Owner owner;
        unsigned int damage;
    };
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
    list <Shot*> getListOfShots();
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
     * \brief get health of hero
     * \return hero's health
     */
    int getHeroHealth();
    /*!
     * \brief get gold of hero
     * \return hero's gold
     */
    unsigned int getHeroGold();
    /*!
     * \brief get max health of hero
     * \return hero's max bhealth
     */
    int getHeroMaxHealth();
    /*!
     * \brief Move character by vectorCoordinates
     * \param character
     * \param vectorCoordinates
     */
    void takeMove(MapObject* character, Point vectorCoordinates);
    int getAmountOfMonsters();
    /*!
     * \brief takeHeroGold give some gold to hero
     * \param amountOfGold
     */
    void takeHeroGold(unsigned int amountOfGold);

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

    WeaponTypes getMonsterWeaponType(MonsterObject* monster);
    WeaponTypes getHeroWeaponType();
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
     * \brief heroAtacksMonster hero shots or hits monster
     * and improves his skill in any way
     * \param vectorCoordinates
     */
    void heroAtacksMonster(Point vectorCoordinates);
    /*!
     * \brief Monster take damage to hero
     * \param monster
     */
    void monsterAttaksHero(MonsterObject* monster);
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
    void combatMonstersAtackHero();
    /*!
     * \brief check evry shot on collision,
     * if it is near enemy it hits it
     * else move the shot on orthogonal vector
     */
    void takeShots();
    /*!
     * \brief playGame take all actions which aren't controlled by user
     * \param current time
     * \param time % shotTime == 0 then shots move
     * \param time % monsterTime == 0 then monster reacts
     */
    void playGame(unsigned int time, unsigned int shotTime, unsigned int monsterTime);

private:
    static double signum(double val);
    static int signum(int val);
    void heroGetsMonsterDrop(MonsterObject* monster);
    Point leftUpBorder, rightDownBorder;
    HeroObject* mainHero;
    TraderObject* trader;
    list <MonsterObject*> monsters;
    list <Shot*> shots;
    void setLeftUpBorder(int x, int y);
    void setRightDownBorder(int x, int y);

    /*!
     * \brief add shot
     * \param shot
     */
    void addShot(Shot* shot);
    /*!
     * \brief checkBorder
     * \param pos
     * \return true if inside border
     */
    bool checkBorder(Point pos);
};

#endif // LEVEL_H
