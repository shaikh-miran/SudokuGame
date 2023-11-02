/**
 * @file ContainerVisitor.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_CONTAINERVISITOR_H
#define PROJECT1_GAMELIB_CONTAINERVISITOR_H

#include <cmath>
#include "Visitor.h"
#include "ItemContainer.h"

/**
 * container visitor class, derived from class Visitor
 */
class ContainerVisitor : public Visitor
{
private:
    /// member variables sparty center x , sparty centre y,
    double mSpartyCenterX, mSpartyCenterY;

    /// member variables mX, mY
    double mX, mY;

    /// item container instance
    ItemContainer* mContainer = nullptr;

public:

    /// function to visit item container
    void ContainerVisit(ItemContainer* container);

    /// getter for mX
    double GetX() {return mX;}

    /// getter for mY
    double GetY() {return mY;}

    /// setter for sparty location x, y coordinates
    void SetSpartyLocation(double x, double y) {mSpartyCenterX = x; mSpartyCenterY = y;}


    /// getter for item container
    ItemContainer* GetContainer() {return mContainer;}
};
#endif //PROJECT1_GAMELIB_CONTAINERVISITOR_H