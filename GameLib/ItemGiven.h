/**
 * @file ItemGiven.h
 * @author Team Prometheus
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
public:
    /// Default constructor (disabled)
    ItemGiven() = delete;
    /// Copy constructor (disabled)
    ItemGiven(const ItemGiven &) = delete;
    /// Assignment operator
    void operator=(const ItemGiven &) = delete;

    /**
     * accept function for visitors
     * @param visitor visitor object
     */
    void Accept(Visitor *visitor) override{
        visitor->GivenVisit(this);
    }

    /// constructor
    ItemGiven(Game* game, std::wstring filename);
};

#endif //PROJECT1_GAMELIB_ITEMGIVEN_H
