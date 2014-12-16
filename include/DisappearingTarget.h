#ifndef DISAPPEARINGTARGET_H
#define DISAPPEARINGTARGET_H

#include <Target.h>
#include <string>

class DisappearingTarget : public Target
{
    public:
        DisappearingTarget(int x, int y, int difficulty, std::string fileName);
        virtual ~DisappearingTarget();
        void draw(RenderWindow &app);
        void runActions(Target **target, Board &board);
    protected:
    private:
        int step = 60;
        std::string characterFileName;
};

#endif // DISAPPEARINGTARGET_H
