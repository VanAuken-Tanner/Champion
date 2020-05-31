#pragma once

#include <string>


#include "character.h"
#include "STATS.h"

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
    Enemy(EnemyType eType, int hp, int str, int def, int agi, int wil, int spd, int luck) : Character(hp, str, def, agi, wil, spd, luck), enType_{eType} {}

    void printProfile();
    std::string GetEnemyName();
    EnemyType GetEnemyType() {return enType_;};
private:
    EnemyType enType_;
};