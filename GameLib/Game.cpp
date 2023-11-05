/**
 * @file Game.cpp
 * @author Team Prometheus
 */
#include "pch.h"
#include "Game.h"
#include "Sparty.h"
#include "Item.h"
#include "YumVisitor.h"
#include "ContainerVisitor.h"
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


/**
 * accept function for visitor class
 * @param visitor
 */
void Game::Accept(Visitor *visitor){
    for (auto item : mItems)
    {
        item->Accept(visitor);
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
    int pixelWidth = mTileWidth * mWidth;
    int pixelHeight = mTileHeight * mHeight;

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

    for (auto item : mItems){
        item->Draw(graphics);
    }


    // Write out PopUp message for 3 seconds
    mStopWatchPopUp.Start();
    if (mStartState){
        CallPopUpDraw(graphics);
    }

    if (mFullMessage)
    {
        CallPopUpDraw(graphics);
    }

    if (mWrongLocationMessage)
    {
        CallPopUpDraw(graphics);
    }

    if (mScoreboard.GetStartTimer()) {
        mScoreboard.OnDraw(graphics, this);
    }

    if (mSolutionCorrect)
    {
        CallPopUpDraw(graphics);
    }

    if (mSolutionIncorrect)
    {
        CallPopUpDraw(graphics);
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

    /// If the timer is already moving, stop it so that it does not run while the pop up is on screen
    mScoreboard.StopTimer();

    /// Reset Timer to 0 for new level
    mScoreboard.ResetTimer();
}


/**
 * Test an x,y click location to see if an item exists at that position.
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
        mScoreboard.SetStartTimer(true);
        mScoreboard.StartTimer();
        mStartState = false;
        mDuration = 0;
    }

    if (mFullMessage == true && mStopWatchSpartyFull.Time() > 3000)
    {
        mFullMessage = false;
        mDurationFullMessage = 0;
    }

    if (mWrongLocationMessage == true && mStopWatchWrongLocation.Time() > 3000)
    {
        mWrongLocationMessage = false;
        mDurationWrongLocation = 0;
    }
    /// If Level 3, handle the timed sparty darkness image changes
    /// Only change image when sparty is not performing headbutt or eat (will crash)
    if (mCurrentLevel == 3 && !GetSparty()->InAction())
    {
        if (round(mDuration) == 20)
        {
            GetSparty()->UpdateDarknessLevel(L"images/darkness-2.png");
        }
        else if (round(mDuration) == 40)
        {
            GetSparty()->UpdateDarknessLevel(L"images/darkness-3.png");
        }
        else if (round(mDuration) == 70)
        {
            GetSparty()->UpdateDarknessLevel(L"images/darkness-4.png");
        }
        else if (round(mDuration) == 110)
        {
            GetSparty()->UpdateDarknessLevel(L"images/darkness-5.png");
        }
        else if (round(mDuration) == 160)
        {
            GetSparty()->UpdateDarknessLevel(L"images/darkness-6.png");
        }
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


/**
 * function for sparty to eat a digit to eat a digit
 * gets location, checks if digit at location
 * checks if digit exists in xray already
 * if not, eats digit
 */
void Game::SpartyYum()
{
    // getting sparty full bool
    XRayVisitor visitorForGetFullVariable;
    this->Accept(&visitorForGetFullVariable);
    bool isFull = visitorForGetFullVariable.GetIsFull();

    // if sparty is not full
    if (!isFull)
    {
        mSparty->Yum();
        YumVisitor visitor;
        visitor.XSparty(mSparty->GetX());
        visitor.YSparty(mSparty->GetY());

        this->Accept(&visitor);

        if (visitor.GetYummyDigit() != nullptr )
        {
            XRayVisitor visitor2;
            this->Accept(&visitor2);
            XRay *xray = visitor2.GetXray();
            std::vector<ItemDigit*> XrayDigits = xray->GetXRayDigits();

            if (std::find(XrayDigits.begin(), XrayDigits.end(), visitor.GetYummyDigit()) == XrayDigits.end())
            {
                if (!xray->GetXrayFull() ) {
                    xray->AddItem(visitor.GetYummyDigit());
                    xray->DisplayNums(visitor.GetYummyDigit());
                    visitor.GetYummyDigit()->SetHeight(visitor.GetYummyDigit()->GetHeight()/2);
                    visitor.GetYummyDigit()->SetWidth(visitor.GetYummyDigit()->GetWidth()/2);
                }
            }
        }
    }
    else
    {
        mSpartyFull = true;
        mStopWatchSpartyFull.Start();
        mFullMessage = true;


    }
}


/**
 * Regurgitates the digit when a key is pressed.
 * @param keyPressed the key pressed in int.
 */
void Game::SpartyRegurgitate(long keyPressed)
{
    XRayVisitor visitor;
    this->Accept(&visitor);
    XRay *xray = visitor.GetXray();
    std::vector<ItemDigit*> digits = xray->GetXRayDigits();

    int row = mClickX/48;
    int col = mClickY/48;

    bool keyPressedFound = false;
    for (auto item : digits) {
        if (item->GetValue() == keyPressed) {
            keyPressedFound = true;
            break; // Found a match, no need to continue searching
        }
    }

    if (keyPressedFound)
    {
        if(isLocationInVector(col,row,mCurrentLevel))
        {
            bool location = GivenExist(col,row);
            if (!location)
            {
                mSparty->Yum(); // Call Yum if keyPressed was found
                xray->RegurgitateItemDigit(keyPressed);

            }
            else
            {
                mGivenExists = true;
                mStopWatchWrongLocation.Start();
                mWrongLocationMessage = true;
            }

        }
    }

    mSpartyFull = false;
}


/**
 * function to call pop up messages at different instances
 *
 * @param graphics
 */
void Game::CallPopUpDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    BackgroundVisitor visitor;
    this->Accept(&visitor);
    Background *background = visitor.GetBackground();
    int height = background->GetHeight();
    int width = background->GetWidth();

    if (mStartState) {
        mPopUpMessage.OnDraw(graphics, mCurrentLevel, width, height);
        mGivenExists = false;
        mSolutionCorrect = false;
        mSolutionIncorrect = false;
    }

    if (mSpartyFull) {
        mPopUpMessage.OnSpartyFull(graphics, mCurrentLevel, width, height);
        mGivenExists = false;
        mSolutionCorrect = false;
        mSolutionIncorrect = false;
    }

    if (mGivenExists)
    {
        mPopUpMessage.OnExists(graphics,mCurrentLevel,width,height);
        mSolutionCorrect = false;
        mSolutionIncorrect = false;

    }

    if (mSolutionCorrect) {
        mPopUpMessage.OnLevelCompletion(graphics, mCurrentLevel, width, height);
        mGivenExists = false;
        mSolutionIncorrect = false;
    }

    if (mSolutionIncorrect) {
        mPopUpMessage.OnIncorrect(graphics, mCurrentLevel, width, height);
        mGivenExists = false;
        mSolutionCorrect = false;
    }
}

/**
 * Function that runs when sparty headbutts (B is pressed, activating this function). If there is a container in range,
 * the container will release all numbers within.
 */
void Game::SpartyHeadButt(){
    mSparty->Headbutt();
    ContainerVisitor visitor;
    visitor.SetSpartyLocation(mSparty->GetX(), mSparty->GetY());
    this->Accept(&visitor);
    if (visitor.GetContainer() != nullptr)
    {
        visitor.GetContainer()->EjectDigits();
    }
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
void Game::ChangeStateThree(bool starting)
{
    mStartState = starting;
    mEndState = false;
    mCurrentLevel = 3;

    mDuration = 0;
}

/**
 * Create a vector of tuples of position on the grid.
 * @return a the vector.
 */
void Game::generateLocationTuples(int level)
{
    int rowStart , colStart;
    if (level == 1 || level == 3)
    {
        rowStart = 3;
        colStart = 4;
    }
    if (level == 2)
    {
        rowStart = 1;
        colStart = 5;
    }

    const int numRows = 9;
    const int numCols = 9;

    for (int row = rowStart; row < rowStart+numRows; row++) {
        for (int col = colStart; col < colStart+numCols; col++) {
            mLocationTuples.push_back(std::make_tuple(row, col));
        }
    }
}

/**
 * checks if the location is valid and is in the board frame.
 * @param row row clicked
 * @param col col clicked.
 * @return return true if valid location.
 */
bool Game::isLocationInVector(int row, int col, int level)
{
    generateLocationTuples(level);
    for (auto& location : mLocationTuples) {
        if (std::get<0>(location) == row && std::get<1>(location) == col) {
            return true; // Location found in the vector
        }
    }
    return false; // Location not found in the vector
}

/**
 * checks if there exists any digit at that point.
 * @param x col
 * @param y row
 * @return true if a given exists there.
 */
bool Game::GivenExist(int x, int y)
{
    for(auto item: mItems)
    {
        int row = item->GetX()/mTileWidth;
        int col = item->GetY()/mTileHeight;
        if (col == x && row == y)
        {
            return true; // Item exists at the given location (x, y)
        }
    }
    return false; // No item found at the given location (x, y)

}
