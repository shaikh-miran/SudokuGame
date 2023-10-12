/**
 * @file Game.cpp
 * @author hailey cohen
 */
#include "pch.h"
#include "Game.h"

using namespace std;

/**
 * Game Constructor
 */
Game::Game()

{
    mBackground = make_unique<wxBitmap>(
        L"images/background.png", wxBITMAP_TYPE_ANY);




}