#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>

#include "textureManager.h"

enum GAME_STATE
{
    MENU,
    ADVENTURE,
    BATTLE,
    END

};

class Game
{
public:
    Game();
    ~Game();


    void Init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();

    GAME_STATE State() {return game_state_;};
private:
    GAME_STATE game_state_;

    int count_;

    SDL_Window *window_;
    SDL_Renderer *renderer_;


    //Textures
    SDL_Texture* pBackGround;
    SDL_Texture* pPlayerTexture;
    
};