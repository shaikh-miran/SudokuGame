/**
 * @file Game.h
 * @author haile
 *
 *
 */


#ifndef CSE335PROJECTONE_PROJECT1_GAME_H
#define CSE335PROJECTONE_PROJECT1_GAME_H
#include "pch.h"
#include "Scoreboard.h"
#include <vector>
#include<memory> //shared_ptr
#include <random>
///#include "Item.h"


#include <wx/xml/xml.h>
#include <wx/graphics.h>




class Game
{
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    ///Scale double variable
    double mScale;

    ///Y and X offset doubles
    double mXOffset;
    ///Y and X offset doubles
    double mYOffset;

//    /// All of the items to populate our aquarium
//    std::vector<std::shared_ptr<Item>> mItems;
    Scoreboard mScoreboard;


public:
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Load(const wxString & filename);
    Game();
};

#endif //CSE335PROJECTONE_PROJECT1_GAME_H
