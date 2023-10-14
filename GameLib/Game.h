/**
 * @file Game.h
 * @author haile
 *
 *
 */


#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include "pch.h"
#include <vector>
#include <memory> //shared_ptr
#include <random>
#include <wx/xml/xml.h>
#include <wx/graphics.h>
#include "Item.h"
#include "Scoreboard.h"


class Item;
class Game
{
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;
    Scoreboard mScoreboard;

    ///Scale double variable
    double mScale;

    ///Y and X offset doubles
    double mXOffset;
    ///Y and X offset doubles
    double mYOffset;

public:
    void OnDraw(wxDC* dc, std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    Game();
    std::shared_ptr<Item> HitTest(int x, int y);

};

#endif //PROJECT1_GAMELIB_GAME_H
