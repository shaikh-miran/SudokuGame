/**
 * @file ItemDigit.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_ITEMDIGIT_H
#define PROJECT1_GAMELIB_ITEMDIGIT_H

#include "Item.h"
#include "DeclarationDigit.h"
#include "Visitor.h"

/**
 * item digit class, derived from item class
 * these digits are going to be eaten , placed on grid
 */
class ItemDigit : public Item
{
private:
    /// value member variable
    int mValue ;

    /// bool, true if item is eatable
    bool mIsEatable;

    /// Boolean value that will be toggled when the Digit is in the sudoku grid (true if placed in grid)
    bool mIsPlaced = false;


public:

    /**
     * accept function for visitors
     * @param visitor Visitor object
     */
    void Accept(Visitor * visitor) override {
        visitor->VisitDigit(this);
    }
    //// Default constructor (disabled)
    ItemDigit() = delete;

    /// Copy constructor (disabled)
    ItemDigit(const ItemDigit &) = delete;

    /// Assignment operator
    void operator=(const ItemDigit &) = delete;

    /// Constructor
    ItemDigit(Game* game, std::wstring filename);

    /**
     * getter for mValue
     * @return value of the ItemDigit
     */
    int GetValue() {return mValue;}

    /**
     * setter for is eatable member variable
     * @param isEatable bool, true if eatable
     */
    void SetEatable(bool isEatable) { mIsEatable = isEatable; }

    /**
     * getter for is eatable member variable
     * @return bool mIsEatable
     */
    bool GetEatable() { return mIsEatable; }

    /**
     * Toggle mIsPlaced when the Digit is in the sudoku grid (true if placed in grid)
     * @param value boolean value to set mIsPlaced to
     */
    void SetPlaced(bool value) { mIsPlaced = value; }

    /**
     * Getter that indicates whether or not a Digit is placed in the grid
     * @return bool true if Digit is placed
     */
    bool GetPlaced() const { return mIsPlaced; }

};

#endif //PROJECT1_GAMELIB_ITEMDIGIT_H
