#include "textureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char * texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(Game::renderer_g, tempSurface);
    SDL_FreeSurface(tempSurface);

    return newTexture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect& src, SDL_Rect& dest)
{
    if(Game::renderer_g == nullptr)
        std::cout << "null renderer" << std::endl;

    SDL_RenderCopy(Game::renderer_g, texture, &src, &dest);
}