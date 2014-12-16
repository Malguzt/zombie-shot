#include "AppearingTarget.h"
#include "StillTarget.h"
using namespace sf;

AppearingTarget::AppearingTarget(int x, int y, int difficulty)
{
    this->x = x;
    this->y = y;
    this->difficulty = difficulty;

    characterArea = IntRect(x + 10, y, 40, 40);

    loadSprite();
}

AppearingTarget::~AppearingTarget()
{
    //dtor
}

void AppearingTarget::draw(RenderWindow &app)
{
    ++step;

    int left =  (step - step % 20) * 2;
    characterSprite.setTextureRect(IntRect(left, 0, 40, 40));
    characterSprite.setPosition(x + 10, y + step / 2);
    shake();

    characterArea = IntRect(x + 10, y + step / 2, 40, 40);

    app.draw(bushSprite);
    app.draw(characterSprite);
}
