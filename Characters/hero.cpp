#include "hero.h"

unsigned int Hero::potionsCoefficient;

Hero::Hero(unsigned int amountOfMaxHealth){
    setMaxHealth(amountOfMaxHealth);
    setCurHealth(amountOfMaxHealth);
    setWeapon(new Weapon(0, Weapon::TypeOfWeapon::None));
    setExp(new Experience(100, 25, 0, 0));
    setGold(0);
    setAmountOfPotions(0);
}


Experience* Hero::getExp(){
    return exp;
}

void Hero::setExp(Experience* expArgument){
    exp = expArgument;
}


unsigned int Hero::getGold(){
    return gold;
}

Hero::Skill Hero::getGunSkill(){
    return gunSkill;
}
Hero::Skill Hero::getMageSkill(){
    return mageSkill;
}
Hero::Skill Hero::getMeleeSkill(){
    return meleeSkill;
}
void Hero::setGold(unsigned int amountOfGold){
    gold = amountOfGold;
}

unsigned int Hero::getAmountOfPotions(){
    return numberOfPotions;
}

/* This function changes  gold negatively and positively */
bool Hero::takeGold(int amountOfGold){
    if((signed)getGold() + amountOfGold >= 0){
        setGold((signed)getGold() + amountOfGold);
        return true;
    }
    else
        return false;
}

unsigned int Hero::getPotionsCoefficient(){
    return potionsCoefficient;
}



void Hero::addAmountOfPotions(unsigned int amountOfPotions){
    setAmountOfPotions(getAmountOfPotions() + amountOfPotions);
}



void Hero::setAmountOfPotions(unsigned int amountOfPotions){
    numberOfPotions = amountOfPotions;
}
void Hero::setPotionsCoefficient(unsigned int valueOfPotionsCoefficient){
    potionsCoefficient = valueOfPotionsCoefficient;
}
void Hero::consumePotion(){
    if(getAmountOfPotions() > 0)
        setAmountOfPotions(getAmountOfPotions() - 1);
    takeHealth(getMaxHealth() * getPotionsCoefficient() / 100.0);
}
