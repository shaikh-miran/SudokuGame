/**
 * @file Item.cpp
 * @author Sonia Charles Thalatoti
 */



#include "pch.h"
#include "Item.h"
#include "Game.h"


using namespace std;



/**
 * Constructor - Sets the filename for the item, and creates a bitmap based on it
 * @param game The game that the item will be associated with
 * @param filename The filename of the item to use for the image
 */
Item::Item(Game *game, const std::wstring &filename) : mGame(game)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Alternate Constructor
 * @param game The game this item is a member of
 */
Item::Item(Game *game) : mGame(game) {}

/**
 * Destructor
 */
Item::~Item()
{
}

bool Item::HitTest(int x, int y)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if(testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    //return !mItemImage->IsTransparent((int)testX, (int)testY);
    return true;
}

/**
Draw implementation for items
@param graphics Device context to draw on
*/
void Item::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    graphics->DrawBitmap(*mItemBitmap,
                         GetX(),
                         GetY(),
                         mWidth,
                         mHeight);
}

/**
 * load function from xml file
 * @param node
 */
void Item::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"col", L"0").ToDouble(&mX);
    node->GetAttribute(L"row", L"0").ToDouble(&mY);
}
