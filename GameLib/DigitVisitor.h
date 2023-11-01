/**
 * @file DigitVisitor.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DIGITVISITOR_H
#define PROJECT1_GAMELIB_DIGITVISITOR_H

#include "Visitor.h"

class DigitVisitor : public Visitor
{
private:
    ItemDigit * mDigit = nullptr;
    int mValue = -1;

public:
    void VisitDigit(ItemDigit * digit);
    void SetUneatable();

    int GetValue() { return mValue; }
    void SetValue(int value) { mValue = value; }

    ItemDigit * GetDigit() { return mDigit; }
    void SetDigit(ItemDigit * digit) { mDigit = digit; }
};

#endif //PROJECT1_GAMELIB_DIGITVISITOR_H
