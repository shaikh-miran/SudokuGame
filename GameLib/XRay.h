/**
 * @file XRay.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_XRAY_H
#define PROJECT1_PROJECT1_GAMELIB_XRAY_H

#include "Item.h"
#include "DeclarationXray.h"

class XRay : public Item
{
private:

public:

    void Accept(Visitor *visitor) override { visitor->XrayVisit(this); }

    XRay(Game* game, std::wstring filename);
    
    /// Default constructor (disabled)
    XRay() = delete;
    
    /// Copy constructor (disabled)
    XRay(const XRay &) = delete;
    
    /// Assignment operator
    void operator=(const XRay &) = delete;
    void DisplayNums(ItemDigit * digit);
};

#endif //PROJECT1_PROJECT1_GAMELIB_XRAY_H

