#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Target.h"
#include "Board.h"

using namespace sf;


class Level
{
    public:
        Level();
        virtual ~Level();
        void draw(RenderWindow &app);
        void runActions();
        void setSightPosition(Vector2i position);
        void checkTheShot(Vector2i position);
    protected:
    private:
        time_t lastShot;
        Board board;
        void createBushes();
        void loadSprites();
        Vector2i sightPosition;
        Texture sightTexture;
        Sprite sightSprite;
        Texture backgroundTexture;
        Sprite backgroundSprite;
        int numberOfBushes = 20;
        std::vector<Target*> targets;

};

#endif // LEVEL_H
