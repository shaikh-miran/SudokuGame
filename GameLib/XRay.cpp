/**
 * @file XRay.cpp
 * @author haile
 */

#include "pch.h"
#include "XRay.h"

/**
 * Constructor
 * @param game game this xray is a member of
 */
XRay::XRay(Game *game, std::wstring filename) : Item(game, filename)
{
}