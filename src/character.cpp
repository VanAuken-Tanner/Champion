#include "character.h"

#include <iostream>

Character::Character()
{

}

Character::Character(int hp, int str, int def, int agi, int wil, int spd, int luck)
{
    hpmax_ = hpcur_ = hp;
    strength_ = str;
    defense_ = def;
    agility_ = agi;
    willpower_ = wil;
    speed_ = spd;
    luck_ = luck_;
}

void Character::printProfile()
{
    std::cout << "HP:  " << hpmax_ << std::endl;
    std::cout << "STR: " << strength_ << std::endl;
    std::cout << "DEF: " << defense_ << std::endl;
    std::cout << "AGI: " << agility_ << std::endl;
    std::cout << "WIL: " << willpower_ << std::endl;
    std::cout << "SPD: " << speed_ << std::endl;
    std::cout << "LCK: " << luck_ << std::endl;
}

int Character::TakeHit(int dmg)
{
    int dmg_modded = dmg;
    hpcur_ -= dmg_modded;
    return dmg_modded;
}