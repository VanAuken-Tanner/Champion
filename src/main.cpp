#include <iostream>
#include <string>
#include <vector>

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "battleManager.h"
#include "enemyGenerator.h"
#include "graphicsManager.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Welcome to Battle! A simple battle game in which our hero (you)
//gets to fight hordes of baddies!

//MAIN TODO
//Create player abilities
//Create player attack that utilizes random damage + modifiers.
//add armor to characters
//add xp and items to character
//add a status phase and menu

//create difficulty system (levels)

bool Continue()
{
    std::cout << "Continue?(y/n)..." << std::endl;
    std::string input;
    std::cin >> input;

    if(input == "end")
        return false;
    
    GraphicsManager::RefreshPage();
    return true;
}


int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
    {
        std::cout << "SDL Failed to init everything...  err:" << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL Init success..." << std::endl;
    }
    
    if(!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "SDL Image failed to init png...  err:" << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL Image success..." << std::endl;
    }
    

    bool running = true;
    int level = 1;
    GraphicsManager::Opening();

    Player player;
    player.printProfile();
    Continue();

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