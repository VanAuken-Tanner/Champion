#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>


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

    bool Running() {return isRunning_;};

private:
    bool isRunning_;

    int count_;

    SDL_Window *window_;
    SDL_Renderer *renderer_;


};