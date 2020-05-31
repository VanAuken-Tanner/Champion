#include "dice.h"

Dice* Dice::mainDice = nullptr;

Dice::Dice()
{
    seed_ = std::chrono::system_clock::now().time_since_epoch().count();
    generator_p = new std::mt19937(seed_);
}

Dice::~Dice()
{
    if(generator_p)
        delete generator_p;
}

int Dice::Roll(int min, int max)
{
    std::uniform_int_distribution<uint16_t> roller(min, max);
    return roller(*generator_p);
}

Dice* Dice::GetDice()
{
    if(mainDice == nullptr)
        mainDice = new Dice();
    
    return mainDice;
}
