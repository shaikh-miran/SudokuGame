/**
 * @file Item.h
 * @author Sonia Charles Thalatoti
 *
 *
 */

#ifndef PROJECT1_GAMELIB_ITEM_H
#define PROJECT1_GAMELIB_ITEM_H


class Game;
class Item
{
private:
    /// The aquarium this item is contained in
    Game *mGame;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item


    std::unique_ptr<wxImage> mItemImage;
    std::unique_ptr<wxBitmap> mItemBitmap;
    std::unique_ptr<Item> mItems;

protected:
    Item(Game *game, const std::wstring &filename);

protected:
    Item(Game *game);


public:
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
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    void SetLocation(double x, double y) { mX = x; mY = y; }


    /**
     * Draw this item
     * @param dc Device context to draw on
     */

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) {};

    /**
     * Test this item to see if it has been clicked on
     * @param x X location on the aquarium to test in pixels
     * @param y Y location on the aquarium to test in pixels
     * @return true if clicked on
     */

    virtual bool HitTest(int x, int y);

};




#endif //PROJECT1_GAMELIB_ITEM_H
