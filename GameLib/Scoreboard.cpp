/**
 * @file Scoreboard.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Game.h"
#include <memory>
#include <wx/graphics.h>

using namespace std;

/// Size of the scoreboard text in virtual pixels
const int ScoreboardTextSize = 64;

/// Scoreboard x coordinate
const int ScoreboardX = 10;

/// Scoreboard y coordinate
const int ScoreboardY = 20;

/// The font color to use
const wxColour FontColor = wxColour(255, 255, 255);

/**
 * scoreboard constructor
 */
Scoreboard::Scoreboard()
{
    mTimer.Bind(wxEVT_TIMER, &Scoreboard::UpdateTime, this);
}

/**
 * update time function
 * @param event
 */
void Scoreboard::UpdateTime(wxTimerEvent& event)
{
    if (mSeconds == 60)
    {
        mMinutes++;
        mSeconds = 0;
    }
    ++mSeconds;
}

/**
 * start timer
 *
 */
void Scoreboard::StartTimer()
{
    mTimer.Start(1000);
}

/**
 * stop timer function
 */
void Scoreboard::StopTimer()
{
    mTimer.Stop();
}

/**
 * reset timer function
 */
void Scoreboard::ResetTimer()
{
    mMinutes = 0;
    mSeconds = 0;
}


/**
 * Draw Scoreboard
 * @param gc
 * @param level
 */
void Scoreboard::OnDraw(std::shared_ptr<wxGraphicsContext> gc, Game* level)
{
    if (mStartTimer)
    {
        wxFont font(wxSize(0, ScoreboardTextSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        gc->SetFont(font, FontColor);
        wxString timeString;
        timeString.Printf("%02d:%02d", mMinutes, mSeconds);
        gc->DrawText(timeString, ScoreboardX, ScoreboardY);
    }
}


