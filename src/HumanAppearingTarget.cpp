#include "HumanAppearingTarget.h"
#include "HumanStillTarget.h"

HumanAppearingTarget::HumanAppearingTarget(int x, int y, int difficulty)
: AppearingTarget(x, y, difficulty)
{
    characterFileName = "img/human-00.png";
    characterFileName[11] = rand() % 8 + '1';

    characterTexture.loadFromFile(characterFileName);
    characterSprite.setTexture(characterTexture);
    characterSprite.setPosition(x + 10, y);
}

HumanAppearingTarget::~HumanAppearingTarget()
{
}

void HumanAppearingTarget::runState(Target **target)
{
    if(!isKilled(target))
    {
        if(step > 60)
        {
            *target = new HumanStillTarget(x, y, difficulty, characterFileName);
            delete this;
        }
    }
}

void HumanAppearingTarget::checkTheShot(Vector2i &position, Board &board)
{
    if(characterArea.contains(position))
    {
        board.lostALive();
        board.addPoints(-10);
        killed = true;
    }
}
