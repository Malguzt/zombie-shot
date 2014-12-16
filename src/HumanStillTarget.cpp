#include "HumanStillTarget.h"
#include "HumanDisappearingTarget.h"
#include "EmptyTarget.h"

using namespace sf;

HumanStillTarget::HumanStillTarget(int x, int y, int difficulty, std::string fileName)
: StillTarget::StillTarget(x, y, difficulty, fileName)
{
}

HumanStillTarget::~HumanStillTarget()
{
}

void HumanStillTarget::runState(Target **target)
{
    if(!isKilled(target))
    {
        if((rand() % 1000) < difficulty)
        {
            *target = new HumanDisappearingTarget(x, y, difficulty, characterFileName);
            delete this;
        }
    }
}

void HumanStillTarget::checkTheShot(Vector2i &position, Board &board)
{
    if(characterArea.contains(position))
    {
        board.lostALive();
        board.addPoints(-10);
        killed = true;
    }
}
