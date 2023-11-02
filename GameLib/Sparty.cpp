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

const double MaxSpeed = 400.00;

const double TotalTimeEating = 0.5;

const double TotalTimeHeadbutt = 0.5;

//headbutting
const double Sparty::HeadbuttTime = 0.5;

/**
 * Constructor
 * @param game The game the sparty item will be part of
 * @param image1 The image file name of sparty body
 * @param image2 The image file name of sparty mouth
 */
Sparty::Sparty(Game *game, std::wstring image1, std::wstring image2) : Item(game)
{
    /// Initialize sparty main body image
    mSpartyImage = std::make_unique<wxImage>(image1, wxBITMAP_TYPE_ANY);
    mSpartyBitmap = std::make_unique<wxBitmap>(*mSpartyImage);

    /// Initialize sparty mouth image
    mSpartyMouthImage = std::make_unique<wxImage>(image2, wxBITMAP_TYPE_ANY);
    mSpartyMouthBitmap = std::make_unique<wxBitmap>(*mSpartyMouthImage);
}

void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mSpartyImage->GetWidth();
    double hit = mSpartyImage->GetHeight();

    double wid1 = mSpartyMouthBitmap->GetWidth();
    double hit1 = mSpartyMouthBitmap->GetHeight();
//    // headX, headY are the pixel location of the top-left corner of the Sparty images
    double HeadX = GetX() - wid / 2;
    double HeadY = GetY() - hit / 2;

    graphics->PushState();

//    // Translate to the top-left corner of the Sparty image
    graphics->Translate(HeadX,HeadY);

    double angleOfHead = 0;
    double angleOfMouth = 0;
    if (mTimeHeadbutt > 0){
        double halfOfHeadbutt = TotalTimeHeadbutt / 2;
        if (mTimeHeadbutt < halfOfHeadbutt)
        {
            angleOfHead = mTimeHeadbutt / halfOfHeadbutt * mHeadAngle;
        }
        else{
            angleOfHead = (TotalTimeEating - mTimeHeadbutt) / halfOfHeadbutt * mHeadAngle;
        }
        graphics->Translate(mHeadPivot.x, mHeadPivot.y);
        graphics->Rotate(angleOfHead);
        graphics->Translate(-mHeadPivot.x, -mHeadPivot.y); //from Interact ;)
    }
    if (mTimeEating > 0){
        double halfTimeEating = TotalTimeEating / 2;
        if (mTimeEating < halfTimeEating){
            angleOfMouth = mTimeEating / halfTimeEating * mMouthAngle;
        }
        else{
            angleOfMouth = (TotalTimeHeadbutt - mTimeEating) / halfTimeEating * mMouthAngle;
        }
    }

    graphics->PushState();
    graphics->Translate(mMouthPivot.x, mMouthPivot.y);
    graphics->Rotate(angleOfMouth);
    graphics->Translate(-mMouthPivot.x, -mMouthPivot.y); //from Interact ;)

    graphics->DrawBitmap(*mSpartyMouthBitmap , 0, 0, wid1, hit1);
    graphics->PopState();

    graphics->DrawBitmap(*mSpartyBitmap , 0, 0, wid, hit);
    /// If level 3, draw in the darkness image too
    if (mIsLevel3)
    {
        graphics->Translate((-mDarknessImage->GetWidth()/2) + (wid/2),(-mDarknessImage->GetHeight()/2) + (hit/2));
        graphics->DrawBitmap(*mDarknessBitmap, 0, 0,
                             mDarknessImage->GetWidth(), mDarknessImage->GetHeight());
    }
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
    int adjustedTargetX, adjustedTargetY;
    int boundryX = GetGame()->GetTileWidth() * GetGame()->GetWidthB();
    int boundryY = GetGame()->GetTileHeight() * GetGame()->GetHeightB();

    if (mCanMove) {
        adjustedTargetX = getClickX - (mTargetPivot.x/2);
        adjustedTargetY = getClickY - mTargetPivot.y;
    } else {
        adjustedTargetX = getClickX;
        adjustedTargetY = getClickY;
    }

    if (adjustedTargetX < 0) {
        adjustedTargetX = GetWidth()/2;
    } else if (adjustedTargetX > boundryX) {
        adjustedTargetX = boundryX;
    }

    if (adjustedTargetY < 0) {
        adjustedTargetY = GetHeight()/2;
    } else if (adjustedTargetY > boundryY) {
        adjustedTargetY = boundryY;
    }

    if(GetX() == adjustedTargetX && GetY() == adjustedTargetY)
    {
        SetXSpeed(0);
        SetYSpeed(0);
    }
    else if (getClickX != -1 && getClickY != -1)
    {
        double deltaX = adjustedTargetX - GetX();
        double deltaY = adjustedTargetY - GetY();
        double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

        double dirX = deltaX / distance;
        double dirY = deltaY / distance;

        if(distance <= MaxSpeed * elapsed)
        {
            SetLocation(adjustedTargetX, adjustedTargetY);
            SetXSpeed(0);
            SetYSpeed(0);
        }
        else if (getClickX < 0 || getClickX > boundryX)
        {
            SetXSpeed(0);
            SetYSpeed(0);
        }
        else if (getClickY < 0 || getClickY > boundryY)
        {
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
    if (mTimeEating >0){
        double time = mTimeEating - elapsed;
        if (mTimeEating >= TotalTimeEating/2 && time < TotalTimeEating/2)
        {}
        if (time < 0){
            mTimeEating = 0;

        }
        else{
            mTimeEating = time;
        }
    }
    if (mTimeHeadbutt >0){
        double time = mTimeHeadbutt - elapsed;
        if (mTimeHeadbutt >= TotalTimeHeadbutt/2 && time < TotalTimeHeadbutt/2)
        {

        }
        if (time < 0){
            mTimeHeadbutt = 0;
        }
        else{
            mTimeHeadbutt = time;
        }
    }
}

void Sparty::StartHeadbutt()
{
//    mIsHeadbutting = true;
//    mHeadbuttDuration = 0.0;
}


void Sparty::Yum(){
    mTimeEating = TotalTimeEating;
}

void Sparty::Headbutt(){
    mTimeHeadbutt = TotalTimeHeadbutt;
}

 /**
  * Update Sparty's image post-initialization. Updates the current image/bitmaps with the input. (Level 3)
  * @param image3 new image filename
  */
void Sparty::UpdateDarknessLevel(std::wstring image3)
{
    /// If the image has not been updated to the new image yet...
    if (mDarknessImageFilename != image3) {
        /// Initialize sparty main body image
        mDarknessImage = std::make_unique<wxImage>(image3, wxBITMAP_TYPE_ANY);
        mDarknessBitmap = std::make_unique<wxBitmap>(*mDarknessImage);
        mDarknessImageFilename = image3;
    }
}