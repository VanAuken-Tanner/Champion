#include "game.h"
#include "gameObject.h"    
#include "enemyGenerator.h"
#include "ECS.h"
#include "Component.h"

SDL_Renderer * Game::Game::renderer_g = nullptr;

Game::Game()
{

}

Game::~Game()
{

}

ComponentManager compManager;
auto& newPlayer(compManager.AddEntity());

void Game::Init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Init success..." << std::endl;

        window_ = SDL_CreateWindow(title.c_str(),xpos,ypos,width,height,fullscreen);
        
        if(window_)
        {
            std::cout << "Window created..." << std::endl;
        }

        Game::Game::renderer_g = SDL_CreateRenderer(window_, -1, 0);

        if(Game::Game::renderer_g)
        {
            SDL_SetRenderDrawColor(Game::Game::renderer_g, 255, 255, 255, 255);
            std::cout << "Renderer created..." << std::endl;
        }

        game_state_ = GAME_STATE::MENU;
    }
    else
    {
        game_state_ = GAME_STATE::END;
        std::cout << "SDL Failed to init everything...  err:" << SDL_GetError() << std::endl;

    }
    
    if(!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "SDL Image failed to init png...  err:" << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL Image success..." << std::endl;
    }

    //initing all the random shit
    //create our background
    pBackGround = TextureManager::LoadTexture("res/BasicBackground.png");
    pTextBox = TextureManager::LoadTexture("res/BattleMenu_Background.png");

    //create our player
    //player = new GameObject("res/Paladin.png", BP_P1_X, BP_P1_Y);
    // enemy1 = new GameObject("res/Skeleton.png", BP_E1_X, BP_E1_Y);
    // enemy2 = new GameObject("res/Skeleton.png", BP_E2_X, BP_E2_Y);
    // enemy3 = new GameObject("res/Skeleton.png", BP_E3_X, BP_E3_Y);

    newPlayer.AddComponent<PositionComponent>(BP_P1_X, BP_P1_Y);
    newPlayer.AddComponent<SpriteComponent>("res/Paladin.png");
}

void Game::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        game_state_ = GAME_STATE::END;
        break;
    case SDL_KEYDOWN:
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_RETURN:
            {
                if(game_state_ == GAME_STATE::MENU)
                    game_state_ = GAME_STATE::BATTLE;
            }
            break;
        
        default:
            break;
        }
    }
    break;
    default:
        break;
    }
}

void Game::Update()
{
    compManager.Refresh();
    compManager.Update();

    // switch (game_state_)
    // {
    // case GAME_STATE::MENU:
    //     {
            
    //     }
    //     break;
    // case GAME_STATE::BATTLE:
    //     {
    //         manager.Update();
    //         std::cout << newPlayer.GetComponent<PositionComponent>().X() << "," << newPlayer.GetComponent<PositionComponent>().Y() << std::endl;
    //         newPlayer->Update();
    //         enemy1->Update();
    //         enemy2->Update();
    //         enemy3->Update();
    //     }
    //     break;
    
    // default:
    //     break;
    // }
}

void Game::Render()
{
    SDL_RenderClear(Game::renderer_g);
    //for now always render the background.. first...
    SDL_RenderCopy(Game::renderer_g, pBackGround, NULL, NULL);

    compManager.Draw();
    
    // switch (game_state_)
    // {
    // case GAME_STATE::MENU:
    //     {
    //         SDL_Rect textRect;
    //         textRect.h = 100;
    //         textRect.w = 750;
    //         textRect.x = 25;
    //         textRect.y = 475;

    //         SDL_RenderCopy(Game::renderer_g, pTextBox, NULL, &textRect);
    //     }
    //     break;
    // case GAME_STATE::BATTLE:
    //     {
    //         player->Render();
    //         enemy1->Render();
    //         enemy2->Render();
    //         enemy3->Render();
    //     }
    //     break;
    // default:
    //     break;
    // }
    
    
    SDL_RenderPresent(Game::renderer_g);
}

void Game::Clean()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(Game::renderer_g);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}


