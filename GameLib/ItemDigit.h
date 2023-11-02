/**
 * @file ItemDigit.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_ITEMDIGIT_H
#define PROJECT1_GAMELIB_ITEMDIGIT_H

#include "Item.h"
#include "DeclarationDigit.h"
#include "Visitor.h"

class ItemDigit : public Item
{
private:
    int mValue;

    /// Boolean value that will be toggled when the Digit is in the sudoku grid (true if placed in grid)
    bool mIsPlaced = false;

public:

    void Accept(Visitor * visitor) override {
        visitor->DigitVisit(this);
    }
    //// Default constructor (disabled)
    ItemDigit() = delete;

    /// Copy constructor (disabled)
    ItemDigit(const ItemDigit &) = delete;

    /// Assignment operator
    void operator=(const ItemDigit &) = delete;

    /// Constructor
    ItemDigit(Game* game, std::wstring filename);

    /// getter for mValue
    int GetValue(){return mValue;}

    /**
     * Toggle mIsPlaced when the Digit is in the sudoku grid (true if placed in grid)
     * @param value boolean value to set mIsPlaced to
     */
    void SetPlaced(bool value) { mIsPlaced = value; }

    /// Getter that indicates whether or not a Digit is placed in the grid (True if yes)
    bool IsPlaced() const { return mIsPlaced; }
};

#endif //PROJECT1_GAMELIB_ITEMDIGIT_H
