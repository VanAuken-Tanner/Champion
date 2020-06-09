#pragma once

#include "Component.h"
#include "SDL2/SDL.h"

class SpriteComponent : public Component
{
private:
    PositionComponent* position_;
    SDL_Texture *texture_;
    SDL_Rect srcRect_, destRect_;

public:

    SpriteComponent() = default;
    
    SpriteComponent(const char* filepath)
    {
        SetTexture(filepath);
    }

    void SetTexture(const char* filepath)
    {
        texture_ = TextureManager::LoadTexture(filepath);
    }

    void Init() override
    {
        position_ = &entity_->GetComponent<PositionComponent>();
        
        srcRect_.x = srcRect_.y = 0;
        destRect_.h = destRect_.w = 64;
        srcRect_.w = srcRect_.h = 32;

        
    }

    void Update() override
    {
        destRect_.x = position_->X();
        destRect_.y = position_->Y();
    }

    void Draw() override
    {
        TextureManager::Draw(texture_, srcRect_, destRect_);
    }
};
