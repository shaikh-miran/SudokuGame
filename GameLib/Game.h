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
#include "ItemContainer.h"
#include "MessageBox.h"
#include "Visitor.h"
#include "XRayVisitor.h"

/// Forward declaration of class Item
class Item;

/// Forward declaration of class ParseXML
class ParseXML;

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


    double mClickY = -1;
    double mClickX = -1;
    double mWidth;
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


    std::shared_ptr<ItemContainer> mContainer;

    /// The timer that allows for intro screen
    wxTimer mIntroScreenTimer;

    wxTimer mGameTimer;

    /// An object that describes the intro screen
    //MessageBox mMessageBox;

    bool mIntroScreenVisible = true;
    std::mt19937 mRandom;

public:

    ItemDigit* mYummyTile = nullptr;

    void Accept(Visitor * visitor);

    void SpartyYum();

    void SpartyHeadButt();

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
     * Set the Game's associated Container object (shared ptr)
     * @param Container pointer to set
     */
    void SetContainer(std::shared_ptr<ItemContainer> container) { mContainer = container; }

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
     * Get the Game's Container object
     * @return Container shared pointer
     */
    std::shared_ptr<ItemContainer> GetContainer() { return mContainer; }

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

};

#endif //CSE335PROJECTONE_PROJECT1_GAME_H

