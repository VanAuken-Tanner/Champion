#include "enemyGenerator.h"

#include <iostream>
#include <random>
#include <chrono>

#include "dice.h"

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
    Enemy newEnemy(type, GenEnemyHP(type), GenEnemySTR(type), 0, 0, 0, GenEnemySPD(type), 0);
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

    return Dice::GetDice()->Roll(min,max);
}



int EnemyGenerator::GenEnemyHP(EnemyType type)
{
    switch (type)
    {
    case EnemyType::GOBLIN:
        return Dice::GetDice()->Roll(GOBLIN_BASE_HP, GOBLIN_BASE_HP);
        break;
    case EnemyType::SKELETON:
        return Dice::GetDice()->Roll(SKELETON_BASE_HP, SKELETON_BASE_HP);
        break;
    case EnemyType::WRAITH:
        return Dice::GetDice()->Roll(WRAITH_BASE_HP, WRAITH_BASE_HP);
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
        return Dice::GetDice()->Roll(GOBLIN_BASE_STR, GOBLIN_BASE_STR);
        break;
    case EnemyType::SKELETON:
        return Dice::GetDice()->Roll(SKELETON_BASE_STR, SKELETON_BASE_STR);
        break;
    case EnemyType::WRAITH:
        return Dice::GetDice()->Roll(WRAITH_BASE_STR, WRAITH_BASE_STR);
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
        return Dice::GetDice()->Roll(GOBLIN_BASE_SPD, GOBLIN_BASE_SPD);
        break;
    case EnemyType::SKELETON:
        return Dice::GetDice()->Roll(SKELETON_BASE_SPD, SKELETON_BASE_SPD);
        break;
    case EnemyType::WRAITH:
        return Dice::GetDice()->Roll(WRAITH_BASE_SPD, WRAITH_BASE_SPD);
        break;
    default:
        break;
    }
    return -1;
}