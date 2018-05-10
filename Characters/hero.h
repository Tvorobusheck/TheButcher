#ifndef HERO_H
#define HERO_H
#define POTION_COEFFICIENT 30
#include "character.h"
#include "experience.h"

#define LEVELUP_HEALTH_INCOME 1.25
#define HERO_ORIGIN_EXP_THRESHOLD 100
#define HERO_MAX_LEVEL 25
#define SKILL_MAX_LEVEL 100
#define SKILL_EXP_THRESHOLD 100
#define SKILL_FIRST_LEVEL 0

class Hero: public Character
{
public:
    Hero(unsigned int amountOfMaxHealth, unsigned int maxLevel);
    unsigned int getLevel();
    unsigned int getExp();
    unsigned int getGunSkillLevel();
    unsigned int getMageSkillLevel();
    unsigned int getMeleeSkillLevel();
    unsigned int getGunSkillExp();
    unsigned int getMageSkillExp();
    unsigned int getMeleeSkillExp();

    unsigned int getGold();
    /* This function changes  gold negatively and positively
        returns false and do nothing if balance is negative
        returns true if balance is non-negative and change it
    */
    bool takeGold(int amountOfGold);
    void takeGunSkillExp(unsigned int amountOfExp);
    void takeMageSkillExp(unsigned int amountOfExp);
    void takeMeleeSkillExp(unsigned int amountOfExp);

    /*
     * return damage, which raised by skills
     */
    unsigned int getHeroicDamage();

    unsigned int getAmountOfPotions();
    unsigned int getPotionsCoefficient();
    void addAmountOfPotions(unsigned int amountOfPotions);
    void consumePotion();
    void takeExp(unsigned int amountOfExp);
    void giveNewWeapon(Weapon* newWeapon);
private:
    struct Skill
    {
        Experience* exp;
    };
    Experience* exp;
    Skill gunSkill;
    Skill mageSkill;
    Skill meleeSkill;
    unsigned int gold;
    unsigned int numberOfPotions;
    static unsigned int potionsCoefficient;

    void setGold(unsigned int amountOfGold);

    void setAmountOfPotions(unsigned int amountOfPotions);
    void setPotionsCoefficient(unsigned int valueOfPotionsCoefficient);

    void setExp(Experience* expArgument);

    unsigned int getSkillExp(Skill skill);
    unsigned int getSkillLevel(Skill skill);
    void takeSkillExp(Skill skill, unsigned int amountOfExp);
};

#endif // HERO_H
