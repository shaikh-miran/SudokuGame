/**
 * @file GameView.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "GameView.h"
#include "ids.h"
#include "Sparty.h"
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <string>
#include "Solution.h"

using namespace std;

const int FrameDuration = 30;

/**
 * GameView object initializer.
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY,
           wxDefaultPosition, wxDefaultSize,
           wxFULL_REPAINT_ON_RESIZE);

    SetBackgroundStyle(wxBG_STYLE_PAINT);

    // Bind the OnPaint event handler
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    // Bind options to load different levels
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel0, this, IDM_LEVEL_0);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel1, this, IDM_LEVEL_1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel2, this, IDM_LEVEL_2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel3, this, IDM_LEVEL_3);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnSolve, this, IDM_SOLVE);

    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_TIMER,&GameView::OnTimer,this);
    Bind(wxEVT_KEY_DOWN, &GameView::OnKeyPress, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopwatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();
    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());

    auto newTime = mStopwatch.Time();
    auto elapsed = (double)(newTime - mTime)*0.001;
    mTime = newTime;
    mGame.Update(elapsed);
}

/**
 * Handler for level 0 option in file menu
 * @param event Menu event
 */
void GameView::OnLevel0(wxCommandEvent& event)
{
    const wxString filename = L"levels/level0.xml";
    mGame.Load(filename);
    mGame.ChangeStateZero(true);
    Refresh();
}

/**
 * Handler for level 1 option in file menu
 * @param event Menu event
 */
void GameView::OnLevel1(wxCommandEvent& event)
{
    const wxString filename = L"levels/level1.xml";
    mGame.Load(filename);
    mGame.ChangeStateOne(true);
    Refresh();
}

/**
 * Handler for level 2 option in file menu
 * @param event Menu event
 */
void GameView::OnLevel2(wxCommandEvent& event)
{
    const wxString filename = L"levels/level2.xml";
    mGame.Load(filename);
    mGame.ChangeStateTwo(true);
    Refresh();
}

/**
 * Handler for level 3 option in file menu
 * @param event Menu event
 */
void GameView::OnLevel3(wxCommandEvent& event)
{
    const wxString filename = L"levels/level3.xml";
    mGame.Load(filename);
    mGame.ChangeStateThree(true);
    Refresh();
}

/**
 * function to update scoreboard
 * @param event
 */
void GameView::UpdateScoreboard(wxTimerEvent& event)
{
    mScoreboard.UpdateTime(event);
    Refresh();
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
    bool startState = mGame.GetStartState();
    if (!startState)
    {
        mGame.OnLeftDown(event.GetX(), event.GetY());

    }

}

/**
* Handle the key press event
* @param event
*/
void GameView::OnKeyPress(wxKeyEvent &event)
{
    bool startState = mGame.GetStartState();
    if (!startState)
    {
        /// Spacebar pressed
        if (event.GetKeyCode() == WXK_SPACE)
        {
            mGame.SpartyYum();
        }
            /// B pressed
        else if (event.GetUnicodeKey()==L'B'){
            mGame.SpartyHeadButt();
        }
        else if(event.GetUnicodeKey() >= 48 && event.GetUnicodeKey() <= 57)
        {
            int keyPressed = event.GetUnicodeKey() - 48;
            mGame.SpartyRegurgitate(keyPressed);
            if (mGame.GetGridFull()) {
                if (mGame.GetCheckSolution()) {
                    mGame.SetSolutionCorrect(true);
                } else {
                    mGame.SetSolutionIncorrect(true);
                }
            }
        }
    }

}


/**
 * function to refresh game window
 * @param event
 */
void GameView::OnTimer(wxTimerEvent &event)
{
    Refresh();
}

/**
 * Handler for level 0 option in file menu
 * @param event Menu event
 */
void GameView::OnSolve(wxCommandEvent& event)
{
    mGame.GetSolution()->SolveGame(&mGame);
    if (mGame.GetGridFull()) {
        if (mGame.GetCheckSolution()) {
            mGame.SetSolutionCorrect(true);
        } else {
            mGame.SetSolutionIncorrect(true);
        }
    }
}
