#include "Target.h"
#include "EmptyTarget.h"
using namespace sf;

Target::Target()
{
    loadSprite();

    newPosition();
}

Target::Target(int x, int y, int difficulty)
{
    this->x = x;
    this->y = y;
    setDifficulty(difficulty);

    bushArea = IntRect(x, y, 63, 63);

    loadSprite();
}

Target::~Target()
{
}

void Target::loadSprite()
{
    bushTexture.loadFromFile("img/bush.png");
    bushSprite.setTexture(bushTexture);
    bushSprite.setPosition(x, y);
}

void Target::draw(RenderWindow &app)
{
    app.draw(bushSprite);
    app.draw(characterSprite);
}

void Target::shake()
{
    bushSprite.setPosition(x + (-4 + rand() % 9), y);
}

void Target::checkTheShot(Vector2i &position, Board &board)
{
}

void Target::newPosition()
{

    x = rand() % 700;
    y = rand() % 300 + 200;

    bushSprite.setPosition(x, y);
    bushArea = IntRect(x, y, 63, 63);
}

bool Target::zoneIsUsed(Target &otherTarget)
{

    return bushArea.intersects(otherTarget.bushArea);
}

int Target::getX()
{
    return x;
}

int Target::getY()
{
    return y;
}

bool Target::isKilled(Target **target)
{
    if(killed)
    {
        *target = new EmptyTarget(x, y, difficulty);
        delete this;

        return true;
    }

    return false;
}

void Target::setDifficulty(int value)
{
    if(value > 0)
    {
        difficulty = value;
    } else {
        difficulty = 1;
    }
}
