/**
 * @file ItemContainer.cpp
 * @author Team Prometheus
 */

#include "ItemContainer.h"
#include "Game.h"
#include <utility>

/**
 * Constructor
 * @param game The game to associate with the new Container object
 * @param image1 The rear/back image of the Container
 * @param image2  The front image of the Container
 * @param declaration The DeclarationContainer object that contains initializing data
 */
ItemContainer::ItemContainer(Game *game, std::wstring image1, std::wstring image2, DeclarationContainer * declaration) : Item(game), mDeclaration(declaration)
{
    mContainerImage = std::make_unique<wxImage>(image1, wxBITMAP_TYPE_ANY);
    mContainerBitmap = std::make_unique<wxBitmap>(*mContainerImage);
    mContainerFrontImage = std::make_unique<wxImage>(image2, wxBITMAP_TYPE_ANY);
    mContainerFrontBitmap = std::make_unique<wxBitmap>(*mContainerFrontImage);
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

/**
 * Draw override for Container objects. Draws the two parts of the container (front and rear) individually so that they
 * overlap on each other. Also draws the digits within the mDigitList list.
 * @param graphics wxDC graphics context
 */
void ItemContainer::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double width = mContainerImage->GetWidth();
    double height = mContainerImage->GetHeight();

    double widthFront = mContainerFrontImage->GetWidth();
    double heightFront = mContainerFrontImage->GetHeight();

    graphics->PushState();

    graphics->DrawBitmap(*mContainerBitmap, GetX() - width/ 2, GetY() - height / 2, width, height);

    for (auto& x: mDigitList)
    {
        wxBitmap* BitMap = x->GetBitmap();
        graphics->DrawBitmap(*BitMap,x->GetX(),x->GetY(),x->GetWidthBitMap(),x->GetHeightBitMap());
    }

    graphics->DrawBitmap(*mContainerFrontBitmap, GetX() - widthFront/ 2, GetY() - heightFront / 2,
                         widthFront, heightFront);

    graphics->PopState();
}

/**
 * Add the specified ItemDigit object to the Container's mDigitList
 * @param digit input ItemDigit object
 */
void ItemContainer::AddDigits(std::shared_ptr<Item> digit)
{
    mDigitList.push_back(digit);
}

/**
 * Moves all digits contained inside the Container object into the Game object's mItems list. Edits the items' locations
 * so that they will no longer be on top of the containers.
 */
void ItemContainer::EjectDigits() {
    for (auto item : mDigitList)
    {
        /// Use random location to set new x,y location for the digit
        const double MaxX = GetWidth() - GetGame()->GetTileWidth();
        const double MaxY = GetHeight() - GetGame()->GetTileHeight();
        std::uniform_real_distribution<> distributionX(-MaxX, MaxX);
        std::uniform_real_distribution<> distributionY(0, MaxY);
        auto x = GetX() + distributionX(GetGame()->GetRandom());
        auto y = (GetY() + GetGame()->GetTileHeight() / GetHeight() - GetGame()->GetTileHeight() * 2)
            - distributionY(GetGame()->GetRandom());
        item->SetLocation(x, y);

        /// Move the digit from mDigitList to Game -> mItems
        this->GetGame()->AddItem(std::move(item));
    }

    /// I think move copies for some reason :( to prevent multiples of the same object, delete !
    mDigitList.clear();
}