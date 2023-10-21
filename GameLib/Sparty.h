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

    /// moving mouth
    wxPoint mMouthPivot;
    double mMouthAngle;

public:
    /// Default constructor (disabled)
    Sparty() = delete;

    /// Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    /// Assignment operator
    void operator=(const Sparty &) = delete;

    /// Constructor
    Sparty(Game *game, std::wstring image1, std::wstring image2);

    void Update(double elapsed) override;

    void Draw( std::shared_ptr<wxGraphicsContext> graphics) override;
    void DrawTop( std::shared_ptr<wxGraphicsContext> graphics);
    void DrawBottom( std::shared_ptr<wxGraphicsContext> graphics);

    bool HitTest(int x, int y) override;

    /// moving mouth
    void SetMouthPivot(const wxPoint& pivot);
    void SetMouthAngle(double angle);
};

#endif //PROJECT1_GAMELIB_SPARTY_H
