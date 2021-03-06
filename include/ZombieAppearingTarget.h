#ifndef ZOMBIEAPPEARINGTARGET_H
#define ZOMBIEAPPEARINGTARGET_H

#include <AppearingTarget.h>


class ZombieAppearingTarget : public AppearingTarget
{
    public:
        ZombieAppearingTarget(int x, int y, int difficulty);
        virtual ~ZombieAppearingTarget();
        void runActions(Target **target, Board &board);
        void checkTheShot(Vector2i &position, Board &board);
    protected:
    private:
};

#endif // ZOMBIEAPPEARINGTARGET_H
