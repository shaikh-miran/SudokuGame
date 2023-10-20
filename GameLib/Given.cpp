/**
 * @file Given.cpp
 * @author Sonia Charles Thalatoti
 */

#include "Given.h"

Given::Given(Game *game, const std::wstring &filename) : Item(game, filename)
{
    mGivenImage = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mGivenBitmap = std::make_unique<wxBitmap>(*mGivenImage);
}

void Given::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mGivenImage->GetWidth();
    double hit = mGivenImage->GetHeight();


    double HeadX = GetX() - wid / 2;
    double HeadY = GetY() - hit / 2;

    graphics->PushState();

    graphics->PushState();
    graphics->Translate(HeadX, HeadY);

    graphics->DrawBitmap(*mGivenBitmap, 0, 0, wid, hit);

    graphics->PopState();

}





