/**
 * @file Game.h
 * @author Team Prometheus
 */


#ifndef CSE335PROJECTONE_PROJECT1_GAME_H
#define CSE335PROJECTONE_PROJECT1_GAME_H

#include "Sparty.h"
#include "Scoreboard.h"
#include "XRay.h"
#include "Item.h"
#include "ParseXML.h"
#include "Declaration.h"
#include <memory> //shared_ptr
#include <random>
#include <vector>
#include <wx/xml/xml.h>
#include <wx/graphics.h>
#include <map>
#include "Visitor.h"
#include "XRayVisitor.h"
#include "PopUp.h"
#include "Solution.h"
#include "Background.h"
#include "BackgroundVisitor.h"

/// Forward declaration of class Item
class Item;

/// Forward declaration of class ParseXML
class ParseXML;

class ItemContainer;
/**
 * Class Game - Holds the game board data, keeps track of time via Scoreboard, and handles game loading, game/UI
 * interaction.
 */
class Game
{
private:
    /// Scale double variable
    double mScale;

    /// Vector to store all of the items to be drawn and interacted with in the game
    std::vector<std::shared_ptr<Item>> mItems;


    /// member variable for click x
    double mClickY = -1;

    /// member variable for click y
    double mClickX = -1;

    /// member variable for width
    double mWidth;

    /// member variable for height
    double mHeight;


    /// Tile width
    double mTileHeight;

    /// Tile Height
    double mTileWidth;

    ///Y and X offset doubles
    double mXOffset;
    ///Y and X offset doubles
    double mYOffset;

    /// Scoreboard; keeps track of time from when the game begins
    Scoreboard mScoreboard;

    /// Sparty object saved in order to associate the game to it.
    std::shared_ptr<Sparty> mSparty;

    /// background object
    std::shared_ptr<Background> mBackground;

    /// xRay object
    std::shared_ptr<XRay> mXray;

    /// The timer that allows for intro screen
    wxTimer mIntroScreenTimer;

    /// game timer variable
    wxTimer mGameTimer;

    /// bool that is true when intro screen visible
    bool mIntroScreenVisible = true;

    /// random seed
    std::mt19937 mRandom;

    ///Duration
    double mDuration = 0;

    /// Status Starting
    bool mStartState = true;

    /// bool for if sparty full message displayed
    bool mFullMessage = false;

    /// bool for if something is already there message displayed
    bool mWrongLocationMessage = false;

    /// double duration for full message
    double mDurationFullMessage = 0;

    /// Status Ending
    bool mEndState = false;
    /// Current Level
    long mCurrentLevel = 1;

    /// is sparty full
    bool mSpartyFull = false;
    /// is a given exist in the location.
    bool mGivenExists = false;

    int mSolutionCorrect = false;
    int mSolutionIncorrect = false;

    /// Stopwatch for pop up message
    wxStopWatch mStopWatchPopUp;

    /// stopwatch for pop up sparty is full message
    wxStopWatch mStopWatchSpartyFull;

    /// stopwatch for pop up somethign is there.
    wxStopWatch mStopWatchWrongLocation;

    /// pop up message
    PopUp mPopUpMessage;

    /// full timer stopwatch
    wxStopWatch mFullTimer;

    /// solution instance
    Solution * mSolution = new Solution();

    /// vector of tuples of int, int - contains locations
    std::vector<std::tuple<int, int>> mLocationTuples = {};

public:
    void Accept(Visitor * visitor);

    /// function that makes sparty eat digits
    void SpartyYum();

    /// function that regurgitates a number from xray to a location
    void SpartyRegurgitate(long keyPressed);


    /// function that makes sparty headbutt
    void SpartyHeadButt();

    /// function that calls pop up draws on different occasions
    void CallPopUpDraw(std::shared_ptr<wxGraphicsContext> graphics);


    /// Constructor
    Game();

    /// Update the game (on-demand)
    void Update(double elapsed);

    /// Handles items to be drawn on the game window
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    /// Returns whether or not an item exists at the current cursor location
    std::shared_ptr<Item> HitTest(int x, int y);

    /// Start the level loading process, given the desired level filename
    void Load(const wxString & filename);

    /// Handles left click event - force Sparty object to move to the clicked location
    void OnLeftDown(int x, int y);

    /// Clear the game data - deletes all known items in the game.
    void Clear();

    /// Add the Item from item parameter into the Game object's mItems list
    void AddItem(std::shared_ptr<Item> item);

    /**
     * Return the x-position of the click event
     * @return x value of the position
     */
    double GetClickX(){return mClickX;}

    /**
     * Return the y-position of the click event
     * @return y value of the position
     */
    double GetClickY(){return mClickY;}

    /**
     * Set the Game height
     * @param height double input to set
     */
    void SetHeight(double height) { mHeight = height; }

    /**
     * Set the Game width
     * @param width double input to set
     */
    void SetWidth(double width) { mWidth = width; }

    /**
     * Set the Game's tile height
     * @param height double input to set
     */
    void SetTileHeight(double height) { mTileHeight = height; }

    /**
     * Set the Game's tile width
     * @param width double input to set
     */
    void SetTileWidth(double width) { mTileWidth = width; }

    /**
     * Set the Game's associated Sparty object (shared ptr)
     * @param sparty pointer to set
     */
    void SetSparty(std::shared_ptr<Sparty> sparty) { mSparty = sparty; }

    /**
    * sets the x-position of the click event
    * @return x value of the position
    */
    double SetClickX(double clickedX){return mClickX = clickedX;}

    /**
     * sets the y-position of the click event
     * @return y value of the position
     */
    double SetClickY(double clickedY){return mClickY = clickedY;}

    /**
     * Get the tile width
     * @return tile width (double)
     */
    double GetTileWidth() { return mTileWidth; }

    /**
     * Get the tile height
     * @return tile height (double)
     */
    double GetTileHeight() { return mTileHeight; }

    /**
     * Get the Game's scoreboard object
     * @return Scoreboard object reference
     */
    Scoreboard * GetScoreboard() { return &mScoreboard; }

    /**
     * Get the Game's Sparty object
     * @return Sparty shared pointer
     */
    std::shared_ptr<Sparty> GetSparty() { return mSparty; }

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    /**
     * Gets the width of the item.
     * @return width
     */
    double GetWidthB() {return mWidth;}

    /**
     * Gets the height of the item.
     * @return height
     */
    double GetHeightB() {return mWidth;}


    /// change game state to level 0
    void ChangeStateZero(bool starting);

    /// change game state to level 1
    void ChangeStateOne(bool starting);

    /// change game state to level 2
    void ChangeStateTwo(bool starting);

    /// change game state to level 3
    void ChangeStateThree(bool starting);

    /**
     * getter for full message
     * @return
     */

    /**
     * getter for solution
     * @return
     */
    Solution * GetSolution() { return mSolution; };

    /// getter for mStartState
    bool GetStartState(){return mStartState;}

    /// function that generates tuple locations
    void generateLocationTuples(int level);

    /// function that checks if location in vector
    bool isLocationInVector(int row, int col, int level);

    /// checks if given exists
    bool GivenExist(int x, int y);

    bool GetGridFull() { return mSolution->GridFull(this); }
    bool GetCheckSolution() { return mSolution->CheckSolution(this); }

    void SetSolutionCorrect(bool setCorrect) { mSolutionCorrect = setCorrect; }
    void SetSolutionIncorrect(bool setIncorrect) { mSolutionIncorrect = setIncorrect; }
};

#endif //CSE335PROJECTONE_PROJECT1_GAME_H

