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
    XRay(Game* game, std::wstring filename);
    
    /// Default constructor (disabled)
    XRay() = delete;
    
    /// Copy constructor (disabled)
    XRay(const XRay &) = delete;
    
    /// Assignment operator
    void operator=(const XRay &) = delete;
};

#endif //PROJECT1_PROJECT1_GAMELIB_XRAY_H

