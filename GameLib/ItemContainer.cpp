/**
 * @file ItemContainer.cpp
 * @author Sonia Charles Thalatoti
 */

#include "ItemContainer.h"

ItemContainer::ItemContainer(Game *game, std::wstring image,DeclarationContainer * declaration) : Item(game),mDeclaration(declaration)
{

    mContainerImage = std::make_unique<wxImage>(image, wxBITMAP_TYPE_ANY);
    mContainerBitmap = std::make_unique<wxBitmap>(*mContainerImage);

//    mContainerImage = std::make_unique<wxImage>(image, wxBITMAP_TYPE_ANY);
//    mContainerBitmap = std::make_unique<wxBitmap>(*mContainerImage);


}
void ItemContainer::ContainerXmlLoad(wxXmlNode *node)
{
//    Item::XmlLoad(node);
    auto digitEntry = node->GetChildren();
    for( ; digitEntry;digitEntry = digitEntry->GetNext())
    {
        auto digitId = digitEntry->GetAttribute(L"id").ToStdWstring();
        auto digitName = digitEntry->GetName();
        auto declaration = mDeclaration->GetLevel()->FindDeclaration(digitId);
        if(declaration)
        {
            auto item = declaration->Create(digitEntry,GetGame());
            AddDigits(item);
        }
    }
}

void ItemContainer::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
//    double wid1 = mContainerFrontImage->GetWidth();
//    double hit1 = mContainerFrontImage->GetHeight();

    double wid = mContainerImage->GetWidth();
    double hit = mContainerImage->GetHeight();

    double HeadX = GetX() - wid/ 2;
    double HeadY = GetY() - hit / 2;

    graphics->PushState();

    graphics->Translate(HeadX,HeadY);

    graphics->DrawBitmap(*mContainerBitmap, 0, 0, wid, hit);

//    for (auto &x: digits)
//    {
//        x->Draw(graphics);
//    }
//    graphics->DrawBitmap(*mContainerFrontBitmap, 0, 0, wid, hit);

//    DrawFront(graphics);
    graphics->PopState();
}
//void ItemContainer::DrawImage(std::shared_ptr<wxGraphicsContext> graphics)
//{
//    double wid = mContainerImage->GetWidth();
//    double hit = mContainerImage->GetHeight();
//    graphics->DrawBitmap(*mContainerBitmap, 0, 0, wid, hit);
//}
//void ItemContainer::DrawFront(std::shared_ptr<wxGraphicsContext> graphics)
//{
//    double wid = mContainerFrontImage->GetWidth();
//    double hit = mContainerFrontImage->GetHeight();
//    graphics->DrawBitmap(*mContainerFrontBitmap, 0, 0, wid, hit);
//}

void ItemContainer::AddDigits(std::shared_ptr<Item> digit)
{
    digits.push_back(digit);
}

