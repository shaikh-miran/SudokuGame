/**
 * @file ItemContainer.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "ItemContainer.h"
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

/**
 * transverse through the xml node, Container's Children.
 * @param node Container node in xml.
 */
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
        std::uniform_real_distribution<> distributionX(0, MaxX);
        std::uniform_real_distribution<> distributionY(0, MaxY);
        double x, y ;

        do {
            x = GetX() + GetGame()->GetTileWidth()/2 - distributionX(GetGame()->GetRandom());
            y = (GetY() + GetGame()->GetTileHeight()/2 - GetHeight()/2 - GetGame()->GetTileHeight() )
                - distributionY(GetGame()->GetRandom());
        } while (DigitExist(x, y));

        item->SetLocation(x, y);

        /// Move the digit from mDigitList to Game -> mItems
        this->GetGame()->AddItem(std::move(item));
    }

    /// I think move copies for some reason :( to prevent multiples of the same object, delete !
    mDigitList.clear();
}

/**
 * A check to see if overlapping of digits occur.
 * @param x A x-location
 * @param y A y-location
 * @return Returns true if an digits exists there. Else false.
 */
bool ItemContainer::DigitExist(double x, double y)
{
    // Iterate through existing ItemDigits and check if any are located at (x, y)
    for (auto &item : mDigitList) {
        double itemX = item->GetX();
        double itemY = item->GetY();
        double itemWidth = item->GetWidth();
        double itemHeight = item->GetHeight();

        // Check if the new position overlaps with the existing ItemDigit's position
        if (x >= itemX - 20 && x <= itemX + itemWidth + 20 &&
            y >= itemY - 20 && y <= itemY + itemHeight + 20) {
            return true; // An ItemDigit already exists at this position
        }
    }
    return false; // No ItemDigit exists at this position
}

/**
 * hit test for item container
 * @param x
 * @param y
 * @return
 */
bool ItemContainer::HitTest(int x, int y)
{
    double wid = mContainerBitmap->GetWidth();
    double hit = mContainerBitmap->GetHeight();

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
    return true;
}