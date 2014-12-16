#ifndef APPEARINGTARGET_H
#define APPEARINGTARGET_H

#include <Target.h>
#include <string>


class AppearingTarget : public Target
{
    public:
        AppearingTarget(int x, int y, int difficulty);
        virtual ~AppearingTarget();
        void draw(RenderWindow &app);
        virtual void runActions(Target **target, Board &board) = 0;
    protected:
        std::string characterFileName;
        int step = 0;
    private:
};

#endif // APPEARINGTARGET_H
