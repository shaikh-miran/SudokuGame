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