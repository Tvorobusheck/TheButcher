#include "level.h"
#include <math.h>
using namespace std;
Level::Level_opt(int leftBorderVal, int upperBorderVal,
             int rightBorderVal, int lowerBorderVal,
             int heroX, int heroY,
             unsigned int heroMaxHealth, unsigned int heroMaxLevel,
             int traderX, int traderY)
{
    leftBorder = leftBorderVal;
    upperBorder = upperBorderVal;
    rightBorder = rightBorderVal;
    lowerBorder = lowerBorderVal;
    mainHero = new HeroObject(heroX, heroY, heroMaxHealth, heroMaxLevel);
    trader = new TraderObject(traderX, traderY);
}
Level::Level(int leftBorderVal, int upperBorderVal,
             int rightBorderVal, int lowerBorderVal,
             int heroX, int heroY,
             unsigned int heroMaxHealth, unsigned int heroMaxLevel,
             int traderX, int traderY)
{
    leftBorder = leftBorderVal;
    upperBorder = upperBorderVal;
    rightBorder = rightBorderVal;
    lowerBorder = lowerBorderVal;
    mainHero = new HeroObject(heroX, heroY, heroMaxHealth, heroMaxLevel);
    trader = new TraderObject(traderX, traderY);
}

MonsterObject* Level::addMonster(int x,  int y,
                       unsigned int amountOfMaxHealth,
                       unsigned int weaponDamage, WeaponTypes typeOfWeapon,
                       unsigned int dropExpAmount, unsigned int dropGoldAmount){
    Weapon::TypeOfWeapon weaponLibType;
    switch (typeOfWeapon) {
    case Gun:
        weaponLibType = Weapon::TypeOfWeapon::Gun;
        break;
    case Mage:
        weaponLibType = Weapon::TypeOfWeapon::Mage;
        break;
    case Melee:
        weaponLibType = Weapon::TypeOfWeapon::Melee;
        break;
    }
    MonsterObject* newMonster = new MonsterObject(x, y, amountOfMaxHealth, weaponDamage,
                                                 weaponLibType, dropExpAmount, dropGoldAmount);
    monsters.push_back(newMonster);
    return newMonster;
}

Level::Point Level::getPos(MapObject* character){
    return Point{character->getPosX(), character->getPosY()};
}
int Level::getHeroHealth(){
    return getMainHeroObject() -> getHeroState() -> getCurHealth();
}
int Level::getHeroMaxHealth(){
    return getMainHeroObject() -> getHeroState() -> getMaxHealth();
}
void Level::takeMove(MapObject* character, Level::Point vectorCoordinates){
    if(checkBorder(vectorCoordinates + getPos(character)))
        character->takeMovement(vectorCoordinates.x, vectorCoordinates.y);
}

int Level::getAmountOfMonsters(){
    return monsters.size();
}
bool Level::heroAbilityToBuyWeapon(){
    return trader -> getTrader() -> abilityToPayWeapon(mainHero -> getHeroState());
}
bool Level::heroAbilityToBuyOnePotion(){
    return trader -> getTrader() -> abilityToPayPotion(mainHero -> getHeroState());
}

void Level::heroBuysPotion(){
    return trader -> getTrader() -> heroBuysPotion(mainHero -> getHeroState());
}
void Level::heroBuysNewWeapon(WeaponTypes weaponType){
    Weapon::TypeOfWeapon weaponLibType;
    switch (weaponType) {
    case Gun:
        weaponLibType = Weapon::TypeOfWeapon::Gun;
        break;
    case Mage:
        weaponLibType = Weapon::TypeOfWeapon::Mage;
        break;
    case Melee:
        weaponLibType = Weapon::TypeOfWeapon::Melee;
        break;
    }
    trader -> getTrader() -> heroBuysWeapon(mainHero -> getHeroState(), weaponLibType);
}

