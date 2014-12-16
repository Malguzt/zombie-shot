#ifndef HUMANDISAPPEARINGTARGET_H
#define HUMANDISAPPEARINGTARGET_H

#include <DisappearingTarget.h>


class HumanDisappearingTarget : public DisappearingTarget
{
    public:
        HumanDisappearingTarget(int x, int y, int difficulty, std::string fileName);
        virtual ~HumanDisappearingTarget();
    protected:
    private:
};

#endif // HUMANDISAPPEARINGTARGET_H
