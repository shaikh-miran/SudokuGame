/**
 * @file YumVisitor.cpp
 * @author team promethius
 */
#include "pch.h"
#include "YumVisitor.h"

/**
 * VisitDigit implementation; access data from the ItemDigit object and determine if it is in range for Sparty to eat.
 * If so, mark the ItemDigit as so.
 * @param digit
 */
void YumVisitor::VisitDigit(ItemDigit* digit)
{
    /// Get ItemDigit coordinates
    double digitx = digit->GetX();
    double digity = digit->GetY();

    /// Calculate the distance of the ItemDigit from the Sparty hittest location
    double distance = sqrt(pow(digitx - mSpartyCenterX, 2) + pow(digity - mSpartyCenterY, 2));

    /// If the ItemDigit is in range, store the ItemDigit's data (mark as eat)
    if (distance <= 20)
    {
        mX = digitx;
        mY = digity;
        mYumDigit = digit;
    }

}