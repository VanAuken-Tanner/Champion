#pragma once

#include <string>
#include <vector>

#include "player.h"
#include "enemy.h"


enum BATTLEPHASE
{
    PLAYER,
    PSTATUS,
    ENEMY,
    ESTATUS,
    EXIT_BATTLE
};

enum COMMAND
{
    ATTACK,
    DEFEND,
    RUN,
    INVALID,
    END_GAME
};

//static BattleManager pBattleMan;

class BattleManager
{
public:
    void CreateBattle(Player &player, std::vector<Enemy>& enemies);

    bool ContinueBattle() {return currentPhase_ != BATTLEPHASE::EXIT_BATTLE;};
    int CommenceBattle();

    //Phase management
    BATTLEPHASE GetFirstTurn();
    void RoutePhase();
    void CheckEnemyStatus();
    void CheckPlayerStatus();

    //Enemy turn Functions
    void RunEnemyTurn();

    //Player turn functions
    void RunPlayerTurn();
    std::string GetCommandText(COMMAND index);
    COMMAND TranslateCommand(std::string input);
    int GetTargetOfAttack();
    void CommitCommand(COMMAND command);

    //Display Fuctions
    void PrintBattlerCreation();
    void PrintPlayerOptions();
    void DisplayPlayer();
    void DisplayEnemies();
    //info functions
    void DisplayEnemyProfiles(std::vector<Enemy>& vEnemies);



//this will likely be removed....
    void SetEndPhase() {currentPhase_ = BATTLEPHASE::EXIT_BATTLE;};

private:
    void UpdatePhase();
    BATTLEPHASE currentPhase_;
    Player* player_;
    std::vector<Enemy>* enemies_;
};