/**
 * @file Game.cpp
 * @author hailey cohen, maui
 */
#include "pch.h"
#include "Game.h"


/// Initial sparty X location
const int InitialX = 100;

/// Initial sparty Y location
const int InitialY = 100;

/// Initial XRay X location
const int XRInitialX = 100;

/// Initial XRay Y location
const int XRInitialY = 100;

#include "Sparty.h"
#include "Item.h"
using namespace std;

/**
 * Game Constructor
 */
Game::Game()

{
    mScoreboard.StartTimer();

    //mouth open close
    mSparty = std::make_shared<Sparty>(this);
    mSparty->SetLocation(InitialX, InitialY);

    mItems.push_back(mSparty);
}

void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    int pixelWidth = 20*48;
    int pixelHeight = 15*48;

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

    mScoreboard.OnDraw(graphics, this);
    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    for (auto item : mItems) {
        item->Draw(graphics);
    }
    graphics->PopState();
}

/**
 * Start the level loading process, given the desired level filename
 * @param filename name of the level file (ex. level0.xml)
 */
void Game::Load(const wxString & filename)
{
    /// Instantiate an xml document
    wxXmlDocument xmlDoc;

    /// Load xml file based on the filename (errors if not found in directory)
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Error loading file: check levels folder.");
        return;
    }

    Clear();

    auto mLevel = new ParseXML(this);
    /// Offload loading process to ParseXML object
    mLevel->Load(xmlDoc);
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

void Game::OnLeftDown(int x, int y)
{
    mClickY = (y - mYOffset) / mScale;
    mClickX = (x - mXOffset) / mScale;

    for (auto item : mItems)
    {
        if (item->isSpart)
        {
            double isSpartY = (item->GetY()-mYOffset) / mScale;
            double isSpartX = (item->GetX()-mXOffset) / mScale;

            double newSpeedX = mClickX - isSpartX;
            double newSpeedY = mClickY - isSpartY;

            item->SetXSpeed(newSpeedX);
            item->SetYSpeed(newSpeedY);
        }
    }
}



void Game::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}

/**
 * Clear the game data.
 *
 * Deletes all known items in the game.
 */
void Game::Clear()
{
    mItems.clear();
}

void Game::AddItem(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}
