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

    /// visitor acceptor function
    void Accept(Visitor *visitor) override{
        visitor->BackgroundVisit(this);
    }
    //// Default constructor (disabled)
    Background() = delete;

    /// Copy constructor (disabled)
    Background(const Background &) = delete;

    /// Assignment operator
    void operator=(const Background &) = delete;

    /// Constructor
    Background(Game* game, std::wstring filename);

    /// function to test if item hit
    bool HitTest(int x, int y) override { return false; };
};

#endif //PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H
