#include "weapon.h"

/* Creating Weapon class object */
Weapon::Weapon(unsigned int amountOfDamage, TypeOfWeapon typeOfWeapon){
    setDamage(amountOfDamage);
    setType(typeOfWeapon);
}

unsigned int Weapon::getDamage(){
    return damage;
}
Weapon::TypeOfWeapon Weapon::getWeaponType(){
    return type;
}

void Weapon::setDamage(unsigned int amountOfDamage){
    damage = amountOfDamage;
}
void Weapon::setType(TypeOfWeapon typeOfWeapon){
    type = typeOfWeapon;
}
