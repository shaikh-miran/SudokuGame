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


void Game::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);
    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
   // dc->DrawText(L"Under the Sea!", 10, 10);

//    for (auto item : mItems)
//    {
//        item->Draw(dc);
//    }
}

void Game::Load(const wxString & filename) {
    wxXmlDocument inputDoc;
    if(!inputDoc.Load(filename))
    {
        wxMessageBox(L"Error loading file: check levels folder.");
        return;
    }

    /// Parse through inputDoc
    /// Clear any progress, anything on the board
    /// delete the current level, create a new level
}