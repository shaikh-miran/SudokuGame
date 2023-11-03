/**
 * @file XRayVisitor.cpp
 * @author Navya Singh
 */
#include "pch.h"
#include "XRayVisitor.h"

/**
 * XRayVisit implementation; Visit the XRay and collect pointer and full status
 * @param xray
 */
void XRayVisitor::XrayVisit(XRay* xray)
{
    mXRay = xray;
    mIsFull = xray->GetXrayFull();
}