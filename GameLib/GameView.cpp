/**
 * @file GameView.cpp
 * @author haile
 */

#include "pch.h"

#include "GameView.h"
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>

/**
 * Initialize the aquarium view class.
 *
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    // Bind the OnPaint event handler
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);


    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);


//    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnAddSparty, this, IDM_ADDSPARTY);
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
//    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileOpen, this, wxID_OPEN);
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
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();


    mGame.OnDraw(&dc);
}



/**
 * Handle the left mouse button down event
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{
   mGrabbedItem = mGame.HitTest(event.GetX(), event.GetY());
}

/**
* Handle the left mouse button down event
* @param event
*/
void GameView::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the left mouse button down event
* @param event
*/
void GameView::OnMouseMove(wxMouseEvent &event)
{
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to
        // move it while the left button is down.
        if (event.LeftIsDown())
        {
            mGrabbedItem->SetLocation(event.GetX(), event.GetY());
        }
        else
        {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }

        // Force the screen to redraw
        Refresh();
    }
}