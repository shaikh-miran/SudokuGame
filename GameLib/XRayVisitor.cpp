/**
 * @file XRayVisitor.cpp
 * @author Navya Singh
 */
#include "pch.h"
#include "XRayVisitor.h"

void XRayVisitor::XrayVisit(XRay* xray)
{
    mXRay = xray;
    mIsFull = xray->GetXrayFull();
}