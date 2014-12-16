#include "DisappearingTarget.h"
#include "EmptyTarget.h"
DisappearingTarget::DisappearingTarget(int x, int y, int difficulty, std::string fileName)
{
    characterFileName = fileName;
    characterTexture.loadFromFile(characterFileName);
    characterSprite.setTexture(characterTexture);
    characterSprite.setPosition(x + 10, y);

    characterArea = IntRect(x + 10, y + 30, 40, 40);

    this->x = x;
    this->y = y;
    this->difficulty = difficulty;

    loadSprite();
}

DisappearingTarget::~DisappearingTarget()
{
    //dtor
}

void DisappearingTarget::draw(RenderWindow &app)
{
    --step;

    int left =  (step - step % 20) * 2;
    characterSprite.setTextureRect(IntRect(left, 80, 40, 40));
    characterSprite.setPosition(x + 10, y + step / 2);
    shake();


    characterArea = IntRect(x + 10, y + step / 2, 40, 40);

    app.draw(bushSprite);
    app.draw(characterSprite);
}

void DisappearingTarget::runActions(Target **target, Board &board)
{
    if(step < 0)
    {
        *target = new EmptyTarget(x, y, difficulty);
        delete this;
    }
}
