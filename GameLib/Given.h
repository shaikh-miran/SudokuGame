/**
 * @file Given.h
 * @author Sonia Charles Thalatoti
 *
 *
 */

#ifndef PROJECT1_GAMELIB_GIVEN_H
#define PROJECT1_GAMELIB_GIVEN_H
#include "Item.h"
class Given : public Item
{
private:
    /// The underlying xray image
    std::unique_ptr<wxImage> mGivenImage;

    /// The bitmap we can display for this xray
    std::unique_ptr<wxBitmap> mGivenBitmap;

public:
    /// Default constructor (disabled)
    Given() = delete;

    /// Copy constructor (disabled)
    Given(const Given &) = delete;

    /// Assignment operator
    void operator=(const Given &) = delete;

    Given(Game* game,const std::wstring& filename);

    void Draw(std::shared_ptr<wxGraphicsContext> gc);

    void Update(double elapsed){};

};

#endif //PROJECT1_GAMELIB_GIVEN_H
