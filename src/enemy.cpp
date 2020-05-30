#include <iostream>


#include "enemy.h"

std::string Enemy::GetEnemyName()
{
    switch (enType_)
    {
    case EnemyType::SKELETON:
        return "Skeleton";
        break;
    case EnemyType::GOBLIN:
        return "Goblin";
        break;
    case EnemyType::WRAITH:
        return "Wraith (elite)";
        break;
    default:
        break;
    }

    return "invalid enemy typing.";
}

void Enemy::printProfile()
{
    std::cout << GetEnemyName() << std::endl;
    Character::printProfile();
}