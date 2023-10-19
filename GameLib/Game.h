/**
 * @file Game.h
 * @author haile
 *
 *
 */


#ifndef CSE335PROJECTONE_PROJECT1_GAME_H
#define CSE335PROJECTONE_PROJECT1_GAME_H
#include "pch.h"
#include "Sparty.h"

#include "Scoreboard.h"
#include <vector>
#include "XRay.h"
#include <memory> //shared_ptr
#include <random>
#include "Item.h"
#include "ParseXML.h"
#include "Declaration.h"
#include <wx/xml/xml.h>
#include <wx/graphics.h>

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

    std::vector<std::shared_ptr<Declaration>> mDeclarations;

    double mClickY = 200;
    double mClickX = 200;

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

//    /// All of the items to populate our aquarium
//    std::vector<std::shared_ptr<Item>> mItems;

//mouth open close
    std::shared_ptr<Sparty> GetSparty() { return mSparty; }
    void AddItem(std::shared_ptr<Item> item);
    void AddDeclaration(std::shared_ptr<Declaration> dec);
};

#endif //CSE335PROJECTONE_PROJECT1_GAME_H
