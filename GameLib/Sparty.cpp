/**
 * @file Sparty.cpp
 * @author Sonia Charles Thalatoti
 */
#include "pch.h"
#include "Sparty.h"
#include <string>
#include "Item.h"
#include "Game.h"

using namespace std;

const int InitialX = 200;

const int InitialY = 200;

const double MaxSpeed = 400.00;

const wstring SpartyImage = L"images/sparty-1.png";
const wstring SpartyMouthImage =  L"images/sparty-2.png";

Sparty::Sparty(Game *game) : Item(game, SpartyImage)
{
    mSpartyImage = std::make_unique<wxImage>(SpartyImage, wxBITMAP_TYPE_ANY);
    mSpartyBitmap = std::make_unique<wxBitmap>(*mSpartyImage);
    mSpartyMouthImage = std::make_unique<wxImage>(SpartyMouthImage, wxBITMAP_TYPE_ANY);
    mSpartyMouthBitmap = std::make_unique<wxBitmap>(*mSpartyMouthImage);

    mMouthPivot = wxPoint(0, 0);
    mMouthAngle = 0;
}
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics)

//put sparty mouth open here

{


    double wid = mSpartyImage->GetWidth();
    double hit = mSpartyImage->GetHeight();

    double wid1 = mSpartyMouthBitmap->GetWidth();
    double hit1 = mSpartyMouthBitmap->GetHeight();
//
//    // headX, headY are the pixel location of the top-left corner of the Sparty images
    double HeadX = GetX() - wid / 2;
    double HeadY = GetY() - hit / 2;

    graphics->PushState();

//
//    // Translate to the top-left corner of the Sparty image
    graphics->Translate(HeadX,HeadY);
//
//    // Draw all the Sparty character assuming the
//    // top left corner is at 0,0
//    graphics->Translate(mMouthPivot.x, mMouthPivot.y);
//    graphics->Rotate(mMouthAngle);
//    graphics->Translate(-mMouthPivot.x, -mMouthPivot.y);
//
//
//    graphics->DrawBitmap(*mSpartyMouthBitmap, int(wid - wid1) / 2, int(hit - hit1) / 2, wid1, hit1);
//    graphics->DrawBitmap(*mSpartyImage, 0, 0, wid, hit);
//
//    // moving mouth
//
//
//    //graphics->DrawBitmap(*mSpartyMouthBitmap, int(wid - wid1) / 2, int(hit - hit1) / 2, wid1, hit1);
//
//    // hailey: this should be 0 and 0, not int(wid - wid1) / 2 and int(hit - hit1) / 2
//
//
//
    DrawTop(graphics);
    DrawBottom(graphics);

    graphics->PopState();


}
void Sparty::DrawTop(std::shared_ptr<wxGraphicsContext> graphics)

//put sparty mouth open here

{
    double wid = mSpartyImage->GetWidth();
    double hit = mSpartyImage->GetHeight();


    // headX, headY are the pixel location of the top-left corner of the Sparty images
    double HeadX = GetX() - wid / 2;
    double HeadY = GetY() - hit / 2;

    //  graphics->PushState();



    graphics->DrawBitmap(*mSpartyImage, 0, 0, wid, hit);

    // moving mouth


    //graphics->DrawBitmap(*mSpartyMouthBitmap, int(wid - wid1) / 2, int(hit - hit1) / 2, wid1, hit1);

    // hailey: this should be 0 and 0, not int(wid - wid1) / 2 and int(hit - hit1) / 2



    // graphics->PopState();


}
void Sparty::DrawBottom(std::shared_ptr<wxGraphicsContext> graphics)

//put sparty mouth open here

{


    double wid1 = mSpartyMouthBitmap->GetWidth();
    double hit1 = mSpartyMouthBitmap->GetHeight();



    graphics->PushState();

    // Translate to the top-left corner of the Sparty image

    // Draw all the Sparty character assuming the
    // top left corner is at 0,0
    graphics->Translate(mMouthPivot.x, mMouthPivot.y);
    graphics->Rotate(mMouthAngle);
    graphics->Translate(-mMouthPivot.x, -mMouthPivot.y);


    graphics->DrawBitmap(*mSpartyMouthBitmap, 0, 0, wid1, hit1);

    // moving mouth


    //graphics->DrawBitmap(*mSpartyMouthBitmap, int(wid - wid1) / 2, int(hit - hit1) / 2, wid1, hit1);

    // hailey: this should be 0 and 0, not int(wid - wid1) / 2 and int(hit - hit1) / 2



    graphics->PopState();


}


/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Sparty::HitTest(int x, int y)
{
    double wid = mSpartyBitmap->GetWidth();
    double hit = mSpartyBitmap->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mSpartyImage->IsTransparent((int)testX, (int)testY);
}

// moving mouth
void Sparty::SetMouthPivot(const wxPoint& pivot)
{
    mMouthPivot = pivot;
}

void Sparty::SetMouthAngle(double angle)
{
    mMouthAngle = angle;
}


/**

Handle updates in time of sparty*
This is called before we draw and allows us to
move sparty. We add our speed times the amount
of time that has elapsed.
@param elapsed Time elapsed since the class call
*/
void Sparty::Update(double elapsed)
{
    Game *game = GetGame();
    int getClickX = game->GetClickX();
    int getClickY = game->GetClickY();

    if(GetX() == getClickX && GetY() == getClickY)
    {
        SetXSpeed(0);
        SetYSpeed(0);
    }
    else
    {
        double deltaX = getClickX - GetX();
        double deltaY = getClickY - GetY();
        double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

        double dirX = deltaX / distance;
        double dirY = deltaY / distance;

        if(distance <= MaxSpeed * elapsed)
        {
            SetLocation(getClickX, getClickY);
            SetXSpeed(0);
            SetYSpeed(0);
        }
        else
        {
            SetXSpeed(MaxSpeed * dirX);
            SetYSpeed(MaxSpeed * dirY);

            SetLocation(GetX() + GetSpeedX() * elapsed, GetY() + GetSpeedY() * elapsed);


        }
    }
}
