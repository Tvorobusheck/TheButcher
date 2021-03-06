#ifndef EXPERIENCE_H
#define EXPERIENCE_H


class Experience
{
public:
    Experience(unsigned int valueOfMaxLevel, unsigned int valueOfThreshold, double valueOfThresholdCoefficient,
               unsigned int amountOfExp = 0, unsigned int amountOfLevels = 0);

    unsigned int getExp();
    unsigned int getCurrentLevel();
    unsigned int getThreshold();
    double getThresholdCoefficient();
    unsigned int getMaxLevel();

    void setExp(unsigned int amountOfExp);
    void setCurrentLevel(unsigned int amountOfLevel);
    /* Set exp threshold which aiming causes levelup */
    void setThresholdExp(unsigned int border);
    void setMaxLevel(unsigned int valueOfMaxLevel);
    void setThresholdCoefficient(double valueOfCoefficient);
    /* Adding one level */
    void incLevel();
    void incThresholdExp();
    /* This function add exp to hero */
    void takeExp(unsigned int amountOfExp);
private:
    /* Value which define levelup */
    unsigned int thresholdExp;
    double thresholdCoefficient;
    /* Expirience */
    unsigned int exp;
    unsigned int currentLevel;
    unsigned int maxLevel;
};

#endif // EXPERIENCE_H
