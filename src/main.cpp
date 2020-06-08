#include <iostream>
#include <string>
#include <vector>

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "battleManager.h"
#include "enemyGenerator.h"
#include "graphicsManager.h"
#include "game.h"

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


Game* game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();
    game->Init("Champion",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);


    const int FPS = 60;//how many frames we want in a second                        
    const int frameTargetTime = 1000 / FPS; //a frame should take 16 milliseconds
    Uint32 frameStart = 0;
    int frameTime = 0;

    
    while (game->State() != GAME_STATE::END)
    {

        frameStart = SDL_GetTicks();//milliseconds since sdl init



        game->HandleEvents();
        game->Update();
        game->Render();

        frameTime = SDL_GetTicks() - frameStart; //milliseconds our game took to loop

        if(frameTargetTime > frameTime)//if our frame time is less than our inteded frame time, delay by the difference.
        {
            SDL_Delay(frameTargetTime - frameTime);
        }

    }

    game->Clean();

    return 0;
}



// int main(int argc, char *argv[])
// {

    

//     bool running = true;
//     int level = 1;
//     GraphicsManager::Opening();
//     Continue();
//     Player player;
//     player.printProfile();
//     Continue();

//     while (running)
//     {
//         std::cout << "Loading..." << std::endl;
//         GraphicsManager::MilliWait(1000);
//         GraphicsManager::RefreshPage();
//         GraphicsManager::PrintLine();
//         std::cout << "Now beggining level: " << level << std::endl;
//         GraphicsManager::PrintLine();
//         GraphicsManager::MilliWait(2500);
//         GraphicsManager::RefreshPage();

//         std::vector<Enemy> enemies;
//         EnemyGenerator::GenerateEnemies(enemies, level);

//         BattleManager battler;
//         battler.CreateBattle(player,enemies);
//         battler.CommenceBattle();
        
    
//         level++;        
//         player.FullHeal();

//         running = Continue(); 
//     }

// }