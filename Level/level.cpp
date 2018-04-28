#include "level.h"

Level::Level(int borderXLeftUp, int borderYLeftUp,
             int borderXRightDown, int borderYRightDown,
             int heroX, int heroY,
             unsigned int heroMaxHealth, unsigned int heroMaxLevel,
             int traderX, int traderY)
{
    setLeftUpBorder(borderXLeftUp, borderYLeftUp);
    setRightDownBorder(borderXRightDown, borderYRightDown);
    mainHero = new HeroObject(heroX, heroY, heroMaxHealth, heroMaxLevel);
    trader = new TraderObject(traderX, traderY);
}
void Level::setLeftUpBorder(int x, int y){
    leftUpBorder.x = x;
    leftUpBorder.y = y;
}
void Level::setRightDownBorder(int x, int y){
    rightDownBorder.x = x;
    rightDownBorder.y = y;
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
void Level::takeMove(MapObject* character, Level::Point vectorCoordinates){
    if(vectorCoordinates.x > leftUpBorder.x && vectorCoordinates.x < rightDownBorder.x &&
            vectorCoordinates.y > rightDownBorder.y && vectorCoordinates.y < leftUpBorder.y)
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

bool Level::heroAtacksMonster(MonsterObject* monster){
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
    if(monster -> getMonsterState() -> takeDamage(getHeroRaisedDamage())){
        heroGetsMonsterDrop(monster);
        return true;
    }
    else
        return false;
}
bool Level::monsterAttaksHero(MonsterObject* monster){
    return mainHero -> getHeroState() -> takeDamage(monster -> getMonsterState() -> getDamage());
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

void Level::combatMonstersAtackHero(unsigned int dist){
    for(auto it: monsters)
        if(it -> isAttacks()){
            if(1ull * (it -> getPosX() - mainHero -> getPosX())* (it -> getPosX() - mainHero -> getPosX()) +
                    1ull*(it -> getPosY() - mainHero -> getPosY())* (it -> getPosY() - mainHero -> getPosY()) <= dist * dist)
                monsterAttaksHero(it);
            else{
                int dirX = mainHero -> getPosX() - it -> getPosX();
                int dirY = mainHero -> getPosY() - it -> getPosY();
                takeMove(it, {dirX = signum(dirX),
                             dirY = signum(dirY)});
            }
        }
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
