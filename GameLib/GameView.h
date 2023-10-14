/**
 * @file GameView.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_GAMELIB_GAMEVIEW_H
#define PROJECT1_GAMELIB_GAMEVIEW_H

#include "Game.h"
#include "Scoreboard.h"
#include <wx/dcbuffer.h>

class GameView:  public wxWindow {
private:
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    void OnPaint(wxPaintEvent& event);
    Game mGame;

    Scoreboard mScoreboard; // Include the Scoreboard instance
public:
    void Initialize(wxFrame*);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void UpdateScoreboard(wxTimerEvent& event);
};

#endif //PROJECT1_GAMELIB_GAMEVIEW_H
