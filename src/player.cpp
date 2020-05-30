#include <iostream>

#include "player.h"

void Player::printProfile()
{
    std::cout<< name_<<std::endl;
    Character::printProfile();
}