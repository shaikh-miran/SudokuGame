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
    void OnPaint(wxPaintEvent& event);
    Game mGame;

public:
    void Initialize(wxFrame*);
    void OnLevel0(wxCommandEvent& event);
    void OnLevel1(wxCommandEvent& event);
    void OnLevel2(wxCommandEvent& event);
    void OnLevel3(wxCommandEvent& event);
};

#endif //PROJECT1_PROJECT1_GAMEVIEW_H
