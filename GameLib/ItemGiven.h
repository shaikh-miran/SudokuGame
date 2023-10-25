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

    ItemGiven(Game* game, std::wstring filename);
};

#endif //PROJECT1_GAMELIB_ITEMGIVEN_H