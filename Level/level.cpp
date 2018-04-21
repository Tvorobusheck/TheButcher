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
int Level::getAmountOfMonsters(){
    return monsters.size();
}
