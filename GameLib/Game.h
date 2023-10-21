/**
 * @file Game.h
 * @author haile
 *
 *
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

class Item;
class ParseXML;

class Game
{
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    ///Scale double variable
    double mScale;
    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;

    double mClickY = 200;
    double mClickX = 200;

    double mHeight;
    double mWidth;
    double mTileHeight;
    double mTileWidth;

    ///Y and X offset doubles
    double mXOffset;
    ///Y and X offset doubles
    double mYOffset;

    Scoreboard mScoreboard;

    std::shared_ptr<Sparty> mSparty;

    /// ParseXML object, handles the loading of the level


public:

    double GetClickX(){return mClickX;}
    double GetClickY(){return mClickY;}

    void Update(double elapsed);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    Game();
    std::shared_ptr<Item> HitTest(int x, int y);
    void Load(const wxString & filename);
    void OnLeftDown(int x, int y);
    void Clear();

    void SetHeight(double height) { mHeight = height; }
    void SetWidth(double width) { mWidth = width; }
    void SetTileHeight(double height) { mTileHeight = height; }
    void SetTileWidth(double width) { mTileWidth = width; }
    void SetSparty(std::shared_ptr<Sparty> sparty) { mSparty = sparty; }

    double GetTileWidth() { return mTileWidth; }
    double GetTileHeight() { return mTileHeight; }
    Scoreboard * GetScoreboard() { return &mScoreboard; }

    std::shared_ptr<Sparty> GetSparty() { return mSparty; }
    void AddItem(std::shared_ptr<Item> item);
};

#endif //CSE335PROJECTONE_PROJECT1_GAME_H
