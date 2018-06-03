#ifndef WEAPON_H
#define WEAPON_H
#include <gtest/gtest_prod.h>
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
    FRIEND_TEST(WeaponCase, WeaponTypeGetSet);
    FRIEND_TEST(WeaponCase, WeaponDamageGetSet);
    /* Setting stats */
    void setDamage(unsigned int amountOfDamage);
    void setType(TypeOfWeapon typeOfWeapon);
};

#endif // WEAPON_H
