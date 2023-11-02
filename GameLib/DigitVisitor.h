/**
 * @file DigitVisitor.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DIGITVISITOR_H
#define PROJECT1_GAMELIB_DIGITVISITOR_H

#include "Visitor.h"

/**
 * digit visitor class, derives from visitor class
 */
class DigitVisitor : public Visitor
{
private:
    /// item digit instance
    ItemDigit * mDigit = nullptr;

    /// bool variable for value
    int mValue = -1;

public:
    /// digit visit function
    void VisitDigit(ItemDigit * digit);

    /// function to set digit to uneatable
    void SetUneatable();

    /// getter for mValue
    int GetValue() { return mValue; }

    /// setter for mValue
    void SetValue(int value) { mValue = value; }

    /// getter for digit
    ItemDigit * GetDigit() { return mDigit; }

    /// setter for digit
    void SetDigit(ItemDigit * digit) { mDigit = digit; }
};

#endif //PROJECT1_GAMELIB_DIGITVISITOR_H
