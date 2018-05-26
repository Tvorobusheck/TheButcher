#ifndef TRADER_H
#define TRADER_H
#include "character.h"
#include "hero.h"

#define POTION_DIVISIONER 3

class Trader: public Character
{
public:
    /*
     * return true if hero has enough money
     */
    bool abilityToPayWeapon(Hero *hero);
    bool abilityToPayPotion(Hero *hero);

    unsigned int getDamgeOfNewWeapon(Hero *hero);
    Weapon* heroBuysWeapon(Hero *hero, Weapon::TypeOfWeapon type);
    void heroBuysPotion(Hero *hero);
    /*
     * always return true, because traders never die!
     */
    bool takeDamage(unsigned int amountOfDamage);
    Trader();
private:
    const unsigned int damageCoeficient = 5;
    const unsigned int goldCoeficient = 5;
};

#endif // TRADER_H
