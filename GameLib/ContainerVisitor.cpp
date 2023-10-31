/**
 * @file ContainerVisitor.cpp
 * @author Team prometheus
 */

#include "ContainerVisitor.h"

void ContainerVisitor::ContainerVisit(ItemContainer* container)
{
    double containerX = container->GetX();
    double containerY = container->GetY();
    //mSpartyCenterX += 1;
    double distance = sqrt(pow(containerX - mSpartyCenterX, 2) + pow(containerY - mSpartyCenterY, 2));

    if (distance <= 128)
    {
        mX = containerX;
        mY = containerY;
        mContainer = container;
    }

}