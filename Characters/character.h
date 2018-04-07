#ifndef CHARACTER_H
#define CHARACTER_H
#include "weapon.h"

/* Abstract class of characters */
class Character
{
public:
        /* Get states */
        int getCurHealth();
        unsigned int getMaxHealth();
        unsigned int getDamage();


        /* Character gets damage and health */

        /* Returns true, when character is alive
         * Returns false, when character is dead
         */
        virtual bool takeDamage(unsigned int amountOfDamage);
        void takeHealth(unsigned int amountOfHeal);

        /*Character has died */
        void killCharacter();
private:
        unsigned int maxHealth;
        /* Current health */
        int curHealth;
        Weapon* weapon;
protected:
        /*Setting*/
        void setCurHealth(int amountOfCurHealth);
        void setMaxHealth(unsigned int amountOfMaxHealth);
        void setWeapon(Weapon* weapon);
        Weapon::TypeOfWeapon getWeaponType();
};

#endif // CHARACTER_H
