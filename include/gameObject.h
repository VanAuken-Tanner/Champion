#pragma once

#include "game.h"

class GameObject
{
public:
    GameObject(const char* texture, int xpos, int ypos);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos_;
    int ypos_;

    SDL_Texture* objTexture_;
    SDL_Rect srcRect_, destRect_;
};