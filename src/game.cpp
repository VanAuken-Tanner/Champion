#include "game.h"


SDL_Rect srcRect,destRect;
    

Game::Game()
{

}

Game::~Game()
{

}


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

        renderer_ = SDL_CreateRenderer(window_, -1, 0);

        if(renderer_)
        {
            SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
            std::cout << "Renderer created..." << std::endl;

            
            //create our background
            pBackGround = TextureManager::LoadTexture("res/BasicBackground.png", renderer_);
            //create our player
            pPlayerTexture = TextureManager::LoadTexture("res/Paladin.png", renderer_);

            srcRect.h = 32;
            srcRect.w = 32;
            destRect.h = 64;
            destRect.w = 64;
            destRect.x = 100;
            destRect.y = 100;
        }

        game_state_ = GAME_STATE::MENU;
        count_ = 0;

         
        
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
    
    default:
        break;
    }
}

void Game::Update()
{
    
    count_++;
    //std::cout << count_ << std::endl;
}

void Game::Render()
{
    SDL_RenderClear(renderer_);
    SDL_RenderCopy(renderer_, pBackGround, NULL, NULL);
    SDL_RenderCopy(renderer_, pPlayerTexture, &srcRect, &destRect);
    SDL_RenderPresent(renderer_);
}

void Game::Clean()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}


