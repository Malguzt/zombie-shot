#ifndef ZOMBIEDISAPPEARINGTARGET_H
#define ZOMBIEDISAPPEARINGTARGET_H

#include <DisappearingTarget.h>


class ZombieDisappearingTarget : public DisappearingTarget
{
    public:
        ZombieDisappearingTarget(int x, int y, int difficulty, std::string fileName);
        virtual ~ZombieDisappearingTarget();
    protected:
    private:
};

#endif // ZOMBIEDISAPPEARINGTARGET_H
