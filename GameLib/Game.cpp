/**
 * @file Game.cpp
 * @author hailey cohen
 */
#include "pch.h"
#include "Game.h"
#include "Sparty.h"
#include "Item.h"
using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/**
 * Game Constructor
 */
Game::Game()

{
    mBackground = make_unique<wxBitmap>(
        L"images/background.png", wxBITMAP_TYPE_ANY);

    shared_ptr<Item> sparty = make_shared<Sparty>(this);
    sparty->SetLocation(InitialX, InitialY);
    mItems.push_back(sparty);


}


void Game::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);
    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
   // dc->DrawText(L"Under the Sea!", 10, 10);


    for (auto item : mItems)
    {
        item->Draw(dc);
    }

}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}