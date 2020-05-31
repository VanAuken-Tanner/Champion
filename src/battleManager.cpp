#include <string>
#include <iostream>

#include "battleManager.h"
#include "graphicsManager.h"

void BattleManager::CreateBattle(Player &player, std::vector<Enemy> &enemies)
{
    player_ = &player;
    enemies_ = &enemies;
    
    //PrintBattlerCreation();
}

void BattleManager::PrintBattlerCreation()
{
    std::cout << "Battle created!" << std::endl;
    std::cout << "Player: " << player_->GetName() << std::endl;
    std::cout << "Num Enemies: " << enemies_->size() << std::endl;
}

int BattleManager::CommenceBattle()
{
    int battleResult = 0;

    currentPhase_ = GetFirstTurn();

    while(currentPhase_ != BATTLEPHASE::EXIT_BATTLE)
    {

        RoutePhase();       
    }

    return battleResult;
}

BATTLEPHASE BattleManager::GetFirstTurn()
{
    int highestEnemySpeed = 0;

    for (int i = 0; i < enemies_->size(); i++)
    {
        if (highestEnemySpeed < enemies_->at(i).GetSPD())
            highestEnemySpeed = enemies_->at(i).GetSPD();
    }

    if (player_->GetSPD() >= highestEnemySpeed)
        return BATTLEPHASE::PLAYER;

    return BATTLEPHASE::ENEMY;
}

void BattleManager::RoutePhase()
{
    switch (currentPhase_)
    {
    case BATTLEPHASE::PLAYER:
        RunPlayerTurn();
        break;

    case BATTLEPHASE::PSTATUS:
        CheckEnemyStatus();
        break;

    case BATTLEPHASE::ENEMY:
        RunEnemyTurn();
        break;

    case BATTLEPHASE::ESTATUS:
        CheckPlayerStatus();
        break;

    case BATTLEPHASE::EXIT_BATTLE:
        std::cout << "EXIT BATTLE!!!" << std::endl;
        break;

    default:
        break;
    }
}

void BattleManager::CheckEnemyStatus()
{
    for (int i = 0; i < enemies_->size(); i++)
    {
        if (!enemies_->at(i).IsAlive())
        {
            enemies_->erase(enemies_->begin() + i );
            i--;
        }
    }

    if(enemies_->size() > 0)
        currentPhase_ = BATTLEPHASE::ENEMY;
    else
    {    
        std::cout << "The player has defeated all of the enemies!!!" << std::endl;
        currentPhase_ = BATTLEPHASE::EXIT_BATTLE;   
    }
}

void BattleManager::CheckPlayerStatus()
{
    if (!player_->IsAlive())
    {
        GraphicsManager::PrintGameOver();
        currentPhase_ = BATTLEPHASE::EXIT_BATTLE;
        return;
    }
    currentPhase_ = BATTLEPHASE::PLAYER;
}

void BattleManager::RunEnemyTurn()
{
    for (int i = 0; i < enemies_->size(); i++)
    {
        int dmg = player_->TakeHit(enemies_->at(i).GetSTR());
        GraphicsManager::PrintCombat(true,false,enemies_->at(i).GetEnemyName(), player_->GetName(), dmg);
    }
    currentPhase_ = BATTLEPHASE::ESTATUS;
}

void BattleManager::RunPlayerTurn()
{
    DisplayPlayer();
    DisplayEnemies();
    PrintPlayerOptions();

    std::string input;
    std::cin >> input;

    COMMAND command = TranslateCommand(input);

    if (command == COMMAND::INVALID)
    {
        std::cout << "Please enter a valid command." << std::endl;
        RunPlayerTurn();
    }
    else
    {
        CommitCommand(command);        
    }
    
}

void BattleManager::PrintPlayerOptions()
{

   GraphicsManager::PrintLine();
    std::cout << "What would you like to do player?" << std::endl;
    std::cout << 1 << ": " << GetCommandText(COMMAND::ATTACK) << "." << std::endl;
    std::cout << 2 << ": " << GetCommandText(COMMAND::DEFEND) << "." << std::endl;
    std::cout << 3 << ": " << GetCommandText(COMMAND::RUN) << "." << std::endl;
   GraphicsManager::PrintLine();

}

std::string BattleManager::GetCommandText(COMMAND index)
{
    switch (index)
    {
    case COMMAND::ATTACK:
        return "Attack";
        break;
    case COMMAND::DEFEND:
        return "Defend";
        break;
    case COMMAND::RUN:
        return "Run Away";
        break;
    default:
        break;
    }

    return "invalid command index.";
}

int BattleManager::GetTargetOfAttack()
{
    std::cout << "Who will you attack?" << std::endl;
    std::string input;
    std::cin >> input;

    int tar = std::stoi(input);
    tar--;
    if(tar >= 0 && tar < enemies_->size())
        return tar;
    else
        return GetTargetOfAttack();
}

COMMAND BattleManager::TranslateCommand(std::string input)
{
    if (input.size() != 1)
        return COMMAND::INVALID;

    char inp = input[0];

    //input digit should match the enum order of commands + 1
    switch (inp)
    {
    case '1':
        return COMMAND::ATTACK;
        break;

    case '2':
        return COMMAND::DEFEND;
        break;

    case '3':
        return COMMAND::RUN;
        break;

    case 'X':
        return COMMAND::END_GAME;
    default:
        break;
    }

    return COMMAND::INVALID;
}

void BattleManager::CommitCommand(COMMAND command)
{
    switch (command)
    {
    case COMMAND::ATTACK:
    {
        int enemyIndex = GetTargetOfAttack();
        int dmgDealt = enemies_->at(enemyIndex).TakeHit(player_->GetSTR());
        GraphicsManager::PrintCombat(true, true,player_->GetName(), enemies_->at(enemyIndex).GetEnemyName(), dmgDealt);
        currentPhase_ = BATTLEPHASE::PSTATUS;
        break;
    }       
    case COMMAND::DEFEND:
        std::cout << "player defended." << std::endl;
        currentPhase_ = BATTLEPHASE::PSTATUS;
        break;
    case COMMAND::RUN:
        std::cout << "player ran away." << std::endl;
        currentPhase_ = BATTLEPHASE::EXIT_BATTLE;
        break;
        
    case COMMAND::END_GAME:
        std::cout << "player tried to end game." << std::endl;
        currentPhase_ = BATTLEPHASE::EXIT_BATTLE;
        break;
        
    }
}
//main display for player
void BattleManager::DisplayPlayer()
{
    GraphicsManager::PrintLine();
    std::cout << player_->GetName() << "(" << player_->GetRoleName() << "):" << std::endl;
    std::cout << "HP(" << player_->GetCurrentHP() << "/" << player_->GetMaxHP() << ")" << std::endl;
    GraphicsManager::PrintLine();
}

//main dislpay for enemies
void BattleManager::DisplayEnemies()
{
    std::cout << "ENEMIES:" << std::endl;
    for(int i = 0; i < enemies_->size(); i++)
    {
        Enemy* pEnemy = &enemies_->at(i);
        std::cout << i + 1 << ": " << pEnemy->GetEnemyName();
        std::cout << " - HP(" << pEnemy->GetCurrentHP() << "/" << pEnemy->GetMaxHP() << ")" << std::endl;
    }
}

void BattleManager::DisplayEnemyProfiles(std::vector<Enemy>& vEnemies)
{
    for(Enemy enemy: vEnemies)
        enemy.printProfile();
}



















