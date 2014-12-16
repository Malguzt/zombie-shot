#ifndef ZOMBIESTILLTARGET_H
#define ZOMBIESTILLTARGET_H

#include <StillTarget.h>
#include <SFML/Graphics.hpp>


class ZombieStillTarget : public StillTarget
{
    public:
        ZombieStillTarget(int x, int y, int difficulty, std::string fileName);
        virtual ~ZombieStillTarget();
        void runActions(Target **target, Board &board);
        virtual void checkTheShot(Vector2i &position, Board &board);
        void draw(RenderWindow &app);
    protected:
    private:
        int biting = 1;
        Texture biteTexture;
        Sprite biteSprite;
};

#endif // ZOMBIESTILLTARGET_H
