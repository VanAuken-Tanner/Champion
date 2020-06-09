#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>

#include "textureManager.h"
#include "BATTLE_POS.h"


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

    static SDL_Renderer * renderer_g;

    GAME_STATE State() {return game_state_;};
private:
    GAME_STATE game_state_;
    SDL_Window *window_;

    //Textures
    SDL_Texture* pBackGround;
    SDL_Texture* pTextBox;  
};