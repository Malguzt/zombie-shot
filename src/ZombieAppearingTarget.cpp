#include "ZombieAppearingTarget.h"
#include "ZombieStillTarget.h"

ZombieAppearingTarget::ZombieAppearingTarget(int x, int y, int difficulty)
: AppearingTarget(x, y, difficulty)
{
    characterFileName = "img/zombie-00.png";
    characterFileName[12] = rand() % 6 + '1';

    characterTexture.loadFromFile(characterFileName);
    characterSprite.setTexture(characterTexture);
    characterSprite.setPosition(x + 10, y);
}

ZombieAppearingTarget::~ZombieAppearingTarget()
{
}

void ZombieAppearingTarget::runActions(Target **target, Board &board)
{
    if(!isKilled(target))
    {
        if(step > 60)
        {
            *target = new ZombieStillTarget(x, y, difficulty, characterFileName);
            delete this;
        }
    }
}

void ZombieAppearingTarget::checkTheShot(Vector2i &position, Board &board)
{
    if(characterArea.contains(position))
    {
        board.addPoints(10);
        killed = true;
    }
}
