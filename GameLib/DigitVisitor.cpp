/**
 * @file DigitVisitor.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "DigitVisitor.h"
#include "ItemDigit.h"
/**
 * if it visits a digit, its, eatable, set a pointer to it
 * @param number
 */
void DigitVisitor::VisitDigit(ItemDigit * digit)
{

    if (digit->GetEatable() && mValue == -1)
    {
        mDigit = digit;
    }
    else if (digit->GetEatable() && mValue != -1)
    {
        if (digit->GetValue() == mValue){
            mDigit = digit;
        }
    }
}

/**
 * Sets the digit it found uneatable
 */
void DigitVisitor::SetUneatable()
{
    if (mDigit->GetEatable()) {
        mDigit->SetEatable(false);
    }

}
