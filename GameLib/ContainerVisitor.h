/**
 * @file ContainerVisitor.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_CONTAINERVISITOR_H
#define PROJECT1_GAMELIB_CONTAINERVISITOR_H

#include <cmath>
#include "Visitor.h"
#include "ItemContainer.h"

class ContainerVisitor : public Visitor
{
private:
    double mSpartyCenterX, mSpartyCenterY, mX, mY;
    ItemContainer* mContainer = nullptr;

public:

    void ContainerVisit(ItemContainer* container);

    double GetX() {return mX;}
    double GetY() {return mY;}

    void SetSpartyLocation(double x, double y) {mSpartyCenterX = x; mSpartyCenterY = y;}

    ItemContainer* GetContainer() {return mContainer;}
};
#endif //PROJECT1_GAMELIB_CONTAINERVISITOR_H