#include <iostream>
#include <string>
#include <vector>

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "battleManager.h"
#include "enemyGenerator.h"
#include "graphicsManager.h"

//Welcome to Battle! A simple battle game in which our hero (you)
//gets to fight hordes of baddies!

//MAIN TODO
//random enemy generation
//eliminating multiple enemies
//player choosing which enemy to attack

int main(int argc, char *argv[])
{

    bool running = true;
    std::cout << "battle begin!" << std::endl;

    Player player("Tanner", 100, 20, 30);
    player.printProfile();

    while (running)
    {
        std::vector<Enemy> enemies;
        EnemyGenerator::GenerateEnemies(enemies);
        
        BattleManager battler;
        battler.CreateBattle(player,enemies);
        battler.CommenceBattle();
        
        
        std::cout << "MAIN GAME INPUT" << std::endl;
        std::string input;
        std::cin >> input;
        if(input == "end")
            running = false;
        else
            GraphicsManager::RefreshPage();
        
    }

}