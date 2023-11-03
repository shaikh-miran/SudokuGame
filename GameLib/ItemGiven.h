/**
 * @file ItemGiven.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_ITEMGIVEN_H
#define PROJECT1_GAMELIB_ITEMGIVEN_H

#include "Item.h"
#include "DeclarationGiven.h"

/**
 * given number class, derived from item class
 * represents numbers given on the grid
 */
class ItemGiven : public Item
{
private:

public:
    /// Default constructor (disabled)
    ItemGiven() = delete;
    /// Copy constructor (disabled)
    ItemGiven(const ItemGiven &) = delete;
    /// Assignment operator
    void operator=(const ItemGiven &) = delete;

    /**
     * accept function for visitors
     * @param visitor
     */
    void Accept(Visitor *visitor) override{
        visitor->GivenVisit(this);
    }

    /// constructor
    ItemGiven(Game* game, std::wstring filename);

    //bool HitTest(int x, int y) override { return true; };
};

#endif //PROJECT1_GAMELIB_ITEMGIVEN_H
