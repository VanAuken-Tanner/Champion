#pragma once

#include "character.h"
#include <string>

enum ROLE
{
    PEASANT,
    GOD,
    THIEF,
    ARCHER,
    SORCERER,
    MAGE,
    WARRIOR,
    BARBARIAN 
};

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
    Player();
    Player(std::string name, ROLE role, int hp, int strength, int speed) : Character(hp, strength, speed), name_{name}, role_{role} {}
    void InitPlayer();
    void printProfile();
    std::string GetRoleName();
    std::string GetName() {return name_;};
    void FullHeal() {hpcur_ = hpmax_;};

private:
    std::string GetNewName();
    bool GetAnswer(std::string msg, std::string opt1, std::string opt2);
    ROLE GetPlayerClass();
    ROLE role_;
    std::string name_;
    STATE state_;
};