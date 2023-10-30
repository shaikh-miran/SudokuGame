/**
 * @file XRayVisitor.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_XRAYVISITOR_H
#define PROJECT1_GAMELIB_XRAYVISITOR_H

#include "Visitor.h" // Include the base Visitor class

class XRayVisitor : public Visitor
{
private:
    XRay* mXRay = nullptr;

public:
    XRay* GetXray() { return mXRay; }

    // Implement the Visit method for XRay
    void XrayVisit(XRay* xray) override
    {
        mXRay = xray;
    }
};

#endif //PROJECT1_GAMELIB_XRAYVISITOR_H
