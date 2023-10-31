/**
 * @file YumVisitor.h
 * @author team promethius
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_YUMVISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_YUMVISITOR_H

#include <cmath>
#include "Visitor.h"
#include "ItemDigit.h"
class YumVisitor : public Visitor
{
private:

    double mSpartyCenterX = 0;
    double mSpartyCenterY = 0;

    double mX = 0;
    double mY = 0;

    ItemDigit* mYumDigit = nullptr;

public:

    void DigitVisit(ItemDigit* digit)
    {
        double digitx = digit->GetX();

        double digity = digit->GetY();

        mSpartyCenterX += 1;
        double distance = sqrt(pow(digitx - mSpartyCenterX, 2) + pow(digity - mSpartyCenterY, 2));

        if (distance <= 48)
        {
            mX = digitx;
            mY = digity;
            mYumDigit = digit;
        }

    }
    double GetX() {return mX;}
    double GetY() {return mY;}

    void XSparty(double x) {mSpartyCenterX = x;}
    void YSparty(double y) {mSpartyCenterY = y;}

   ItemDigit* GetYummyDigit() {return mYumDigit;}
};

#endif //PROJECT1_PROJECT1_GAMELIB_YUMVISITOR_H