Level::WeaponTypes Level::getMonsterWeaponType(MonsterObject* monster){
    switch (monster-> getMonsterState() -> getWeaponType()) {
    case Weapon::Gun:
        return Gun;
    case Weapon::Mage:
        return Mage;
    default:
        return Melee;
    }
}
Level::WeaponTypes Level::getHeroWeaponType(){
    switch (mainHero -> getHeroState() -> getWeaponType()) {
    case Weapon::Gun:
        return Gun;
    case Weapon::Mage:
        return Mage;
    default:
        return Melee;
    }
}
unsigned int Level::getHeroLevel(){
    return mainHero -> getHeroState() -> getLevel();
}
unsigned int Level::getHeroExp(){
    return mainHero -> getHeroState() -> getExp();
}

unsigned int Level::getHeroGunLevel(){
    return mainHero -> getHeroState() -> getGunSkillLevel();
}
unsigned int Level::getHeroGunExp(){
    return mainHero -> getHeroState() -> getGunSkillExp();
}
unsigned int Level::getHeroMageLevel(){
    return mainHero -> getHeroState() -> getMageSkillLevel();
}
unsigned int Level::getHeroMageExp(){
    return mainHero -> getHeroState() -> getMageSkillExp();
}
unsigned int Level::getHeroMeleeLevel(){
    return mainHero -> getHeroState() -> getMeleeSkillLevel();
}
unsigned int Level::getHeroMeleeExp(){
    return mainHero -> getHeroState() -> getMeleeSkillExp();
}
unsigned int Level::getHeroBaseDamage(){
    return mainHero -> getHeroState() -> getDamage();
}
unsigned int Level::getHeroRaisedDamage(){
    return mainHero -> getHeroState() -> getHeroicDamage();
}

void Level::heroAtacksMonster(Point vectorCoordinates){
    switch (mainHero -> getHeroState() -> getWeaponType()) {
    case Weapon::TypeOfWeapon::Gun:
        mainHero -> getHeroState() -> takeGunSkillExp(1);
        break;
    case Weapon::TypeOfWeapon::Mage:
        mainHero -> getHeroState() -> takeMageSkillExp(1);
        break;
    case Weapon::TypeOfWeapon::Melee:
        mainHero -> getHeroState() -> takeMeleeSkillExp(1);
        break;
    }
    for(auto monster: monsters){
        if(getHeroWeaponType() == Melee &&
                getPos(getMainHeroObject()) - getPos(monster) <= vectorCoordinates)
            if(monster -> getMonsterState() -> takeDamage(getHeroRaisedDamage()))
                heroGetsMonsterDrop(monster);
    }
    if(getHeroWeaponType() == Gun || getHeroWeaponType() == Mage)
         addShot(new Shot(this, vectorCoordinates));
}
void Level::monsterAttaksHero(MonsterObject* monster){
    if(getMonsterWeaponType(monster))
        mainHero -> getHeroState() -> takeDamage(monster -> getMonsterState() -> getDamage());
    else
        shots.push_back(new Shot(this, monster));
}
void Level::heroGetsMonsterDrop(MonsterObject* monster){
    mainHero -> getHeroState() -> takeGold(monster -> getMonsterState() -> getGoldDrop());
    mainHero -> getHeroState() -> takeExp(monster -> getMonsterState() -> getExpDrop());
}

void Level::heroDrinksPotion(){
    mainHero -> getHeroState() -> consumePotion();
}
unsigned int Level::getHeroAmountOfPotions(){
    return mainHero -> getHeroState() -> getAmountOfPotions();
}

Level::WeaponTypes Level::getCurrentWeaponType(){switch (mainHero -> getHeroState() -> getWeaponType()) {
    case Weapon::TypeOfWeapon::Gun:
        return WeaponTypes::Gun;
        break;
    case Weapon::TypeOfWeapon::Mage:
        return WeaponTypes::Mage;
        break;
    default:
        return WeaponTypes::Melee;
    }
}
void Level::killMonster(MonsterObject *monster){
    monsters.remove(monster);
}

void Level::checkArea(unsigned int radius){
    for(auto it: monsters)
        if(1ull * (it -> getPosX() - mainHero -> getPosX())* (it -> getPosX() - mainHero -> getPosX()) +
                1ull*(it -> getPosY() - mainHero -> getPosY())* (it -> getPosY() - mainHero -> getPosY()) <= radius * radius)
           it -> setCombatState(true);
    else
           it -> setCombatState(false);
}
int Level::signum(int val){
    if(val > 0)
        return 1;
    else if(val == 0)
        return 0;
    else
        return -1;

}
double Level::signum(double val){
    if(val > 0)
        return 1;
    else if(val == 0)
        return 0;
    else
        return -1;

}

