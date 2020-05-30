#include "character.h"

#include <iostream>


void Character::printProfile()
{
    std::cout << hpmax_ << std::endl;
    std::cout << strength_ << std::endl;
}

int Character::TakeHit(int dmg)
{
    int dmg_modded = dmg;
    hpcur_ -= dmg_modded;
    return dmg_modded;
}