#pragma once

#include <string>


#include "character.h"

enum EnemyType
{
    SKELETON,
    GOBLIN,
    WRAITH,
    CYCLOPS,
    DRAGON
};



class Enemy : public Character
{
public:
    Enemy(EnemyType eType, int hp, int strength, int speed) : Character(hp, strength, speed), enType_{eType} {}

    void printProfile();
    std::string GetEnemyName();
    EnemyType GetEnemyType() {return enType_;};
private:
    EnemyType enType_;
};