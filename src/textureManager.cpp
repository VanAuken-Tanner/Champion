#include "textureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char * texture, SDL_Renderer* ren)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);

    if(newTexture == nullptr)
        std::cout << "texture null - " << texture << std::endl;

    return newTexture;
}