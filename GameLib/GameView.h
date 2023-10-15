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
#include "Scoreboard.h"

class GameView:  public wxWindow {


private:
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    void OnPaint(wxPaintEvent& event);

//    std::shared_ptr<Sparty> mClickedItem;

    Game mGame;

    Scoreboard mScoreboard; // Include the Scoreboard instance

    int mGrabOffsetX; // Relative mouse position X
    int mGrabOffsetY; // Relative mouse position Y

public:


    void Initialize(wxFrame*);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void OnLeftClick(wxMouseEvent& event);
    void UpdateScoreboard(wxTimerEvent& event);

    void OnLevel0(wxCommandEvent& event);
    void OnLevel1(wxCommandEvent& event);
    void OnLevel2(wxCommandEvent& event);
    void OnLevel3(wxCommandEvent& event);


};

#endif //PROJECT1_PROJECT1_GAMEVIEW_H
