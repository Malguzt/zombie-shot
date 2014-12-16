#include "ZombieStillTarget.h"
#include "ZombieDisappearingTarget.h"
#include "EmptyTarget.h"

ZombieStillTarget::ZombieStillTarget(int x, int y, int difficulty, std::string fileName)
: StillTarget::StillTarget(x, y, difficulty, fileName)
{
}

ZombieStillTarget::~ZombieStillTarget()
{
    //dtor
}

void ZombieStillTarget::runState(Target **target)
{
    if(!isKilled(target))
    {
        if((rand() % 3000) < difficulty)
        {
            *target = new ZombieDisappearingTarget(x, y, difficulty, characterFileName);
            delete this;
        }
    }
}

void ZombieStillTarget::checkTheShot(Vector2i &position, Board &board)
{
    if(characterArea.contains(position))
    {
        board.addPoints(10);
        killed = true;
    }
}
