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

#define CYCLOPS_MIN_HP      25
#define CYCLOPS_MAX_HP      38
#define CYCLOPS_MIN_STR     21
#define CYCLOPS_MAX_STR     26
#define CYCLOPS_MIN_SPD     13
#define CYCLOPS_MAX_SPD     19

#define DRAGON_MIN_HP       35
#define DRAGON_MAX_HP       50
#define DRAGON_MIN_STR      24
#define DRAGON_MAX_STR      31
#define DRAGON_MIN_SPD      28
#define DRAGON_MAX_SPD      35

class EnemyGenerator
{

public:
    static void GenerateEnemies(std::vector<Enemy>& vEnemies, int level);
    static void GenerateSomeRandomNumbers();
private:
    static int GenerateEnemiesForLevel(int level);
    static int GenRandNum(int min, int max);
    static Enemy GenEnemy(EnemyType type);
    static int GenEnemyHP(EnemyType type);
    static int GenEnemySTR(EnemyType type);
    static int GenEnemySPD(EnemyType type);
    
};