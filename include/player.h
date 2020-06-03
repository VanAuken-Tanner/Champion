#pragma once

#include "character.h"
#include <string>

enum CLASS
{
    PEASANT,
    GOD,
    THIEF,
    ARCHER,
    SORCERER,
    MAGE,
    KNIGHT,
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
    Player(std::string name, CLASS newclass) : Character(), name_{name}, class_{newclass} {}
    void InitPlayer();
    void printProfile();
    std::string GetRoleName();
    std::string GetName() {return name_;};
    void FullHeal() {hpcur_ = hpmax_;};

    int GetAttacked(int dmg);
    int Attack();
    int Defend();
    



private:
    std::string GetNewName();
    bool GetAnswer(std::string msg, std::string opt1, std::string opt2);
    CLASS GetPlayerClass();
    CLASS class_;
    std::string name_;
    STATE state_;
};