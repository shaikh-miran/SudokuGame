/**
 * @file GameView.cpp
 * @author haile
 */

#include "pch.h"


#include "GameView.h"
#include "ids.h"


#include "Sparty.h"
#include "XRay.h"


#include "ids.h"
#include "GameView.h"
#include "Sparty.h"

#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <string>

using namespace std;

const int FrameDuration = 30;

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

    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
    Bind(wxEVT_TIMER,&GameView::OnTimer,this);
    //Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftClick,this);
    //mouth moving
    Bind(wxEVT_KEY_DOWN, &GameView::SpaceBarPressed, this);

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


    // Clear the image to black


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

/**
 * Handle the left mouse button down event
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{

    mGame.OnLeftDown(event.GetX(), event.GetY());

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
//    // See if an item is currently being moved by the mouse
//    if (mGrabbedItem != nullptr)
//    {
//
//
//        if (event.LeftIsDown())
//
////
//        if (event.GetX() == 72 && event.GetY() == 24)
//
//        {
//            mGrabbedItem = nullptr;
//        }
//        else
//        {
//            mGrabbedItem->SetLocation(event.GetX() - mGrabOffsetX, event.GetY() - mGrabOffsetY);
//        }
//
//        // Force the screen to redraw
//        Refresh();
}
//}
void GameView::OnLeftClick(wxMouseEvent &event)
{
    // Check if an item was clicked
    mGrabbedItem = mGame.HitTest(event.GetX(), event.GetY());

    // If an item is clicked, store its position relative to the mouse
    if (mGrabbedItem != nullptr)
    {
        mGrabOffsetX = event.GetX() - mGrabbedItem->GetX();
        mGrabOffsetY = event.GetY() - mGrabbedItem->GetY();
    }

}

///moving mouth
/**
* Handle the space bar event
* @param event
*/
void GameView::SpaceBarPressed(wxKeyEvent &event)
{
    if (event.GetKeyCode() == WXK_SPACE)
    {
        std::shared_ptr<Sparty> sparty = mGame.GetSparty();
        sparty->SetMouthPivot(wxPoint(30,86));
        sparty->SetMouthAngle(0.8);

    }
}

void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}
