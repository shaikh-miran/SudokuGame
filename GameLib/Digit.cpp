/**
 * @file Digit.cpp
 * @author Sonia Charles Thalatoti
 */

#include "Digit.h"

using namespace std;

/**
 * Constructor
 * @param game game this xray is a member of
 */
Digit::Digit(Game *game,const wstring &filename) : Item(game, filename)
{
    mDigitImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mDigitBitmap = make_unique<wxBitmap>(*mDigitImage);
}

void Digit::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    double wid = mDigitImage->GetWidth();
    double hit = mDigitImage->GetHeight();


    double HeadX = GetX() - wid / 2;
    double HeadY = GetY() - hit / 2;

    graphics->PushState();

    graphics->PushState();
    graphics->Translate(HeadX, HeadY);

    graphics->DrawBitmap(*mDigitImage, 0, 0, wid, hit);

    graphics->PopState();

}

