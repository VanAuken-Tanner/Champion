#include "enemyGenerator.h"

#include <iostream>
#include <random>
#include <chrono>

void EnemyGenerator::GenerateEnemies(std::vector<Enemy> &vEnemies)
{
    //Generate a number of enemies
    int numEnemies = GenRandNum(2, 4);

    for (int i = 0; i < numEnemies; i++)
    {
        EnemyType type = GenEnemyType();

        Enemy newEnemy(type, GenEnemyHP(type), GenEnemySTR(type), GenEnemySPD(type));

        vEnemies.emplace_back(newEnemy);
    }
}

int EnemyGenerator::GenRandNum(int min, int max)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    std::uniform_int_distribution<uint16_t> roller(min, max);

    return roller(generator);
}

EnemyType EnemyGenerator::GenEnemyType()
{
    auto var = GenRandNum(1,10);

    if (var > 0 && var <= 5)
        return EnemyType::GOBLIN;
    else if (var > 5 && var <= 9)
        return EnemyType::SKELETON;
    else
        return EnemyType::WRAITH;
}

int EnemyGenerator::GenEnemyHP(EnemyType type)
{
    switch (type)
    {
    case EnemyType::GOBLIN:
        return GenRandNum(GOBLIN_MIN_HP, GOBLIN_MAX_HP);
        break;
    case EnemyType::SKELETON:
        return GenRandNum(SKELETON_MIN_HP, SKELETON_MAX_HP);
        break;
    case EnemyType::WRAITH:
        return GenRandNum(WRAITH_MIN_HP, WRAITH_MAX_HP);
        break;
    default:
        break;
    }
    return -1;
}

int EnemyGenerator::GenEnemySTR(EnemyType type)
{
    switch (type)
    {
    case EnemyType::GOBLIN:
        return GenRandNum(GOBLIN_MIN_STR, GOBLIN_MAX_STR);
        break;
    case EnemyType::SKELETON:
        return GenRandNum(SKELETON_MIN_STR, SKELETON_MAX_STR);
        break;
    case EnemyType::WRAITH:
        return GenRandNum(WRAITH_MIN_STR, WRAITH_MAX_STR);
        break;
    default:
        break;
    }
    return -1;
}

int EnemyGenerator::GenEnemySPD(EnemyType type)
{
    switch (type)
    {
    case EnemyType::GOBLIN:
        return GenRandNum(GOBLIN_MIN_SPD, GOBLIN_MAX_SPD);
        break;
    case EnemyType::SKELETON:
        return GenRandNum(SKELETON_MIN_SPD, SKELETON_MAX_SPD);
        break;
    case EnemyType::WRAITH:
        return GenRandNum(WRAITH_MIN_SPD, WRAITH_MAX_SPD);
        break;
    default:
        break;
    }
    return -1;
}

void EnemyGenerator::GenerateSomeRandomNumbers()
{
    std::cout << "generating random numbers" << std::endl;
    int num = 0;
    int max = 100;
    int min = 1;

    for (int i = 0; i < 20; i++)
    {

        int num = GenRandNum(min, max);
        std::cout << num << std::endl;
    }

    std::cout << "done generating random numbers" << std::endl;
}