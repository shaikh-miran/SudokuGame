/**
 * @file YumVisitor.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_YUMVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_YUMVISITOR_H

#include <cmath>
#include "Visitor.h"
#include "ItemDigit.h"

/**
 * Visitor class for digits; sets digits for Sparty to eat
 */
class YumVisitor : public Visitor
{
private:
    /// X value of the point where digit hittest will occur
    double mSpartyCenterX = 0;

    /// Y value of the point where digit hittest will occur
    double mSpartyCenterY = 0;

    /// Digit that is marked to be eaten
    ItemDigit* mYumDigit = nullptr;

    /// X coordinate for mYumDigit
    double mX = 0;

    /// Y coordinate for mYumDigit
    double mY = 0;

public:
    /// Visit Digit implementation that accesses the data of an ItemDigit object
    void VisitDigit(ItemDigit* digit);

    /**
     * Get mYumDigit x coordinate
     * @return x coordinate
     */
    double GetX() {return mX;}

    /**
     * Get mYumDigit y coordinate
     * @return y coordinate
     */
    double GetY() {return mY;}

    /**
     * Get hit test x coordinate
     * @param x input x value
     */
    void XSparty(double x) {mSpartyCenterX = x;}

    /**
     * Get hit test y coordinate
     * @param y input y value
     */
    void YSparty(double y) {mSpartyCenterY = y;}

    /**
     * Get mYumDigit (the ItemDigit to be eaten)
     * @return ItemDigit* to be eaten
     */
    ItemDigit* GetYummyDigit() {return mYumDigit;}
};

#endif //PROJECT1_PROJECT1_GAMELIB_YUMVISITOR_H
