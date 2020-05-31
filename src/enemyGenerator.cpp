#include "enemyGenerator.h"

#include <iostream>
#include <random>
#include <chrono>

//Generates enemies based on the users current level
void EnemyGenerator::GenerateEnemies(std::vector<Enemy> &vEnemies, int level)
{
    vEnemies.clear();
    //int min = 0; int max = 0;
    switch (level)
    {
        case 1:
        case 2://goblins
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            break;
        }
        case 3:
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::SKELETON));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            break;
        }
        case 4://skeletons and goblins
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::SKELETON));
            vEnemies.emplace_back(GenEnemy(EnemyType::SKELETON));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            break;
        }
        case 5://wraith
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::WRAITH));
            vEnemies.emplace_back(GenEnemy(EnemyType::WRAITH));
            break;
        }
        case 6:
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::SKELETON));
            vEnemies.emplace_back(GenEnemy(EnemyType::WRAITH));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            break;
        }
        case 7://goblins and skeletons and wraiths
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::WRAITH));
            vEnemies.emplace_back(GenEnemy(EnemyType::SKELETON));
            vEnemies.emplace_back(GenEnemy(EnemyType::WRAITH));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            break;
        }
        case 8:// many small enemies
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            vEnemies.emplace_back(GenEnemy(EnemyType::GOBLIN));
            break;
        }
        case 9://cyclops
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::CYCLOPS));
            vEnemies.emplace_back(GenEnemy(EnemyType::CYCLOPS));
            break;
        }
        case 10://dragon
        {
            vEnemies.emplace_back(GenEnemy(EnemyType::DRAGON));
            break;
        }
    }
}

Enemy EnemyGenerator::GenEnemy(EnemyType type)
{
    Enemy newEnemy(type, GenEnemyHP(type), GenEnemySTR(type), GenEnemySPD(type));
    return newEnemy;
}

int EnemyGenerator::GenerateEnemiesForLevel(int level)
{
    int min = 0; int max = 0;

    switch (level)
    {
        case 0:
        case 1:
        case 2://goblins
        {
            min = 2;
            max = 3;
            break;
        }
        case 3:
        case 4://skeletons and goblins
        {
            min = 4;
            max = 5;
            break;
        }
        case 5://wraith
        {
            min = max = 3;
            break;
        }
        case 6:
        case 7://goblins and skeletons and wraiths
        {
            min = 3;
            max = 5;
            break;
        }
        case 8:// many small enemies
        {
            min = 8;
            max = 11;
        }
        case 9://cyclops
        {
            min = max = 2;
        }
        case 10://dragon
        {
            min = max = 1;
        }
    }

    return GenRandNum(min,max);
}

int EnemyGenerator::GenRandNum(int min, int max)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    std::uniform_int_distribution<uint16_t> roller(min, max);

    return roller(generator);
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