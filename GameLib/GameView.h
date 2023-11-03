/**
 * @file GameView.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_PROJECT1_GAMEVIEW_H
#define PROJECT1_PROJECT1_GAMEVIEW_H

#include "Sparty.h"
#include "Game.h"
#include <wx/event.h>
#include "Scoreboard.h"
#include "Alert.h"

/**
 * GameView class - Handles user input, does the back end of displaying items and window. Also handles menu bar options.
 */
class GameView:  public wxWindow {
private:
    /// Game object associated with this
    Game mGame;

    /// Inclusion of the Game's scoreboard instance
    Scoreboard mScoreboard;

    /// Stopwatch that keeps track of the time
    wxStopWatch mStopwatch;

    /// Start time (default 0)
    long mTime = 0;

    /// The timer that allows for animation
    wxTimer mTimer;

    //headbutting
    std::unique_ptr<Sparty> spartyInstance;

public:
    /// Relative mouse x-pos
    int mGrabOffsetX;

    /// Relative mouse y-pos
    int mGrabOffsetY;

    /// Handles Paint event, draws the window
    void OnPaint(wxPaintEvent& event);
    
    /// Handler for when Level 0 is clicked in the menu bar
    void OnLevel0(wxCommandEvent& event);

    /// Handler for when Level 1 is clicked in the menu bar
    void OnLevel1(wxCommandEvent& event);

    /// Handler for when Level 2 is clicked in the menu bar
    void OnLevel2(wxCommandEvent& event);

    /// Handler for when Level 3 is clicked in the menu bar
    void OnLevel3(wxCommandEvent& event);

    /// function to solve level
    void OnSolve(wxCommandEvent& event);

    /// Handler for key presses
    void OnKeyPress(wxKeyEvent &event);

    /// Handler for left click down
    void OnLeftDown(wxMouseEvent &event);

    /// Initializes the GameView object
    void Initialize(wxFrame* parent);

    /// Update the time of the scoreboard
    void UpdateScoreboard(wxTimerEvent& event);

    /// function for intro screen timer
    void IntroScreenTimer(wxTimerEvent& event);


    /// Handles the Timer event
    void OnTimer(wxTimerEvent& event);

    /// Stops the member timer object
    void Stop(){ mTimer.Stop(); }

};

#endif //PROJECT1_PROJECT1_GAMEVIEW_H
