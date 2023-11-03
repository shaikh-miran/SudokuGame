/**
 * @file Item.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H

#include "Visitor.h"
/// Forward declaration of Game Class
class Game;

/**
 * Item class
 */
class Item
{
private:
    /// The item's x-direction speed
    double mXSpeed = 0;

    /// The item's y-direction speed
    double mYSpeed = 0;

    /// The Game object that the item is associated with
    Game *mGame;

    // Item location in the Game window
    ///< X location for the center of the item
    double  mX = 0;
    ///< Y location for the center of the item
    double  mY = 0;

    /// Item width
    double mWidth;

    /// Item height
    double mHeight;

    /// item image pointer
    std::unique_ptr<wxImage> mItemImage;
    /// item bitmap pointer
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// item instance
    std::unique_ptr<Item> mItems;

    /// value instance
    int mValue;

protected:
    /// Item Constructor
    Item(Game *game);

    /// Item Constructor (alternate)
    Item(Game *game, const std::wstring &filename);


public:
    /**
     * Returns the Item's associated Game object pointer
     * @return Game
     */
    Game *GetGame() {return mGame;}

    /**
     * Returns the x-direction speed of the Item
     * @return double
     */
    double GetSpeedX() {return mXSpeed;}
    /**
     * Returns the y-direction speed of the Item
     * @return double
     */
    double GetSpeedY() {return mYSpeed;}

    /**
     * Overridable function to update item members
     * @param elapsed time elapsed since Game start
     */
    virtual void Update(double elapsed) {}

    /**
     * accept function for visitor
     * @param visitor
     */
    virtual void Accept(Visitor * visitor) = 0;

    /**
     * Sets the x-direction speed of the Item
     * @param newXSpeed new inputted x-direction speed
     */
    void SetXSpeed(double newXSpeed) {mXSpeed = newXSpeed;}

    /**
     * Sets the y-direction speed of the Item
     * @param newYSpeed new inputted y-direction speed
     */
    void SetYSpeed(double newYSpeed) {mYSpeed = newYSpeed;}

    /**
     * Sets the item's width
     * @param width new width to set
     */
    void SetWidth(double width) {mWidth = width; }

    /**
     * Sets the item's height
     * @param height new height to set
     */
    void SetHeight(double height) {mHeight = height;}

    /// Returns whether the Item is Sparty (base Item)
    bool isSpart = false;

    /// Destructor
    virtual ~Item();

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * bitmap getter
     * @return
     */
    wxBitmap* GetBitmap() const {
        return mItemBitmap.get();
    }
    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }


    /// Virtual function to draw using wxDC
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    /**
     * Test this item to see if it has been clicked on
     * @param x X location on the aquarium to test in pixels
     * @param y Y location on the aquarium to test in pixels
     * @return true if clicked on
     */
    virtual bool HitTest(int x, int y) ;

    /// load function from xml file
    void XmlLoad(wxXmlNode *node);

    /**
     * bitmap width getter
     * @return int width
     */
    double GetWidthBitMap() {return mItemBitmap->GetWidth();}

    /**
     * bitmap height getter
     * @return height int
     */
    double GetHeightBitMap() {return mItemBitmap->GetHeight();}

    /**
     * width getter
     * @return int width
     */
    double GetWidth() { return mWidth; }

    /**
     * height getter
     * @return height int
     */
    double GetHeight() { return mHeight; }

    /**
     * value setter
     * @param value
     */
    void SetValue(int value) { mValue = value; }

    /**
     * value getter
     * @return mValue
     */
    int GetValue() { return mValue; }
};

#endif //PROJECT1_GAMELIB_ITEM_H
