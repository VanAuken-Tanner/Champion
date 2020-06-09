#pragma once

#include "ECS.h"


class PositionComponent : public Component
{
private:
    int xpos_;
    int ypos_;

public:
    int X() {return xpos_;}
    int Y() {return ypos_;}

    PositionComponent(int x, int y)
    {
        xpos_ = x;
        ypos_ = y;
        std::cout << "player pos init at :" << xpos_ << "," << ypos_ << "..." <<std::endl;
    }

    // void Init() override
    // {
    //     xpos_ = 0;
    //     ypos_ = 0;
    // }

    void Update() override
    {
        // xpos_++;
        // ypos_++;
    }

    
    void SetPosition(int x, int y)
    {
        xpos_ = x;
        ypos_ = y;
    }

};