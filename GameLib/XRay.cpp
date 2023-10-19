/**
 * @file XRay.cpp
 * @author haile
 */

#include "pch.h"
#include "XRay.h"
#include "Game.h"
#include <string>

using namespace std;

/// XRay filename
const wstring XRayImageName = L"images/xray.png";


/**
 * Constructor
 * @param game game this xray is a member of
 */
XRay::XRay(Game *game) : Item(game, XRayImageName)
{
    mXRayImage = make_unique<wxImage>(XRayImageName, wxBITMAP_TYPE_ANY);
    mXRayBitmap = make_unique<wxBitmap>(*mXRayImage);
}

void XRay::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{



    double wid = mXRayImage->GetWidth();
    double hit = mXRayImage->GetHeight();


    // headX, headY are the pixel location of the top-left corner of the Sparty images
    double HeadX = GetX() - wid / 2;
    double HeadY = GetY() - hit / 2;

    graphics->PushState();

    // Translate to the top-left corner of the Sparty image

    // get X * tilewidth + imagewidth / 2 - tilewidth / 2
    // get Y * tileheight - imageheight / 2 + tileheight / 2
    // eventually, code it this way. for Checkpoint 1, can hardcode

    //wxSize name = static_cast<wxSize>(48);

   // graphics->Translate(GetX() - wid, GetY() * 48 - hit + 22/2);

    // headX, headY are the pixel location of the top-left corner of the Sparty images
    graphics->PushState();
    graphics->Translate(HeadX, 800);


    // Draw all of the Sparty character assuming the
    // top left corner is at 0,0

    //graphics->PopState();

    // Draw all the Sparty character assuming the
    // top left corner is at 0,0

    graphics->DrawBitmap(*mXRayImage, 0, 0, wid, hit);


    graphics->PopState();


}