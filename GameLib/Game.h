/**
 * @file Game.h
 * @author haile
 *
 *
 */


#ifndef CSE335PROJECTONE_PROJECT1_GAME_H
#define CSE335PROJECTONE_PROJECT1_GAME_H
#include "pch.h"
#include <vector>
#include<memory> //shared_ptr
#include <random>
///#include "Item.h"


#include <wx/xml/xml.h>

class Game
{
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

public:
    Game();

};

#endif //CSE335PROJECTONE_PROJECT1_GAME_H
