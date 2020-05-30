#pragma once

#include <vector>

#include "enemy.h"


#define GOBLIN_MIN_HP       10
#define GOBLIN_MAX_HP       15
#define GOBLIN_MIN_STR      5
#define GOBLIN_MAX_STR      8
#define GOBLIN_MIN_SPD      12
#define GOBLIN_MAX_SPD      25

#define SKELETON_MIN_HP     13
#define SKELETON_MAX_HP     18
#define SKELETON_MIN_STR    9
#define SKELETON_MAX_STR    11
#define SKELETON_MIN_SPD    14
#define SKELETON_MAX_SPD    19

#define WRAITH_MIN_HP       21
#define WRAITH_MAX_HP       25
#define WRAITH_MIN_STR      13
#define WRAITH_MAX_STR      16
#define WRAITH_MIN_SPD      11
#define WRAITH_MAX_SPD      16


class EnemyGenerator
{

public:
    static void GenerateEnemies(std::vector<Enemy>& vEnemies);
    static void GenerateSomeRandomNumbers();
private:
    static int GenRandNum(int min, int max);
    static EnemyType GenEnemyType();
    static int GenEnemyHP(EnemyType type);
    static int GenEnemySTR(EnemyType type);
    static int GenEnemySPD(EnemyType type);
    
};