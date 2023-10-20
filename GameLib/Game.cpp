/**
 * @file Game.cpp
 * @author hailey cohen, maui
 */
#include "pch.h"
#include "Game.h"

#include <wx/xml/xml.h>
#include "XRay.h"
#include <vector>
#include <memory>
#include "Sparty.h"
#include "Item.h"
#include "GameView.h"
#include "ParseXML.h"


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
#include "Digit.h"
#include "Given.h"
using namespace std;





/**
 * Game Constructor
 */
Game::Game()

{
    mBackground = make_unique<wxBitmap>(
        L"images/background.png", wxBITMAP_TYPE_ANY);

    mScoreboard.StartTimer();

//    std::shared_ptr<Digit> digit = make_shared<Digit>(this);

    //XRay implementation

    std::shared_ptr<XRay> xray = make_shared<XRay>(this);
    xray->SetLocation(XRInitialX, XRInitialY);

    mItems.push_back(xray);

    std::shared_ptr<Digit> digit0 = make_shared<Digit>(this,L"images/0b.png");
    digit0->SetLocation(685, 735);
    mItems.push_back(digit0);

    std::shared_ptr<Digit> digit1 = make_shared<Digit>(this,L"images/1b.png");
    digit1->SetLocation(900, 540);
    mItems.push_back(digit1);

    std::shared_ptr<Digit> digit2 = make_shared<Digit>(this,L"images/2b.png");
    digit2->SetLocation(900, 225);
    mItems.push_back(digit2);

    std::shared_ptr<Digit> digit3 = make_shared<Digit>(this,L"images/3b.png");
    digit3->SetLocation(830, 290);
    mItems.push_back(digit3);

    std::shared_ptr<Digit> digit4 = make_shared<Digit>(this,L"images/4b.png");
    digit4->SetLocation(540, 225);
    mItems.push_back(digit4);

    std::shared_ptr<Digit> digit5 = make_shared<Digit>(this,L"images/5b.png");
    digit5->SetLocation(685, 225);
    mItems.push_back(digit5);

    std::shared_ptr<Digit> digit6 = make_shared<Digit>(this,L"images/6b.png");
    digit6->SetLocation(395, 290);
    mItems.push_back(digit6);

    std::shared_ptr<Digit> digit7 = make_shared<Digit>(this,L"images/7b.png");
    digit7->SetLocation(320, 225);
    mItems.push_back(digit7);

    std::shared_ptr<Digit> digit8 = make_shared<Digit>(this,L"images/8b.png");
    digit8->SetLocation(900, 485 );
    mItems.push_back(digit8);

    std::shared_ptr<Given> given0 = make_shared<Given>(this,L"images/0r.png");
    given0->SetLocation(685, 85);
    mItems.push_back(given0);

    std::shared_ptr<Given> given1 = make_shared<Given>(this,L"images/1r.png");
    given1->SetLocation(1320, 50);
    mItems.push_back(given1);

    std::shared_ptr<Given> given2 = make_shared<Given>(this,L"images/2r.png");
    given2->SetLocation(1232, 295);
    mItems.push_back(given2);

    std::shared_ptr<Given> given3 = make_shared<Given>(this,L"images/3r.png");
    given3->SetLocation(1100, 753);
    mItems.push_back(given3);

    std::shared_ptr<Given> given4 = make_shared<Given>(this,L"images/4r.png");
    given4->SetLocation(1223, 674);
    mItems.push_back(given4);

    std::shared_ptr<Given> given5 = make_shared<Given>(this,L"images/5r.png");
    given5->SetLocation(1000, 225);
    mItems.push_back(given5);

    std::shared_ptr<Given> given6 = make_shared<Given>(this,L"images/6r.png");
    given6->SetLocation(1111, 63);
    mItems.push_back(given6);

    std::shared_ptr<Given> given7 = make_shared<Given>(this,L"images/7r.png");
    given7->SetLocation(1100, 450);
    mItems.push_back(given7);

    std::shared_ptr<Given> given8 = make_shared<Given>(this,L"images/8r.png");
    given8->SetLocation(1390, 485 );
    mItems.push_back(given8);


    mSparty = std::make_shared<Sparty>(this);
    mSparty->SetLocation(InitialX, InitialY);
    mItems.push_back(mSparty);


    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());
}

///**
// * Draw the game
// * @param graphics Graphics device to draw on
// * @param width Width of the window
// * @param height Height of the window
// */
////void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
////{
////    // Determine the size of the playing area in pixels
////    // This is up to you...
////    shared_ptr<Item> item = make_shared<Sparty>(this);
////    item->SetLocation(InitialX, InitialY);
////    mItems.push_back(item);
////}
//
//    shared_ptr<Item> item = make_shared<Sparty>(this);
//    item->SetLocation(InitialX, InitialY);
//    mItems.push_back(item);
//
//    mScoreboard.StartTimer();
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
//    graphics->DrawBitmap(*mDigit, 0,0,pixelWidth, pixelHeight);


    mScoreboard.OnDraw(graphics, this);
    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }
//    mDigit->Draw(graphics, 10,10);
    for (auto item : mItems)
    {
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