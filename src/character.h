#pragma once
#include <string>



class Character
{
public:
    Character();
    Character(int hp, int strength, int speed) : hpcur_{hp}, hpmax_{hp}, strength_{strength}, speed_{speed} {}

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
    int speed_;


};