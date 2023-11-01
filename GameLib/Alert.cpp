/**
 * @file Alert.cpp
 * @author Navya Singh
 */

#include "Alert.h"
#include "Game.h"

Alert::Alert(Game *game) : mGame(game) {}

void Alert::OnDraw(std::shared_ptr<wxGraphicsContext> graphics)
{
    if (mGame->GetFullMessage()) {
        if (mGame->GetFullTimer().Time() < 3000) {
            wxPen pen(wxColour(0, 0, 0), 3);
            graphics->SetPen(pen);

            // white box
            wxBrush rectBrush(*wxWHITE);
            graphics->SetBrush(rectBrush);
            graphics->DrawRectangle(130, 170, 160, 45);

            // title
            wxFont fontTitle(wxSize(0, 20),
                             wxFONTFAMILY_SWISS,
                             wxFONTSTYLE_NORMAL,
                             wxFONTWEIGHT_BOLD);
            graphics->SetFont(fontTitle, wxColour(255, 0, 0));
            // Construct the text string by concatenating the integer
            std::wstring text = L"I'm Full!";
            const wchar_t* textCStr = text.c_str();

            graphics->DrawText(textCStr, 155, 175);
        } else {
            // Reset the flag and timer when the time is up
            mGame->SetFullMessage(false);
            mGame->StopFullTimer();
        }
    }
}
