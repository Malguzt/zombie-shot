#ifndef TARGET_H
#define TARGET_H

#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace sf;

class Target
{
    public:
        Target();
        Target(int x, int y, int difficulty);
        virtual ~Target();
        virtual void draw(RenderWindow &app);
        virtual void runState(Target **target) = 0;
        virtual void checkTheShot(Vector2i &position, Board &board);
        void newPosition();
        bool zoneIsUsed(Target &otherTarget);
        int getX();
        int getY();
    protected:
        bool isKilled(Target **target);
        void shake();
        int x;
        int y;
        int difficulty;
        void loadSprite();
        Sprite bushSprite;
        Texture characterTexture;
        Sprite characterSprite;
        IntRect bushArea;
        IntRect characterArea;
        bool killed = false;
    private:
        Texture bushTexture;
};

#endif // TARGET_H
