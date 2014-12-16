#include "ZombieStillTarget.h"
#include "ZombieDisappearingTarget.h"
#include "EmptyTarget.h"

using namespace sf;

ZombieStillTarget::ZombieStillTarget(int x, int y, int difficulty, std::string fileName)
: StillTarget::StillTarget(x, y, difficulty, fileName)
{
    biteTexture.loadFromFile("img/bite.png");
    biteSprite.setTexture(biteTexture);
    biteSprite.setPosition(x - 30, y);
}

ZombieStillTarget::~ZombieStillTarget()
{
}

void ZombieStillTarget::runActions(Target **target, Board &board)
{
    if(!isKilled(target))
    {
        if((rand() % 3000) < difficulty)
        {
            *target = new ZombieDisappearingTarget(x, y, difficulty, characterFileName);
            delete this;
        }
        biting++;

        int max = (int)(500 - difficulty);
        if(biting % max  == max - 1)
        {
            board.lostALive();
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

void ZombieStillTarget::draw(RenderWindow &app)
{

    unsigned long speed = (500 - difficulty);
    float biteCount = biting % speed;
    float biteSize =  biteCount / speed;

    Vector2f goalScale(biteSize, biteSize);
    Vector2f scale = biteSprite.getScale();

    scale += (goalScale - scale) / (float)2;

    biteSprite.setScale(scale);

    app.draw(bushSprite);
    app.draw(characterSprite);

    if(goalScale.x > 0.7)
    {
        app.draw(biteSprite);
    }
}
