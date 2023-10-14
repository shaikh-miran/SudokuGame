/**
 * @file MainFrame.h
 * @author haile, maui
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H
#define PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H

class GameView;

class MainFrame :  public wxFrame {

private:
    GameView * mGameView;

    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

public:
    void Initialize();
};

#endif //PROJECT1_PROJECT1_GAMELIB_MAINFRAME_H
