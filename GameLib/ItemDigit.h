/**
 * @file ItemDigit.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_ITEMDIGIT_H
#define PROJECT1_GAMELIB_ITEMDIGIT_H

#include "Item.h"
#include "DeclarationDigit.h"

class ItemDigit : public Item
{
private:

public:
    //// Default constructor (disabled)
    ItemDigit() = delete;

    /// Copy constructor (disabled)
    ItemDigit(const ItemDigit &) = delete;

    /// Assignment operator
    void operator=(const ItemDigit &) = delete;

    /// Constructor
    ItemDigit(Game* game, std::wstring filename);
};

#endif //PROJECT1_GAMELIB_ITEMDIGIT_H