#include "Level.h"
#include <EmptyTarget.h>

using namespace sf;

Level::Level()
{
    loadSprites();
    createBushes();
}

Level::~Level()
{
    //dtor
}

void Level::draw(RenderWindow &app)
{
    app.clear();

    if(board.getLives() > 0)
    {
        app.draw(backgroundSprite);

        for (std::vector<Target*>::iterator it = targets.begin(); it != targets.end(); ++it)
        {
            (*it)->draw(app);
        }

        sightSprite.setPosition(sightPosition.x - 20, sightPosition.y - 20);
        app.draw(sightSprite);

        board.draw(app);
    } else {
        board.drawTheEnd(app);
    }

    app.display();
}

void Level::runStates()
{
    for (std::vector<Target*>::iterator it = targets.begin(); it != targets.end(); ++it)
    {
        (*it)->runState(&(*it));
    }
}

void Level::loadSprites()
{
    backgroundTexture.loadFromFile("img/forest-background.png");
    backgroundSprite.setTexture(backgroundTexture);

    sightTexture.loadFromFile("img/sight.png");
    sightSprite.setTexture(sightTexture);
}

void Level::createBushes()
{
    bool zoneIsUsed;
    for(int i = 0; i < numberOfBushes; ++i)
    {
        targets.push_back(new EmptyTarget());
        zoneIsUsed = false;

        do {
            int j = 0;
            targets[i]->newPosition();
            zoneIsUsed = false;

            while(j < i && !zoneIsUsed)
            {
                zoneIsUsed = targets[j]->zoneIsUsed(*(targets[i]));
                ++j;
            }
        } while(zoneIsUsed);
    }
}

void Level::setSightPosition(Vector2i position)
{
    sightPosition = position;
}

void Level::checkTheShot(Vector2i position)
{
    for (std::vector<Target*>::iterator it = targets.begin(); it != targets.end(); ++it)
    {
        (*it)->checkTheShot(position, board);
    }
}
