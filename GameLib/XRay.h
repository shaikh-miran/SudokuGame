/**
 * @file XRay.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_XRAY_H
#define PROJECT1_PROJECT1_GAMELIB_XRAY_H

#include "Item.h"



class XRay : public Item
{
private:
    /// The underlying xray image
    std::unique_ptr<wxImage> mXRayImage;

    /// The bitmap we can display for this xray
    std::unique_ptr<wxBitmap> mXRayBitmap;

public:
    XRay(Game* game);
    virtual void Draw( std::shared_ptr<wxGraphicsContext> graphics);
    
    /// Default constructor (disabled)
    XRay() = delete;
    
    /// Copy constructor (disabled)
    XRay(const XRay &) = delete;
    
    /// Assignment operator
    void operator=(const XRay &) = delete;
    
    void Update(double elapsed){};

};

#endif //PROJECT1_PROJECT1_GAMELIB_XRAY_H
