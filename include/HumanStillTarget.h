#ifndef HUMANSTILLTARGET_H
#define HUMANSTILLTARGET_H

#include <StillTarget.h>


class HumanStillTarget : public StillTarget
{
    public:
        HumanStillTarget(int x, int y, int difficulty, std::string fileName);
        virtual ~HumanStillTarget();
        void runActions(Target **target, Board &board);
        virtual void checkTheShot(Vector2i &position, Board &board);
    protected:
    private:
};

#endif // HUMANSTILLTARGET_H
