#pragma once

#include <vector>

#include "enemy.h"


class EnemyGenerator
{

public:
    static void GenerateEnemies(std::vector<Enemy>& vEnemies, int level);

private:
    static int GenerateEnemiesForLevel(int level);

    static Enemy GenEnemy(EnemyType type);
    static int GenEnemyHP(EnemyType type);
    static int GenEnemySTR(EnemyType type);
    static int GenEnemySPD(EnemyType type);
    
};