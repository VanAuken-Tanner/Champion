#include "graphicsManager.h"

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

#define QUARTER_SECOND      250
#define HALF_SECOND         500
#define FULL_SECOND         1000
#define THREE_SECONDS       3000

void GraphicsManager::RefreshPage()
{
    for (int i = 0; i < screenlength_g; i++)
        std::cout << std::endl;
}

void GraphicsManager::NewLine()
{
    std::cout << std::endl;
}

void GraphicsManager::PrintLine()
{
    for (int i = 0; i < screenwidth_g; i++)
        std::cout << "=";

    std::cout << std::endl;
}

void GraphicsManager::MilliWait(int nanoSeconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(nanoSeconds));
}

void GraphicsManager::Opening()
{
    GraphicsManager::RefreshPage();
    PrintLine();
    std::cout << "Champion!" << std::endl;
    PrintLine();
    std::cout << "Loading." << std::endl;
    MilliWait(2000);
    GraphicsManager::RefreshPage();
    PrintLine();
    std::cout << "Champion!" << std::endl;
    PrintLine();
    std::cout << "Loading.." << std::endl;
    MilliWait(1000);
    GraphicsManager::RefreshPage();
    PrintLine();
    std::cout << "Champion!" << std::endl;
    PrintLine();
    std::cout << "Loading..." << std::endl;
    MilliWait(1000);
    GraphicsManager::RefreshPage();
    PrintLine();
    std::cout << "Champion!" << std::endl;
    PrintLine();
    std::cout << "Loading...." << std::endl;
    MilliWait(250);
    GraphicsManager::RefreshPage();
    PrintLine();
    std::cout << "Champion!" << std::endl;
    PrintLine();
    std::cout << "Loading....." << std::endl;
    MilliWait(250);
    GraphicsManager::RefreshPage();
    PrintLine();
    std::cout << "Champion!" << std::endl;
    PrintLine();
    std::cout << "Loading......" << std::endl;
    MilliWait(100);
    GraphicsManager::RefreshPage();
}

void GraphicsManager::PrintCombat(bool success, bool isplayer, std::string attacker, std::string defender, int dmg)
{
    GraphicsManager::RefreshPage();
    GraphicsManager::PrintLine();
    if(isplayer)
    {
        std::cout << GetRandomCombatString() << std::endl;
        GraphicsManager::MilliWait(HALF_SECOND);
        GraphicsManager::NewLine();
        GraphicsManager::MilliWait(QUARTER_SECOND);
        std::cout << GetRandomCombatString() << std::endl;
        GraphicsManager::MilliWait(QUARTER_SECOND);
        GraphicsManager::NewLine();
        GraphicsManager::MilliWait(QUARTER_SECOND);
        std::cout << GetRandomCombatString() << std::endl;
        GraphicsManager::MilliWait(QUARTER_SECOND);
        std::cout << GetRandomCombatString() << std::endl;
        GraphicsManager::MilliWait(QUARTER_SECOND);
        GraphicsManager::NewLine();
        GraphicsManager::MilliWait(QUARTER_SECOND);
        GraphicsManager::NewLine();
        std::cout << " \"Whew!\"  " << std::endl; 
        GraphicsManager::NewLine();       
    }
    else
    {
        std::cout << " incoming!  " << std::endl;
        GraphicsManager::MilliWait(QUARTER_SECOND);
        GraphicsManager::NewLine();
        GraphicsManager::MilliWait(QUARTER_SECOND);
        std::cout << GetRandomCombatString() << std::endl;
        GraphicsManager::MilliWait(QUARTER_SECOND);
        GraphicsManager::NewLine();
        GraphicsManager::MilliWait(FULL_SECOND);
        std::cout << GetRandomCombatString() << std::endl;
        GraphicsManager::NewLine();
    }
    std::cout << attacker << " hit " << defender << " for " << dmg << "!" << std::endl;
    GraphicsManager::PrintLine();
    GraphicsManager::MilliWait(THREE_SECONDS);
    GraphicsManager::RefreshPage();
}


//TODO this should be somewhere else
std::string GraphicsManager::GetRandomCombatString()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);

    std::uniform_int_distribution<uint16_t> roller(0,9);

    std::string result = "invalid";

    int rand = roller(generator);

    switch (rand)
    {
    case 0:
        result = "Whack!";
        break;
    case 1:
        result = "Thud..";
        break;
    
    case 2:
        result = "..Thonk";
        break;
    
    case 3:
        result = "Slash!";
        break;

    case 4:
        result = "Woosh..";
        break;

    case 5:
        result = "..Donk!";
        break;


    case 6:
        result = "Whap!";
        break;


    case 7:
        result = "Stab.";
        break;

    case 8:
        result = "WOMP!!!";
        break;


    case 9:
        result = "BLAM!!!";
        break;
    default:
        break;
    }

    unsigned seed2 = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator2(seed2);
    std::uniform_int_distribution<uint16_t> roller2(0,15);
    int numSpaces = roller2(generator2);
    std::string space = "";
    for(int i = 0; i < numSpaces; i++)
        space += " ";

    return space + result;
}

void GraphicsManager::PrintGameOver()
{
    GraphicsManager::RefreshPage();
    GraphicsManager::PrintLine();
    GraphicsManager::NewLine();
    std::cout << "        GAME OVER" << std::endl;
    GraphicsManager::NewLine();
    GraphicsManager::PrintLine();
}