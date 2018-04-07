#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
public:

    enum TypeOfWeapon{Gun, Mage, Melee};
    Weapon(unsigned int amountOfDamage, TypeOfWeapon typeOfWeapon);

    /* Getting weapon stats*/
    unsigned int getDamage();
    TypeOfWeapon getWeaponType();

private:
    unsigned int damage;
    TypeOfWeapon type;

    /* Setting stats */
    void setDamage(unsigned int amountOfDamage);
    void setType(TypeOfWeapon typeOfWeapon);
};

#endif // WEAPON_H
