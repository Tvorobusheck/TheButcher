#include "trader.h"

Trader::Trader()
{
    setMaxHealth(1);
    setCurHealth(1);
    setWeapon(new Weapon(0, Weapon::Melee));
}
bool Trader::takeDamage(unsigned int amountOfDamage){
    setCurHealth(getCurHealth() - 0 * amountOfDamage);
    if(getCurHealth() > 0)
       return true;
    else
        return false;
}

bool Trader::abilityToPayWeapon(Hero *hero){
    if(hero -> getGold() >= hero -> getLevel() * goldCoeficient)
        return true;
    else
        return false;
}
bool Trader::abilityToPayPotion(Hero *hero){
    if(hero -> getGold() >= hero -> getLevel() * goldCoeficient / POTION_DIVISIONER)
        return true;
    else
        return false;

}
unsigned int Trader::getDamgeOfNewWeapon(Hero *hero){
    return hero -> getLevel() * damageCoeficient;
}
Weapon* Trader::heroBuysWeapon(Hero *hero, Weapon::TypeOfWeapon type){
    hero -> takeGold(-hero -> getLevel() * goldCoeficient);
    return new Weapon(hero -> getLevel() * damageCoeficient, type);
}

void Trader::heroBuysPotion(Hero *hero){
    hero -> takeGold(-hero -> getLevel() * goldCoeficient / POTION_DIVISIONER);
    hero -> addAmountOfPotions(1);
}
