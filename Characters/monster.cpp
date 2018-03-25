#include "monster.h"

Monster::Monster(unsigned int amountOfMaxHealth, unsigned int weaponDamage,
                 Weapon::TypeOfWeapon weaponType,
                 unsigned int dropExp, unsigned int dropGold)
{
    setMaxHealth(amountOfMaxHealth);
    setCurHealth((signed)amountOfMaxHealth);
    setWeapon(new Weapon(weaponDamage, weaponType));
    setExpDrop(dropExp);
    setGoldDrop(dropGold);
}

Monster::Monster(unsigned int amountOfMaxHealth, int amountOfCurHealth,
                 unsigned int weaponDamage, Weapon::TypeOfWeapon weaponType,
                 unsigned int dropExp, unsigned int dropGold)
{
    setMaxHealth(amountOfMaxHealth);
    setCurHealth(amountOfCurHealth);
    setWeapon(new Weapon(weaponDamage, weaponType));
    setExpDrop(dropExp);
    setGoldDrop(dropGold);
}
void Monster::setExpDrop(unsigned int amountOfExp){
    expDrop = amountOfExp;
}
void Monster::setGoldDrop(unsigned int amountOfGold){
    goldDrop = amountOfGold;
}

unsigned int Monster::getExpDrop(){
    return expDrop;
}

unsigned int Monster::getGoldDrop(){
    return goldDrop;
}

void Monster::killCharacter(){
    delete [] this;
}