void Level::combatMonstersAtackHero(){
    for(auto it: monsters)
        if(it -> isAttacks()){
            if(it -> getMonsterState() -> getWeaponType() == Weapon::TypeOfWeapon::Melee){
                if(1ull * (it -> getPosX() - mainHero -> getPosX())* (it -> getPosX() - mainHero -> getPosX()) +
                        1ull*(it -> getPosY() - mainHero -> getPosY())* (it -> getPosY() - mainHero -> getPosY()) <= MELEE_RADIUS * MELEE_RADIUS)
                    monsterAttaksHero(it);
                else{
                    int dirX = mainHero -> getPosX() - it -> getPosX();
                    int dirY = mainHero -> getPosY() - it -> getPosY();
                    takeMove(it, {dirX = signum(dirX),
                                 dirY = signum(dirY)});
                }
            }
            else{
                if(1ull * (it -> getPosX() - mainHero -> getPosX())* (it -> getPosX() - mainHero -> getPosX()) +
                        1ull*(it -> getPosY() - mainHero -> getPosY())* (it -> getPosY() - mainHero -> getPosY())
                        <= DISTANCE_WEAPON_RADIUS * DISTANCE_WEAPON_RADIUS)
                    addShot(new Shot(this, it));
                else{
                    int dirX = mainHero -> getPosX() - it -> getPosX();
                    int dirY = mainHero -> getPosY() - it -> getPosY();
                    takeMove(it, {dirX = signum(dirX),
                                 dirY = signum(dirY)});
                }
            }

        }
}

list <Level::Shot*> Level::getListOfShots(){
    return shots;
}
list <MonsterObject*> Level::getListOfMonsters(){
    return monsters;
}
list <MonsterObject*> Level::getListOfAttackingMonsters(){
    list <MonsterObject*> attackingMonsters;
    for(auto it: monsters)
        if(it -> isAttacks())
            attackingMonsters.push_back(it);
    return attackingMonsters;
}
list <MonsterObject*> Level::getListOfNonAttackingMonsters(){
    list <MonsterObject*> nonAttackingMonsters;
        for(auto it: monsters)
            if(it -> isAttacks())
                nonAttackingMonsters.push_back(it);
    return nonAttackingMonsters;
}

HeroObject* Level::getMainHeroObject(){
    return mainHero;
}
void Level::addShot(Shot *shot){
    shots.push_back(shot);
}
void Level::takeShots(){
    for(auto it: shots) {
        if(it -> getOwner() == Shot::Owner::Monster){
            if(it -> checkColision(getPos(getMainHeroObject()))){
                getMainHeroObject() -> getHeroState() -> takeDamage(it -> getDamage());
                shots.remove(it);
                delete [] it;
            }
            else
                it -> takeMove(this);
        }
        else{
            for(auto curMonster: monsters){
                if(it -> checkColision(getPos(curMonster))){
                    if(curMonster -> getMonsterState() -> takeDamage(it -> getDamage()))
                        heroGetsMonsterDrop(curMonster);
                    shots.remove(it);
                    delete [] it;
                    break;
                }
                else
                    it -> takeMove(this);
            }
        }
        if(checkBorder(it -> getPos())){
            shots.remove(it);
            delete [] it;
        }
    }
}

bool Level::checkBorder(Point pos){
    return pos.x >= leftBorder && pos.x <= rightBorder &&
            pos.y >= lowerBorder && pos.y <= upperBorder;
}

unsigned int Level::getHeroGold(){
    return getMainHeroObject() -> getHeroState() -> getGold();
}
void Level::takeHeroGold(unsigned int amountOfGold){
    getMainHeroObject() -> getHeroState() -> takeGold(amountOfGold);
}

void Level::playGame(unsigned int time, unsigned int shotTime, unsigned int monsterTime){
    if(time % monsterTime == 0){
        checkArea(SIGHT_RADIUS);
        combatMonstersAtackHero();
    }
    if(time % shotTime == 0){
        takeShots();
    }
}
