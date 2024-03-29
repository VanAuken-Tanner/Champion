#pragma once

#include "game.h"


class TextureManager
{

public:
    static SDL_Texture* LoadTexture(const char* texture);
    static void Draw(SDL_Texture* texture, SDL_Rect& src, SDL_Rect& dest);
};