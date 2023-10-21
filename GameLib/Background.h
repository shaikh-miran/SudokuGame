/**
 * @file Background.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H
#define PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H

#include "Item.h"
#include "DeclarationBackground.h"

class Background : public Item
{
private:

public:
    //// Default constructor (disabled)
    Background() = delete;

    /// Copy constructor (disabled)
    Background(const Background &) = delete;

    /// Assignment operator
    void operator=(const Background &) = delete;

    Background(Game* game, std::wstring filename);
};

#endif //PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H
