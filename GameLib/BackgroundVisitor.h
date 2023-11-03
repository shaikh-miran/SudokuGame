/**
 * @file BackgroundVisitor.h
 * @author Miran
 *
 *
 */

#ifndef PROJECT1_GAMELIB_BACKGROUNDVISITOR_H
#define PROJECT1_GAMELIB_BACKGROUNDVISITOR_H

#include "Visitor.h" // Include the base Visitor class


/**
 * background visitor class, derives from class Visitor
 */
class BackgroundVisitor : public Visitor
{
private:
    /// member variable mBackground, background instance
    Background* mBackground = nullptr;



public:

    /// background getter
    Background* GetBackground() { return mBackground; }

    // Implement the Visit method for XRay
    void BackgroundVisit(Background* background) override
    {
        mBackground = background;
    }
};

#endif //PROJECT1_GAMELIB_BACKGROUNDVISITOR_H
