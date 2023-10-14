/**
 * @file GameView.cpp
 * @author haile
 */

#include "pch.h"

#include "GameView.h"
#include "ids.h"

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

/**
 * Initialize the aquarium view class.
 *
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

//    Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
//    Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
//    Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
//    Bind(wxEVT_TIMER, &AquariumView::AddTimer, this);
//
//    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
//    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddcatfishFish, this, IDM_ADDcatfish);
//    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddcarpFish, this, IDM_ADDcarp);
//    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddDecorCastle, this, IDM_ADDDecorCastle);
//    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileSaveAs, this, wxID_SAVEAS);
//
//    mTimer.SetOwner(this);
//    mTimer.Start(FrameDuration);
//
//    mStopWatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());

//    // Draw the scoreboard
//    mScoreboard.OnDraw(gc);



}

/**
 * Handler for level 0 option in file menu
 * @param event Menu event
 */
void GameView::OnLevel0(wxCommandEvent& event)
{
    const wxString filename = L"levels/level0.xml";
    mGame.Load(filename);
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
    Refresh();
}


void GameView::UpdateScoreboard(wxTimerEvent& event)
{
    mScoreboard.UpdateTime(event);
    Refresh();
}
