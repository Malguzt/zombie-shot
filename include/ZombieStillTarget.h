#ifndef ZOMBIESTILLTARGET_H
#define ZOMBIESTILLTARGET_H

#include <StillTarget.h>


class ZombieStillTarget : public StillTarget
{
    public:
        ZombieStillTarget(int x, int y, int difficulty, std::string fileName);
        virtual ~ZombieStillTarget();
        void runState(Target **target);
        virtual void checkTheShot(Vector2i &position, Board &board);
    protected:
    private:
};

#endif // ZOMBIESTILLTARGET_H
