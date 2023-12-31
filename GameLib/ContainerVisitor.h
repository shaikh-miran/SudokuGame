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
    /// member variable sparty center x
    double mSpartyCenterX;

    /// member variables sparty center y
    double mSpartyCenterY;

    /// member variables mX
    double mX;
    /// member variables mY
    double mY;

    /// item container instance
    ItemContainer* mContainer = nullptr;

public:

    /**
     * Container visit function for accept
     * @param container object
     */
    void ContainerVisit(ItemContainer* container);

    /**
     * Getter for mX
     * @return mX
     */
    double GetX() {return mX;}

    /**
     * Getter for mY
     * @return mY
     */
    double GetY() {return mY;}

    /**
     * setter for sparty location
     * @param x coordinate
     * @param y coordinate
     */
    void SetSpartyLocation(double x, double y) {mSpartyCenterX = x; mSpartyCenterY = y;}


    /**
     * Getter for Container
     * @return container
     */
    ItemContainer* GetContainer() {return mContainer;}
};
#endif //PROJECT1_GAMELIB_CONTAINERVISITOR_H