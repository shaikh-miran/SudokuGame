/**
 * @file Game.cpp
 * @author Team Prometheus
 */
#include "pch.h"
#include "Game.h"

/// Initial XRay X location
const int XRInitialX = 100;

/// Initial XRay Y location
const int XRInitialY = 100;

#include "Sparty.h"
#include "Item.h"
#include "YumVisitor.h"
using namespace std;

/**
 * Game Constructor - Creates an instance of the game, and automatically loads the default level
 */
Game::Game()

{
    /// Load level 1; this is the default level to load
    Load(L"levels/level1.xml");

    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());
}


void Game::Accept(Visitor *visitor){
    for (auto digit : mItems)
    {
        digit->Accept(visitor);
    }
}


/**
 * Handles items to be drawn on the game window
 * @param graphics wxGC object that handles the drawing task
 * @param width window width
 * @param height window height
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    int pixelWidth = GetTileWidth() * mWidth;
    int pixelHeight = GetTileHeight() * mHeight;

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

    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = 0;
    if (height > pixelHeight * mScale)
    {
        mYOffset = (double)((height - pixelHeight * mScale) / 2.0);
    }

    for (auto item : mItems){
        item->Draw(graphics);
    }

    // Write out PopUp message for 3 seconds
    mStopWatchPopUp.Start();
    if (mStartState){
        mPopUpMessage.OnDraw(graphics, mCurrentLevel);
    }


    mScoreboard.OnDraw(graphics, this);


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
    mScoreboard.ResetTimer();
//    mScoreboard.StartTimer();
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

/**
 * Handles left click event - force Sparty object to move to the clicked location
 * @param x current cursor x-location
 * @param y current cursor y-location
 */
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
    mSparty->SetCanMove(true);
}

/**
 * Update the game (on-demand)
 * @param elapsed time elapsed from game begin
 */
void Game::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }

    mDuration += elapsed;

    if(mDuration >= 3 && mStartState == true)
    {
//        mScoreboard.ResetTimer();
        mScoreboard.StartTimer();
        /// change state
        mStartState = false;
        mDuration = 0;
    }
}

/**
 * Clear the game data - deletes all known items in the game.
 */
void Game::Clear()
{
    mItems.clear();
}

/**
 * Add the Item from item parameter into the Game object's mItems list
 * @param item the Item to add
 */
void Game::AddItem(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

void Game::SpartyYum(){
    mSparty->Yum();
    YumVisitor visitor;
    visitor.XSparty(mSparty->GetX());
    visitor.YSparty(mSparty->GetY());

    this->Accept(&visitor);
    if (visitor.GetYummyDigit() != nullptr)
    {
        XRayVisitor visitor2;
        this->Accept(&visitor2);
        XRay *xray = visitor2.GetXray();
        xray->DisplayNums(visitor.GetYummyDigit());
        visitor.GetYummyDigit()->SetHeight(visitor.GetYummyDigit()->GetHeight()/2);
        visitor.GetYummyDigit()->SetWidth(visitor.GetYummyDigit()->GetWidth()/2);
        mYummyTile = visitor.GetYummyDigit();
    }
}

void Game::SpartyHeadButt(){
    mSparty->Headbutt();
}


/**
 * Change Level to 0
 * @param starting
 */
void Game::ChangeStateZero(bool starting){
    mStartState = starting;
    mEndState = false;
    mCurrentLevel = 0;
    mDuration = 0;
}

/**
 * Change Level to 1
 * @param starting
 */
void Game::ChangeStateOne(bool starting){
    mStartState = starting;
    mEndState = false;
    mCurrentLevel = 1;
    mDuration = 0;
}

/**
 * Change Level to 2
 * @param starting
 */
void Game::ChangeStateTwo(bool starting){
    mStartState = starting;
    mEndState = false;
    mCurrentLevel = 2;
    mDuration = 0;
}

/**
 * Change Level to 3
 * @param starting
 */
void Game::ChangeStateThree(bool starting){
    mStartState = starting;
    mEndState = false;
    mCurrentLevel = 3;

    mDuration = 0;
}