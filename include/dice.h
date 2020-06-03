#pragma once

#include <chrono>
#include <random>

class Dice
{
private:
    Dice();
    ~Dice();
    static Dice* mainDice;

    unsigned seed_;
    std::mt19937* generator_p;

public:
    static Dice* GetDice();


    int Roll(int min, int max);
};


