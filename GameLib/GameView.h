/**
 * @file GameView.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMEVIEW_H
#define PROJECT1_PROJECT1_GAMEVIEW_H
#include "Sparty.h"
#include "Game.h"

#include <wx/event.h>





#include "Scoreboard.h"


class GameView:  public wxWindow {


private:
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    void OnPaint(wxPaintEvent& event);

    Game mGame;

    Scoreboard mScoreboard; // Include the Scoreboard instance

    wxStopWatch mStopwatch;
    long mTime = 0;

public:
    void OnLevel0(wxCommandEvent& event);
    void OnLevel1(wxCommandEvent& event);
    void OnLevel2(wxCommandEvent& event);
    void OnLevel3(wxCommandEvent& event);
    void SpaceBarPressed(wxKeyEvent &event);

    void UpdateScoreboard(wxTimerEvent& event);




    int mGrabOffsetX; // Relative mouse position X
    int mGrabOffsetY; // Relative mouse position Y


    void Initialize(wxFrame* parent);




    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void OnLeftClick(wxMouseEvent& event);




};

#endif //PROJECT1_PROJECT1_GAMEVIEW_H
