/**
 * @file ItemContainer.cpp
 * @author Sonia Charles Thalatoti
 */

#include "ItemContainer.h"

ItemContainer::ItemContainer(Game *game, std::wstring image,DeclarationContainer * declaration) : Item(game),mDeclaration(declaration)
{

    mContainerImage = std::make_unique<wxImage>(image, wxBITMAP_TYPE_ANY);
    mContainerBitmap = std::make_unique<wxBitmap>(*mContainerImage);

}
void ItemContainer::ContainerXmlLoad(wxXmlNode *node)
{
    auto digitEntry = node->GetChildren();
    for( ; digitEntry;digitEntry = digitEntry->GetNext())
    {
        auto digitId = digitEntry->GetAttribute(L"id").ToStdWstring();
        auto digitName = digitEntry->GetName();
        auto declaration = mDeclaration->GetLevel()->FindDeclaration(digitId);
        if(declaration)
        {
            auto item = declaration->CreateContainer(digitEntry,GetGame());
            AddDigits(item);
        }
    }
}

void ItemContainer::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mContainerImage->GetWidth();
    double hit = mContainerImage->GetHeight();

    graphics->PushState();

    graphics->DrawBitmap(*mContainerBitmap, GetX() - wid/ 2, GetY() - hit / 2, wid, hit);
    for (auto& x: digits)
    {
        wxBitmap* BitMap = x->GetBitmap();
        graphics->DrawBitmap(*BitMap,x->GetX(),x->GetY(),x->GetWidthBitMap(),x->GetHeightBitMap());
    }
    graphics->PopState();
}

void ItemContainer::AddDigits(std::shared_ptr<Item> digit)
{
    digits.push_back(digit);
}

