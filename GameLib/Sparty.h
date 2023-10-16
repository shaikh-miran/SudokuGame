/**
 * @file Sparty.h
 * @author Sonia Charles Thalatoti
 *
 *
 */

#include "Item.h"
#ifndef PROJECT1_GAMELIB_SPARTY_H
#define PROJECT1_GAMELIB_SPARTY_H

class Sparty: public Item
{
private:
    /// The underlying Sparty image
    std::unique_ptr<wxImage> mSpartyImage;

    /// The bitmap we can display for this Sparty
    std::unique_ptr<wxBitmap> mSpartyBitmap;

    /// The underlying Sparty Mouth image
    std::unique_ptr<wxImage> mSpartyMouthImage;

    /// The bitmap we can display for this Sparty Mouth
    std::unique_ptr<wxBitmap> mSpartyMouthBitmap;



public:
    /// Default constructor (disabled)
    Sparty() = delete;

    /// Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    /// Assignment operator
    void operator=(const Sparty &) = delete;

    Sparty(Game *game);

    void Draw( std::shared_ptr<wxGraphicsContext> graphics) override;

    bool HitTest(int x, int y) override;




};

#endif //PROJECT1_GAMELIB_SPARTY_H
