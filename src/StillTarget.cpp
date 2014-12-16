#include "StillTarget.h"
#include "EmptyTarget.h"

using namespace sf;

StillTarget::StillTarget(int x, int y, int difficulty, std::string fileName)
{

    this->x = x;
    this->y = y;
    this->difficulty = difficulty;

    characterFileName = fileName;
    characterTexture.loadFromFile(characterFileName);
    characterSprite.setTexture(characterTexture);
    characterSprite.setPosition(x + 10, y + 30);
    characterSprite.setTextureRect(IntRect(40, 0, 40, 40));

    characterArea = IntRect(x + 10, y + 30, 40, 40);

    loadSprite();
}

StillTarget::~StillTarget()
{
}
