#include "player.h"
#include "dice.h"
#include <iostream>
#include <string>

Player::Player()
{
    InitPlayer();
}

void Player::InitPlayer()
{
    name_ = GetNewName();
    class_ = GetPlayerClass();

    switch (class_)
    {
        case CLASS::THIEF:
        {
            hpmax_ = hpcur_ =   THIEF_BASE_HP;
            strength_ =         THIEF_BASE_STR;
            defense_ =          THIEF_BASE_DEF;
            agility_ =          THIEF_BASE_AGI;
            willpower_ =        THIEF_BASE_WIL;
            speed_ =            THIEF_BASE_SPD;
            luck_ =             THIEF_BASE_LCK;
            break;
        }
        case CLASS::ARCHER:
        {
            hpmax_ = hpcur_ =   ARCHER_BASE_HP;
            strength_ =         ARCHER_BASE_STR;
            defense_ =          ARCHER_BASE_DEF;
            agility_ =          ARCHER_BASE_AGI;
            willpower_ =        ARCHER_BASE_WIL;
            speed_ =            ARCHER_BASE_SPD;
            luck_ =             ARCHER_BASE_LCK;
            break;
        }
        case CLASS::SORCERER:
        {
            hpmax_ = hpcur_ =   SORCERER_BASE_HP;
            strength_ =         SORCERER_BASE_STR;
            defense_ =          SORCERER_BASE_DEF;
            agility_ =          SORCERER_BASE_AGI;
            willpower_ =        SORCERER_BASE_WIL;
            speed_ =            SORCERER_BASE_SPD;
            luck_ =             SORCERER_BASE_LCK;
            break;
        }
        case CLASS::MAGE:
        {
            hpmax_ = hpcur_ =   MAGE_BASE_HP;
            strength_ =         MAGE_BASE_STR;
            defense_ =          MAGE_BASE_DEF;
            agility_ =          MAGE_BASE_AGI;
            willpower_ =        MAGE_BASE_WIL;
            speed_ =            MAGE_BASE_SPD;
            luck_ =             MAGE_BASE_LCK;
            break;
        }
        case CLASS::KNIGHT:
        {
            hpmax_ = hpcur_ =   KNIGHT_BASE_HP;
            strength_ =         KNIGHT_BASE_STR;
            defense_ =          KNIGHT_BASE_DEF;
            agility_ =          KNIGHT_BASE_AGI;
            willpower_ =        KNIGHT_BASE_WIL;
            speed_ =            KNIGHT_BASE_SPD;
            luck_ =             KNIGHT_BASE_LCK;
            break;
        }
        case CLASS::BARBARIAN:
        {
            hpmax_ = hpcur_ =   BARBARIAN_BASE_HP;
            strength_ =         BARBARIAN_BASE_STR;
            defense_ =          BARBARIAN_BASE_DEF;
            agility_ =          BARBARIAN_BASE_AGI;
            willpower_ =        BARBARIAN_BASE_WIL;
            speed_ =            BARBARIAN_BASE_SPD;
            luck_ =             BARBARIAN_BASE_LCK;
            break;
        }
        case CLASS::PEASANT:
        {
            hpmax_ = hpcur_ =   PEASANT_BASE_HP;
            strength_ =         PEASANT_BASE_STR;
            defense_ =          PEASANT_BASE_DEF;
            agility_ =          PEASANT_BASE_AGI;
            willpower_ =        PEASANT_BASE_WIL;
            speed_ =            PEASANT_BASE_SPD;
            luck_ =             PEASANT_BASE_LCK;
            break;
        }
        case CLASS::GOD:
        {
            hpmax_ = hpcur_ =   GOD_BASE_HP;
            strength_ =         GOD_BASE_STR;
            defense_ =          GOD_BASE_DEF;
            agility_ =          GOD_BASE_AGI;
            willpower_ =        GOD_BASE_WIL;
            speed_ =            GOD_BASE_SPD;
            luck_ =             GOD_BASE_LCK;
            break;
        }
    }
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
    msg = "It was destiny that we meet here, " + input + ".";

    if (GetAnswer(msg, "Agreed.", "Wait. That's not me."))
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

CLASS Player::GetPlayerClass()
{

    CLASS chosen = CLASS::PEASANT;

    if (GetAnswer("Guide me in determining your strengths.", "[nod]", "Wait..."))
    {
        //if broke:peasant or a thief or an archer
        if (GetAnswer("Were you born alone on the streets with nothing to call your own?", "I have been alone for as long as I can remember.", "I was raised in a loving home, with a loving mother and father."))
        {
            if (GetAnswer("Where was it that you grew, learning to survive?", "The streets is where I learned that it was I alone who could help me.", "The forest has taught me that all is here for one another."))
                chosen = CLASS::THIEF;
            else
                chosen = CLASS::ARCHER;

        } //else if magical:sorcerer or wizard
        else if (GetAnswer("Is it your might or mind that has lead you here?", "Mind.", "Might"))
        {
            if (GetAnswer("Do you feel the aether run through your veins?", "Ever since I was young I have fealt the presence of the aether.", "It has been through studying that I have attuned my soul the aether."))
                chosen = CLASS::SORCERER;
            else
                chosen = CLASS::MAGE;
        }
        else //not magical
        {
            if (GetAnswer("From where has your inner flame been kindled?", "On the field of battle with blood dripping over the weak!", "With sword in hand I have trained from dusk to dawn honing my blade."))
                chosen = CLASS::BARBARIAN;
            else
                chosen = CLASS::KNIGHT;
        }
    }
    else
    {
        if (GetAnswer("Excuse me?", "Sorry, Yes.", "I said No."))
            chosen = GetPlayerClass();
        else
        {
            if (GetAnswer("Well then what are you waiting for?", "Nothing, I have been empty and alone for ever and that will not change.", "I am a God and my power is unmatched by all. So move peasant and let me be on with it already!"))
                chosen = CLASS::PEASANT;
            else
                chosen = CLASS::GOD;
        }
    }

    std::string confirmMsg;

    switch (chosen)
    {
    case CLASS::THIEF:
        confirmMsg = "Are you happy as a Thief?";
        break;
    case CLASS::ARCHER:
        confirmMsg = "Are you happy as an Archer?";
        break;
    case CLASS::SORCERER:
        confirmMsg = "Are you happy as a Sorcerer?";
        break;
    case CLASS::MAGE:
        confirmMsg = "Are you happy as a Mage?";
        break;
    case CLASS::KNIGHT:
        confirmMsg = "Are you happy as a Knight?";
        break;
    case CLASS::BARBARIAN:
        confirmMsg = "Are you happy as a Barbarian?";
        break;
    case CLASS::PEASANT:
        confirmMsg = "Are you happy as a Peasant?";
        break;
    case CLASS::GOD:
        confirmMsg = "Well your a fucking god, so im sure ur fine with that eh dick head?";
        break;
    }

    if (GetAnswer(confirmMsg, "Yes.", "No."))
        return chosen;

    return GetPlayerClass();
}

std::string Player::GetRoleName()
{
    std::string ret = "";

    switch (class_)
    {
    case CLASS::THIEF:
        ret = "Thief";
        break;
    case CLASS::ARCHER:
        ret = "Archer";
        break;
    case CLASS::SORCERER:
        ret = "Sorcerer";
        break;
    case CLASS::MAGE:
        ret = "Mage";
        break;
    case CLASS::KNIGHT:
        ret = "Knight";
        break;
    case CLASS::BARBARIAN:
        ret = "Barbarian";
        break;
    case CLASS::PEASANT:
        ret = "Peasant";
        break;
    case CLASS::GOD:
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



//ABILITIES

int Player::Attack()
{
    int potency = 0;

    switch (class_)
    {
    case CLASS::THIEF:
    case CLASS::ARCHER:
        potency = agility_;
        break;
    case CLASS::SORCERER:
    case CLASS::MAGE:
        potency = willpower_;
        break;
    case CLASS::KNIGHT:
    case CLASS::BARBARIAN:
    case CLASS::PEASANT:
    case CLASS::GOD:
        potency = strength_;
    }
    state_ = STATE::ATTACKING;
    return potency;
}

int Player::GetAttacked(int dmg)
{
    //how lucky are we
    int luckRoll = Dice::GetDice()->Roll(1,100);
    int ChanceToGetHit = 100 - luck_;
    if(luckRoll > ChanceToGetHit)
    {
        std::cout << "someone got lucky!" << std::endl;
        return 0;
    }

    if(state_ == STATE::DEFENDING)
        dmg = dmg / 2;

    
    int defensiveValue = 0;

    switch (class_)
    {
    case CLASS::THIEF:
    case CLASS::ARCHER:
        defensiveValue = speed_/2;
        break;
    case CLASS::SORCERER:
    case CLASS::MAGE:
        defensiveValue = agility_/2;
        break;
    case CLASS::KNIGHT:
    case CLASS::BARBARIAN:
    case CLASS::PEASANT:
    case CLASS::GOD:
        defensiveValue = defense_/2;
    }

    dmg -= defensiveValue;

    if(dmg < 1)
        dmg = 1;

    return Character::TakeHit(dmg);
}