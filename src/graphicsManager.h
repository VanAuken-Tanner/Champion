#pragma once
#include <string>

//static class for writing to the screen
class GraphicsManager
{
private:

    static const int screenwidth_g  = 40;
    static const int screenlength_g = 20;

    static void MilliWait(int nanoSeconds);
public:
    static void RefreshPage();
    static void NewLine();
    static void PrintLine();

    static void PrintCombat(bool success, bool isplayer, std::string attacker, std::string defender, int dmg);
    static std::string GetRandomCombatString();
    static void PrintGameOver();



};