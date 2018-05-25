#include "experience.h"
#include <assert.h>

Experience::Experience(unsigned int valueOfMaxLevel, unsigned int valueOfThreshold, double valueOfThresholdCoefficient,
           unsigned int amountOfLevels, unsigned int amountOfExp){
    setMaxLevel(valueOfMaxLevel);
    setThresholdExp(valueOfThreshold);
    setThresholdCoefficient(valueOfThresholdCoefficient);
    setCurrentLevel(amountOfLevels);
    setExp(amountOfExp);
}


unsigned int Experience::getExp(){
    return exp;
}
unsigned int Experience::getCurrentLevel(){
    return currentLevel;
}
unsigned int Experience::getThreshold(){
    return thresholdExp;
}
unsigned int Experience::getMaxLevel(){
    return maxLevel;
}
double Experience::getThresholdCoefficient(){
    return thresholdCoefficient;
}
void Experience::setExp(unsigned int amountOfExp){
    exp = amountOfExp;
    while(exp >= getThreshold())
        incLevel();
}
void Experience::setCurrentLevel(unsigned int amountOfLevels){
    currentLevel = 0;
    for(unsigned int i = 0; i < amountOfLevels; i++)
        incLevel();
}
void Experience::setMaxLevel(unsigned int valueOfMaxLevel){
    maxLevel = valueOfMaxLevel;
}
/* Set exp threshold for all heroes */
void Experience::setThresholdExp(unsigned int border){
    thresholdExp = border;
}
/* Adding one level */
void Experience::incLevel(){
    if(getCurrentLevel() < getMaxLevel()){
        currentLevel++;
        incThresholdExp();
    }
}
void Experience::incThresholdExp(){
    setExp(0);
    setThresholdExp(getThreshold() * getThresholdCoefficient());
}
void Experience::setThresholdCoefficient(double valueOfCoefficient){
    thresholdCoefficient = valueOfCoefficient;
}
/* This function add exp to hero */
void Experience::takeExp(unsigned int amountOfExp){
    setExp(getExp() + amountOfExp);
}
