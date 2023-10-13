/**
 * @file Scoreboard.cpp
 * @author Navya Singh
 */

#include "Scoreboard.h"

/// Size of the scoreboard text in virtual pixels
const int ScoreboardTextSize = 64;

/// Top left corner of the scoreboard in virtual pixels
const wxPoint ScoreboardTopLeft(10, 10);

Scoreboard::Scoreboard()
{
    timer.Bind(wxEVT_TIMER, &Scoreboard::UpdateTime, this);
}

void Scoreboard::UpdateTime(wxTimerEvent& event)
{
    if (seconds == 60)
    {
        minutes++;
        seconds = 0;
    }
    ++seconds;
}

void Scoreboard::StartTimer()
{
    timer.Start(1000);
}

void Scoreboard::StopTimer()
{
    timer.Stop();
}

void Scoreboard::ResetTimer()
{
    minutes = 0;
    seconds = 0;
}

void Scoreboard::Draw(wxDC* dc)
{
    wxFont font(wxSize(0, ScoreboardTextSize), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(255, 255, 255)); // Text color

    wxString timeString;
    timeString.Printf("%02d:%02d", minutes, seconds);

    dc->DrawText(timeString, ScoreboardTopLeft);
}

