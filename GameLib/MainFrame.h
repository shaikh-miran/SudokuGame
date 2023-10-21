/**
 * @file MainFrame.h

 * @author haile, maui

 * @author haile

 *
 *
 */
#include <iostream>
#include <wx/timer.h>
#include "GameView.h"
#ifndef PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H
#define PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H

class MainFrame :  public wxFrame {

private:
    GameView * mGameView = nullptr;
    wxTimer mUpdateTimer; // Add the update timer

public:
    void Initialize();
    void OnExit(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnAbout(wxCommandEvent& event);

};

#endif //PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H

