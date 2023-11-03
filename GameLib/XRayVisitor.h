/**
 * @file XRayVisitor.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_XRAYVISITOR_H
#define PROJECT1_GAMELIB_XRAYVISITOR_H

#include "Visitor.h" // Include the base Visitor class
#include "XRay.h"

/**
 * Visitor class for XRay objects; accesses data within XRay
 */
class XRayVisitor : public Visitor
{
private:
    /// XRay object pointer
    XRay* mXRay = nullptr;

    /// Bool for XRay list being full
    bool mIsFull = false;

public:
    /**
     * Return XRay pointer
     * @return pointer to mXRay
     */
    XRay* GetXray() { return mXRay; }

    /**
     * Return bool for XRay being full
     * @return bool mIsFull true if full else false
     */
    bool GetIsFull() {return mIsFull;}

    /**
     * Visit the Xray object and access the data within
     * @param xray XRay pointer, XRay to visit
     */
    void XrayVisit(XRay* xray) override;
};

#endif //PROJECT1_GAMELIB_XRAYVISITOR_H
