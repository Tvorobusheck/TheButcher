#ifndef EXPERIENCE_H
#define EXPERIENCE_H


class Experience
{
public:
    Experience(unsigned int valueOfThreshold, unsigned int valueOfThresholdCoefficient,
               unsigned int amountOfExp = 0, unsigned int amountOfLevels = 0);

    unsigned int getExp();
    unsigned int getLevel();
    unsigned int getThreshold();
    unsigned int getThresholdCoefficient();

    void setExp(unsigned int amountOfExp);
    void setLevel(unsigned int amountOfLevel);

    /* Set exp threshold which aiming causes levelup */
    void setThresholdExp(unsigned int border);
    void setThresholdCoefficient(unsigned int valueOfCoefficient);
    /* Adding one level */
    void incLevel();
    void incThresholdExp();
    /* This function add exp to hero */
    void takeExp(unsigned int amountOfExp);
private:
    /* Value which define levelup */
    unsigned int thresholdExp;
    unsigned int thresholdCoefficient;
    /* Expirience */
    unsigned int exp;
    unsigned int level;
};

#endif // EXPERIENCE_H
