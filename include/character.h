#pragma once
#include <string>


#include "STATS.h"


class Character
{
public:
    Character();
    Character(int hp, int str, int def, int agi, int wil, int spd, int luck);

    int GetCurrentHP() {return hpcur_;};
    int GetMaxHP() {return hpmax_;};
    int GetSTR() {return strength_;};
    int GetSPD() {return speed_;};
    bool IsAlive(){return hpcur_ > 0;};

    int TakeHit(int dmg);

    virtual void printProfile();
protected:

    //Base stats that all combatants will need
    int hpmax_;
    int hpcur_;

    int strength_;
    int defense_;
    int agility_;
    int willpower_;
    int speed_;
    int luck_;

    bool isOmnipotent;

    
};