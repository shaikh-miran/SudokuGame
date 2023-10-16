/**
 * @file MainFrame.h

 * @author haile, maui

 * @author haile

 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H
#define PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H

class GameView;

class MainFrame :  public wxFrame {

private:
    GameView * mGameView;


    wxTimer mUpdateTimer; // Add the update timer

public:
    void Initialize();


    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

};

#endif //PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H
