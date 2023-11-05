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
    /**
     * Visitor for accept
     * @param digit object
     */
    void VisitDigit(ItemDigit * digit);

    /// function to set digit to uneatable
    void SetUneatable();

    /**
     * Getter for value
     * @return
     */
    int GetValue() { return mValue; }

    /**
     * Setter for value
     * @param value  integer
     */
    void SetValue(int value) { mValue = value; }

    /**
     * Getter for digit object
     * @return digit
     */
    ItemDigit * GetDigit() { return mDigit; }

    /**
     * Setter for digit object
     * @param digit object
     */
    void SetDigit(ItemDigit * digit) { mDigit = digit; }
};

#endif //PROJECT1_GAMELIB_DIGITVISITOR_H
