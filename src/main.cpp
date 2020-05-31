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
//Create player classes and abilities
//Create player attack that utilizes random damage + modifiers.
//add armor to characters

//create difficulty system (levels)

bool Continue()
{
    std::cout << "Continue?..." << std::endl;
    std::string input;
    std::cin >> input;

    if(input == "end")
        return false;
    
    GraphicsManager::RefreshPage();
    return true;
}


int main(int argc, char *argv[])
{

    bool running = true;
    int level = 1;
    GraphicsManager::Opening();

    Player player;
    //player.printProfile();
    //running = Continue();

    while (running)
    {
        std::cout << "Loading..." << std::endl;
        GraphicsManager::MilliWait(1000);
        GraphicsManager::RefreshPage();
        GraphicsManager::PrintLine();
        std::cout << "Now beggining level: " << level << std::endl;
        GraphicsManager::PrintLine();
        GraphicsManager::MilliWait(2500);
        GraphicsManager::RefreshPage();

        std::vector<Enemy> enemies;
        EnemyGenerator::GenerateEnemies(enemies, level);

        BattleManager battler;
        battler.CreateBattle(player,enemies);
        battler.CommenceBattle();
        
    
        level++;        
        player.FullHeal();

        running = Continue(); 
    }

}