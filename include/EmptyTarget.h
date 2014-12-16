#ifndef EMPTYTARGET_H
#define EMPTYTARGET_H

#include <Target.h>


class EmptyTarget : public Target
{
    public:
        EmptyTarget();
        EmptyTarget(int x, int y, int difficulty);
        virtual ~EmptyTarget();
        void runActions(Target **target, Board &board);
    protected:
    private:
};

#endif // EMPTYTARGET_H
