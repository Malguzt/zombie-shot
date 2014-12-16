#ifndef STILLTARGET_H
#define STILLTARGET_H

#include <Target.h>
#include <string>


class StillTarget : public Target
{
    public:
        StillTarget(int x, int y, int difficulty, std::string fileName);
        virtual ~StillTarget();
        virtual void runState(Target **target) = 0;
    protected:
        std::string characterFileName;
    private:
};

#endif // STILLTARGET_H
