/**
 * @file YumVisitor.cpp
 * @author team promethius
 */
#include "pch.h"
#include "YumVisitor.h"

void YumVisitor::VisitDigit(ItemDigit* digit)
{
    double digitx = digit->GetX();
    double digity = digit->GetY();

    double distance = sqrt(pow(digitx - mSpartyCenterX, 2) + pow(digity - mSpartyCenterY, 2));

    if (distance <= 20)
    {
        mX = digitx;
        mY = digity;
        mYumDigit = digit;
    }

}