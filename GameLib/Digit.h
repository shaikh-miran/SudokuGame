/**
 * @file Digit.h
 * @author Sonia Charles Thalatoti
 *
 *
 */
#include "Item.h"
#ifndef PROJECT1_GAMELIB_DIGIT_H
#define PROJECT1_GAMELIB_DIGIT_H

class Digit : public Item
{
private:
    /// The underlying xray image
    std::unique_ptr<wxImage> mDigitImage;

    /// The bitmap we can display for this xray
    std::unique_ptr<wxBitmap> mDigitBitmap;

public:
    /// Default constructor (disabled)
    Digit() = delete;

    /// Copy constructor (disabled)
    Digit(const Digit &) = delete;

    /// Assignment operator
    void operator=(const Digit &) = delete;

    Digit(Game* game,const std::wstring &filename);

    void Draw( std::shared_ptr<wxGraphicsContext> graphics);

    void Update(double elapsed){};


};

#endif //PROJECT1_GAMELIB_DIGIT_H
