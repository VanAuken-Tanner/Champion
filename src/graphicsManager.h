#pragma once
#include <string>

//static class for writing to the screen
class GraphicsManager
{
private:

    static const int screenwidth_g  = 40;
    static const int screenlength_g = 25;

    
public:
    static void Opening();
    static void RefreshPage();
    static void NewLine();
    static void PrintLine();
    static void MilliWait(int nanoSeconds);

    static void PrintCombat(bool success, bool isplayer, std::string attacker, std::string defender, int dmg);
    static std::string GetRandomCombatString();
    static void PrintGameOver();



};