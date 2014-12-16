#include "EmptyTarget.h"
#include "HumanAppearingTarget.h"
#include "ZombieAppearingTarget.h"

EmptyTarget::EmptyTarget()
{
}

EmptyTarget::EmptyTarget(int x, int y, int difficulty)
{
    this->x = x;
    this->y = y;
    this->difficulty = difficulty;

    loadSprite();
}

EmptyTarget::~EmptyTarget()
{
    //dtor
}


void EmptyTarget::runActions(Target **target, Board &board)
{
    if(rand() % 10000 < difficulty)
    {
        if(rand() % 4)
        {
            *target = new ZombieAppearingTarget(x, y, difficulty);
        } else {
            *target = new HumanAppearingTarget(x, y, difficulty);
        }
        delete this;
    }
}
