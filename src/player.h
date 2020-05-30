#pragma once

#include "character.h"
#include <string>


enum STATE
{
    IDLE,
    ATTACKING,
    DEFENDING,
    RUNNING
};

class Player : public Character
{

public:
    Player(std::string name, int hp, int strength, int speed) : Character(hp, strength, speed), name_{name} {}

    void printProfile();
    std::string GetName() {return name_;};
    
private:
    std::string name_;
    STATE state_;
};