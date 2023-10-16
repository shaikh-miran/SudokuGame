/**
 * @file Game.cpp
 * @author hailey cohen
 */
#include "pch.h"
#include "Game.h"

#include <wx/xml/xml.h>
#include "XRay.h"
#include <vector>
#include <memory>

using namespace std;

#include "Sparty.h"
#include "Item.h"

/// Initial sparty X location
const int InitialX = 100;

/// Initial sparty Y location
const int InitialY = 100;

/// Initial XRay X location
const int XRInitialX = 100;

/// Initial XRay Y location
const int XRInitialY = 100;


/**
 * Game Constructor
 */
Game::Game()

{
    mBackground = make_unique<wxBitmap>(
        L"images/background.png", wxBITMAP_TYPE_ANY);

    mScoreboard.StartTimer();

    //XRay implementation

    std::shared_ptr<XRay> xray = make_shared<XRay>(this);
    xray->SetLocation(XRInitialX, XRInitialY);



    mItems.push_back(xray);

}


/**
 * Draw the game
 * @param graphics Graphics device to draw on
 * @param width Width of the window
 * @param height Height of the window
 */
//void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    // Determine the size of the playing area in pixels
//    // This is up to you...
//    shared_ptr<Item> item = make_shared<Sparty>(this);
//    item->SetLocation(InitialX, InitialY);
//    mItems.push_back(item);
//}




void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    int pixelWidth = 1440;
    int pixelHeight = 960;

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(pixelWidth);
    auto scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE

    graphics->DrawBitmap(*mBackground, 0,0,pixelWidth, pixelHeight);

    mScoreboard.OnDraw(graphics, this);
    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }
    for (auto item : mItems){
        item->Draw(graphics);
    }
    graphics->PopState();

}

void Game::Load(const wxString & filename) {
    wxXmlDocument inputDoc;
    //<level width="20" height="15" tilewidth="48" tileheight="48">
    if(!inputDoc.Load(filename))
    {
        wxMessageBox(L"Error loading file: check levels folder.");
        return;
    }

    /// Parse through inputDoc
    /// Clear any progress, anything on the board
    /// delete the current level, create a new level
//    graphics->PushState();
//
//    graphics->Translate(mXOffset, mYOffset);
//    graphics->Scale(mScale, mScale);
//
//    graphics->DrawBitmap(*mBackground, 0,0,pixelWidth, pixelHeight);
//
//    graphics->PopState();
//
//    for (auto item : mItems)
//    {
//        item->Draw(graphics);
//    }

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

//tileheight and tilewidth setter -> <level width="20" height="15" tilewidth="48" tileheight="48">