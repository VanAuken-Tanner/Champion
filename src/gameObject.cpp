#include "gameObject.h"
#include "textureManager.h"


GameObject::GameObject(const char* texture, int xpos, int ypos)
{
    objTexture_ = TextureManager::LoadTexture(texture);
    xpos_ = xpos;
    ypos_ = ypos; 
}

void GameObject::Update()
{
    srcRect_.h = 64;
    srcRect_.w = 64;
    srcRect_.x = 0;
    srcRect_.y = 0;

    destRect_.x = xpos_;
    destRect_.y = ypos_;
    destRect_.h = srcRect_.h;
    destRect_.w = srcRect_.w;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer_g ,objTexture_, &srcRect_, &destRect_);
}