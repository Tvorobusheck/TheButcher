#include "monsterobject.h"

MonsterObject::MonsterObject(int valX, int valY,
                             unsigned int amountOfMaxHealth, unsigned int amountOfDamage,
                             Weapon::TypeOfWeapon typeOfWeapon,
                             unsigned int amountOfDropExp, unsigned int amountOfDropGold)
{
    setPos(valX, valY);
    monster = new Monster(amountOfMaxHealth, amountOfDamage, typeOfWeapon, amountOfDropExp, amountOfDropGold);
}
Monster* MonsterObject::getMonsterState(){
    return monster;
}
void MonsterObject::setCombatState(bool inCombat){
    attacksHero = inCombat;
}
bool MonsterObject::isAttacks(){
    return attacksHero;
}
