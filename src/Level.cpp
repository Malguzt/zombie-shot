#include <time.h>
#include <iostream>
#include "Level.h"
#include "EmptyTarget.h"

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

    // Put the normal sight after a shot
    if(time(NULL) > (lastShot + 0.001))
    {
        sightTexture.loadFromFile("img/sight.png");
    }
}

void Level::runActions()
{
    difficulty += 0.001;
    std::cout << difficulty << std::endl;

    for (std::vector<Target*>::iterator it = targets.begin(); it != targets.end(); ++it)
    {
        (*it)->runActions(&(*it), board);
        (*it)->setDifficulty(difficulty);
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

    lastShot = time(NULL);
    sightTexture.loadFromFile("img/sight2.png");
}
