/**
 * @file BackgroundVisitor.h
 * @author Miran
 *
 *
 */

#ifndef PROJECT1_GAMELIB_BACKGROUNDVISITOR_H
#define PROJECT1_GAMELIB_BACKGROUNDVISITOR_H

#include "Visitor.h" // Include the base Visitor class



class BackgroundVisitor : public Visitor
{
private:
    Background* mBackground = nullptr;



public:

    Background* GetBackground() { return mBackground; }

    // Implement the Visit method for XRay
    void BackgroundVisit(Background* background) override
    {
        mBackground = background;
    }
};

#endif //PROJECT1_GAMELIB_BACKGROUNDVISITOR_H
