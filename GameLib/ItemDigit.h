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
    int mValue ;
    bool mIsEatable;

public:

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

    /// getter for mValue
    int GetValue() {return mValue;}

    void SetEatable(bool isEatable) { mIsEatable = isEatable; }
    bool GetEatable() { return mIsEatable; }
    //bool HitTest(int x, int y) override { return true; };
};

#endif //PROJECT1_GAMELIB_ITEMDIGIT_H
