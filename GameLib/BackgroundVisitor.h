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

    /**
     * Getter for Background object
     * @return Background object
     */
    Background* GetBackground() { return mBackground; }

    /**
     * Background visit for accept function
     * @param background object
     */
    void BackgroundVisit(Background* background) override
    {
        mBackground = background;
    }
};

#endif //PROJECT1_GAMELIB_BACKGROUNDVISITOR_H
