#include "EmptyTarget.h"
#include "HumanAppearingTarget.h"
#include "ZombieAppearingTarget.h"

EmptyTarget::EmptyTarget()
{
    difficulty = 2;
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


void EmptyTarget::runState(Target **target)
{
    int a = rand() % 1000;
    if(a < difficulty)
    {
        if(a % 2)
        {
            *target = new HumanAppearingTarget(x, y, difficulty);
        } else {
            *target = new ZombieAppearingTarget(x, y, difficulty);
        }
        delete this;
    }
}
