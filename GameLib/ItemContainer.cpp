/**
 * @file ItemContainer.cpp
 * @author Sonia Charles Thalatoti
 */

#include "ItemContainer.h"

ItemContainer::ItemContainer(Game *game, std::wstring image,std::wstring front) : Item(game)
{

    mContainerFrontImage = std::make_unique<wxImage>(front, wxBITMAP_TYPE_ANY);
    mContainerFrontBitmap = std::make_unique<wxBitmap>(*mContainerFrontImage);

    mContainerImage = std::make_unique<wxImage>(image, wxBITMAP_TYPE_ANY);
    mContainerBitmap = std::make_unique<wxBitmap>(*mContainerImage);


}

void ItemContainer::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid1 = mContainerFrontImage->GetWidth();
    double hit1 = mContainerFrontImage->GetHeight();

    double wid = mContainerImage->GetWidth();
    double hit = mContainerImage->GetHeight();

    double HeadX = GetX() - wid1 / 2;
    double HeadY = GetY() - hit1 / 2;

    graphics->PushState();

    graphics->Translate(HeadX,HeadY);

    DrawImage(graphics);

    for (auto &x: digits)
    {
        x->Draw(graphics);
    }
    DrawFront(graphics);
    graphics->PopState();
}
void ItemContainer::DrawImage(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mContainerImage->GetWidth();
    double hit = mContainerImage->GetHeight();
    graphics->DrawBitmap(*mContainerBitmap, 0, 0, wid, hit);
}
void ItemContainer::DrawFront(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mContainerFrontImage->GetWidth();
    double hit = mContainerFrontImage->GetHeight();
    graphics->DrawBitmap(*mContainerFrontBitmap, 0, 0, wid, hit);
}

void ItemContainer::AddDigits(std::shared_ptr<ItemDigit> digit)
{
    digits.push_back(digit);
}

