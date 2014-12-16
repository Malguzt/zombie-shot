#ifndef HUMANAPPEARINGTARGET_H
#define HUMANAPPEARINGTARGET_H

#include <AppearingTarget.h>


class HumanAppearingTarget : public AppearingTarget
{
    public:
        HumanAppearingTarget(int x, int y, int difficulty);
        virtual ~HumanAppearingTarget();
        void runState(Target **target);
        void checkTheShot(Vector2i &position, Board &board);
    protected:
    private:
};

#endif // HUMANAPPEARINGTARGET_H
