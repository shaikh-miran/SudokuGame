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


/**
 * main frame class
 * draws the window
 */
class MainFrame :  public wxFrame {

private:
    /// game view instance
    GameView * mGameView = nullptr;

    /// update timer
    wxTimer mUpdateTimer; // Add the update timer

public:
    /// initialize window function
    void Initialize();

    /// on exit event handler
    void OnExit(wxCommandEvent& event);

    /// on close event handler
    void OnClose(wxCloseEvent& event);

    /// on about event handler
    void OnAbout(wxCommandEvent& event);

};

#endif //PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H

