#ifndef EMPTYTARGET_H
#define EMPTYTARGET_H

#include <Target.h>


class EmptyTarget : public Target
{
    public:
        EmptyTarget();
        EmptyTarget(int x, int y, int difficulty);
        virtual ~EmptyTarget();
        void runState(Target **target);
    protected:
    private:
};

#endif // EMPTYTARGET_H
