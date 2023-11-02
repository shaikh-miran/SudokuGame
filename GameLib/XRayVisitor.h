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

class XRayVisitor : public Visitor
{
private:
    XRay* mXRay = nullptr;
    bool mIsFull = false;

public:
    XRay* GetXray() { return mXRay; }
    bool GetIsFull() {return mIsFull;}

    // Implement the Visit method for XRay
    void XrayVisit(XRay* xray) override
    {
        mXRay = xray;
        mIsFull = xray->GetXrayFull();

    }
};

#endif //PROJECT1_GAMELIB_XRAYVISITOR_H
