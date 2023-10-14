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

class GameView:  public wxWindow {


private:
    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    void OnPaint(wxPaintEvent& event);

//    std::shared_ptr<Sparty> mClickedItem;

    Game mGame;

    int mGrabOffsetX; // Relative mouse position X
    int mGrabOffsetY; // Relative mouse position Y

public:


    void Initialize(wxFrame*);
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
    void OnLeftClick(wxMouseEvent& event);
};

#endif //PROJECT1_PROJECT1_GAMEVIEW_H
