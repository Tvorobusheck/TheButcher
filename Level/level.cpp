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
void Level::addMonster(int x,  int y,
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
    monsters.push_back(new MonsterObject(x, y, amountOfMaxHealth, weaponDamage,
                                         weaponLibType, dropExpAmount, dropGoldAmount));
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
bool Level::heroPayAbilityToBuyWeapon(){
    return trader -> getTrader() -> abilityToPayWeapon(mainHero -> getHeroState());
}
bool Level::heroPayAbilityToBuyOnePotion(){
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
