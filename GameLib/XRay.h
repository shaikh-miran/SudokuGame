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

/**
 * Xray class, derived from item class
 */
class XRay : public Item
{
private:
    /// Vector of all digits inside Xray
    std::vector<ItemDigit*> mXrayDigits;

    /// Capacity of Xray
    int mCapacity;

    /// Xray reaches capacity
    bool mXrayFull = false;

public:
    /**
     * Accept function for visitor
     * @param visitor base class
     */
    void Accept(Visitor *visitor) override { visitor->XrayVisit(this); }

    XRay(Game* game, std::wstring filename);
    
    /// Default constructor (disabled)
    XRay() = delete;
    
    /// Copy constructor (disabled)
    XRay(const XRay &) = delete;
    
    /// Assignment operator
    void operator=(const XRay &) = delete;
    void DisplayNums(ItemDigit * digit);

    void AddItem(ItemDigit* item);

    /**
     * Getter for mXrayFull
     * @return boolean
     */
    bool GetXrayFull();

    /**
     * Setter for mXrayFull
     * @param xrayFull boolean
     */
    void SetXrayFull(bool xrayFull) { mXrayFull = xrayFull; }

    /**
     * Setter for xray capacity
     * @param capacity integer to set
     */
    void SetCapacity(int capacity) { mCapacity = capacity; }

    void RegurgitateItemDigit(int keyPressed);

    bool DigitExist(double x, double y);

    /**
     * Hittest for Xray
     * @param x coordinate
     * @param y coordinate
     * @return false
     */
    bool HitTest(int x, int y) override { return false; }

    /**
     * Gets the vector which stores digits inside xray
     * @return vector
     */
    std::vector<ItemDigit*> GetXRayDigits(){return mXrayDigits;}
};

#endif //PROJECT1_PROJECT1_GAMELIB_XRAY_H

