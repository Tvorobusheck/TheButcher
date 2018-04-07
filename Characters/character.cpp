#include "character.h"
#include "weapon.h"

int Character::getCurHealth(){
    return curHealth;
}

unsigned int Character::getMaxHealth(){
    return maxHealth;
}
unsigned int Character::getDamage(){
    return weapon -> getDamage();
}

void Character::setCurHealth(int amountOfCurHealth){
    curHealth = amountOfCurHealth;
}

void Character::setMaxHealth(unsigned int amountOfMaxHealth){
    maxHealth = amountOfMaxHealth;
}

void Character::setWeapon(Weapon* newWeapon){
    weapon = newWeapon;
}

/* Returns true, when character is alive
 * Returns false, when character is dead
 */
bool Character::takeDamage(unsigned int amountOfDamage){
    setCurHealth(getCurHealth() - amountOfDamage);
    if(getCurHealth() <= 0){
        killCharacter();
        return false;
    }
    return true;
}
void Character::takeHealth(unsigned int amountOfHealth){
    setCurHealth(getCurHealth() + amountOfHealth);
    if((unsigned)getCurHealth() > getMaxHealth())
        setCurHealth(getMaxHealth());
}

void Character::killCharacter(){
    delete [] this;
}
