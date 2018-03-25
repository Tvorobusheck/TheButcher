#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
public:

    enum TypeOfWeapon{Gun, Mage, Melee, None};
    Weapon(unsigned int amountOfDamage, TypeOfWeapon typeOfWeapon);

    /* Getting weapon stats*/
    unsigned int getDamage();
    TypeOfWeapon getWeaponType();

    /* Setting stats */
    void setDamage(unsigned int amountOfDamage);
    void setType(TypeOfWeapon typeOfWeapon);
private:
    unsigned int damage;
    TypeOfWeapon type;
};

#endif // WEAPON_H
