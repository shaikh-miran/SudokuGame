/**
 * @file GameView.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMEVIEW_H
#define PROJECT1_PROJECT1_GAMEVIEW_H

#include "Game.h"

class GameView:  public wxWindow {


private:
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    void OnPaint(wxPaintEvent& event);
    Game mGame;

public:


    void Initialize(wxFrame*);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
};

#endif //PROJECT1_PROJECT1_GAMEVIEW_H
