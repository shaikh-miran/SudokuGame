/**
 * @file Background.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H
#define PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H

#include "Item.h"
#include "DeclarationBackground.h"

/**
 * Class Background - Manages objects of the Background type, which display background images in the game window.
 */
class Background : public Item
{
public:
    //// Default constructor (disabled)
    Background() = delete;

    /// Copy constructor (disabled)
    Background(const Background &) = delete;

    /// Assignment operator
    void operator=(const Background &) = delete;

    /// Constructor
    Background(Game* game, std::wstring filename);
};

#endif //PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H
