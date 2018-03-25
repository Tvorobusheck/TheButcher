#ifndef HERO_H
#define HERO_H

#include "character.h"
#include "experience.h"

class Hero: public Character
{
public:
    struct Skill
    {
        Experience* exp;
        Skill() {
            exp = new Experience(100, 25);
        }
    };
    Hero(unsigned int amountOfMaxHealth);

    Experience* getExp();
    void setExp(Experience* expArgument);

    Skill getGunSkill();
    Skill getMageSkill();
    Skill getMeleeSkill();

    unsigned int getGold();
    void setGold(unsigned int amountOfGold);
    /* This function changes  gold negatively and positively
        returns false and do nothing if balance is negative
        returns true if balance is non-negative and change it
    */
    bool takeGold(int amountOfGold);

    unsigned int getAmountOfPotions();
    unsigned int getPotionsCoefficient();
    void setAmountOfPotions(unsigned int amountOfPotions);
    void setPotionsCoefficient(unsigned int valueOfPotionsCoefficient);
    void addAmountOfPotions(unsigned int amountOfPotions);
    void consumePotion();

private:
    Experience* exp;
    Skill gunSkill;
    Skill mageSkill;
    Skill meleeSkill;
    unsigned int gold;
    unsigned int numberOfPotions;
    static unsigned int potionsCoefficient;
};

#endif // HERO_H
