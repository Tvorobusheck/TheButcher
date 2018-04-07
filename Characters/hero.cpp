#include "hero.h"

unsigned int Hero::potionsCoefficient;

Hero::Hero(unsigned int amountOfMaxHealth, unsigned int maxLevel){
    setMaxHealth(amountOfMaxHealth);
    setCurHealth(amountOfMaxHealth);
    setWeapon(new Weapon(0, Weapon::TypeOfWeapon::Melee));
    setExp(new Experience(maxLevel, 100, 25));
    setGold(0);
    setAmountOfPotions(0);
    gunSkill.exp = new Experience(100, 100, 0);
    mageSkill.exp = new Experience(100, 100, 0);
    meleeSkill.exp = new Experience(100, 100, 0);
}


unsigned int Hero::getExp(){
    return exp -> getExp();
}

void Hero::setExp(Experience* expArgument){
    exp = expArgument;
}


unsigned int Hero::getGold(){
    return gold;
}

unsigned int Hero::getGunSkillExp(){
    return getSkillExp(gunSkill);
}
unsigned int Hero::getMageSkillExp(){
    return getSkillExp(mageSkill);
}
unsigned int Hero::getMeleeSkillExp(){
    return getSkillExp(meleeSkill);
}
unsigned int Hero::getGunSkillLevel(){
    return getSkillLevel(gunSkill);
}
unsigned int Hero::getMageSkillLevel(){
    return getSkillLevel(mageSkill);
}
unsigned int Hero::getMeleeSkillLevel(){
    return getSkillLevel(meleeSkill);
}

void Hero::takeGunSkillExp(unsigned int amountOfExp){
    takeSkillExp(gunSkill, amountOfExp);
}
void Hero::takeMageSkillExp(unsigned int amountOfExp){
    takeSkillExp(mageSkill, amountOfExp);
}
void Hero::takeMeleeSkillExp(unsigned int amountOfExp){
    takeSkillExp(meleeSkill, amountOfExp);
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
unsigned int Hero::getSkillExp(Hero::Skill skill){
    return skill.exp -> getExp();
}

unsigned int Hero::getSkillLevel(Hero::Skill skill){
    return skill.exp -> getCurrentLevel();
}
void Hero::takeSkillExp(Hero::Skill skill, unsigned int amountOfExp){
    skill.exp -> takeExp(amountOfExp);
}
