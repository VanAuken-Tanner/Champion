#include "player.h"

#include <iostream>
#include <string>

Player::Player()
{
    InitPlayer();
}

void Player::InitPlayer()
{
    name_ = GetNewName();
    role_ = GetPlayerClass();
    hpmax_ = hpcur_ = 100;
    strength_ = 20;
    speed_ = 20;
    
}

std::string Player::GetNewName()
{
    for (int i = 0; i < 25; i++)
        std::cout << std::endl;

    std::cout << "========================================" << std::endl;
    std::cout << "What is your name?" << std::endl;
    std::cout << "========================================" << std::endl;
    std::string input;
    std::cin >> input;

    std::string msg;
    msg = "Are you sure " + input + "?";

    if(GetAnswer(msg, "Yes.", "No."))
        return input;

    return GetNewName();
}

//true = opt 1, false = opt 2
bool Player::GetAnswer(std::string msg, std::string opt1, std::string opt2)
{
    for (int i = 0; i < 25; i++)
        std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1: " << opt1 << std::endl;
    std::cout << "2: " << opt2 << std::endl;
    std::cout << "========================================" << std::endl;

    std::string input;
    std::cin >> input;

    if (input == "1")
        return true;
    else if (input == "2")
        return false;

    std::cout << "please enter \"1\" or \"2\"." << std::endl;
    return GetAnswer(msg, opt1, opt2);
}

ROLE Player::GetPlayerClass()
{

    ROLE chosen = ROLE::PEASANT;

    if(GetAnswer("Then let us begin... " + name_ + "?", "[nod]", "Wait..."))
    {
        //if broke:peasant or a thief or an archer
        if(GetAnswer("Were you born alone on the streets with nothing to call your own?", "I have been alone for as long as I can remember.", "I was raised in a loving home, with a loving mother and father."))
        {
            if(GetAnswer("Where was it that you grew, learning to survive?", "The streets is where I learned that it was I alone who could help me.", "The forest has taught me that all is here for one another."))
                chosen =  ROLE::THIEF;
            else
                chosen = ROLE::ARCHER;
            
        } //else if magical:sorcerer or wizard
        else if(GetAnswer("Is it your might or mind that has lead you here?", "Mind.", "Might"))
        {
            if(GetAnswer("Do you feel the aether run through your veins?", "Ever since I was young I have fealt the presence of the aether.", "It has been through studying that I have attuned my soul the aether."))
                chosen = ROLE::SORCERER;
            else
                chosen = ROLE::MAGE;
        } else//not magical
        {
            if(GetAnswer("From where has your inner flame been kindled?", "On the field of battle with blood dripping over the weak!", "With sword in hand I have trained from dusk to dawn honing my blade."))
                chosen = ROLE::BARBARIAN;
            else
                chosen = ROLE::WARRIOR;
            
        }
    }
    else
    {
        if(GetAnswer("Excuse me?", "Sorry, Yes.", "I said No."))
            chosen = GetPlayerClass();
        else
        {
            if(GetAnswer("Well then what are you waiting for?", "Nothing, I have been empty and alone for ever and that will not change.", "I am a God and my power is unmatched by all. So move peasant and let me be on with it already!"))
                chosen = ROLE::PEASANT;
            else
                chosen = ROLE::GOD;
            
        }
        
    }
    

    std::string confirmMsg;

    switch (chosen)
    {
    case ROLE::THIEF:
        confirmMsg = "Are you happy as a Thief?";
        break;
    case ROLE::ARCHER:
        confirmMsg = "Are you happy as an Archer?";
        break;
    case ROLE::SORCERER:
        confirmMsg = "Are you happy as a Sorcerer?";
        break;
    case ROLE::MAGE:
        confirmMsg = "Are you happy as a Mage?";
        break;
    case ROLE::WARRIOR:
        confirmMsg = "Are you happy as a Warrior?";
        break;
    case ROLE::BARBARIAN:
        confirmMsg = "Are you happy as a Barbarian?";
        break;
    case ROLE::PEASANT:
        confirmMsg = "Are you happy as a Peasant?";
        break;
    case ROLE::GOD:
        confirmMsg = "Well your a fucking god, so im sure ur fine with that eh dick head?";
        break;
    }
    
    if(GetAnswer(confirmMsg, "Yes.", "No."))
        return chosen;
    
    return GetPlayerClass();
    
}

std::string Player::GetRoleName()
{
    std::string ret = "";

    switch (role_)
    {
    case ROLE::THIEF:
        ret = "Thief";
        break;
    case ROLE::ARCHER:
        ret = "Archer";
        break;
    case ROLE::SORCERER:
        ret = "Sorcerer";
        break;
    case ROLE::MAGE:
        ret = "Mage";
        break;
    case ROLE::WARRIOR:
        ret = "Warrior";
        break;
    case ROLE::BARBARIAN:
        ret = "Barbarian";
        break;
    case ROLE::PEASANT:
        ret = "Peasant";
        break;
    case ROLE::GOD:
        ret = "GOD";
        break;
    }

    return ret;
}

void Player::printProfile()
{
    std::cout << name_ << std::endl;
    Character::printProfile();
}