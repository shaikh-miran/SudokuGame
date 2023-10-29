/**
 * @file MainFrame.cpp

 * @author haile, maui

 * @author haile

 */
#include "pch.h"
#include "ids.h"
#include "MainFrame.h"
#include "GameView.h"


/**
 * Initializes a game window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Game", wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    mGameView = new GameView();
    mGameView->Initialize(this);

    sizer->Add(mGameView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    // Create Menu Bar
    auto menuBar = new wxMenuBar();


    // Create Menu Bar options
    auto fileMenu = new wxMenu;
    auto levelMenu = new wxMenu;
    auto helpMenu = new wxMenu;


    // Add options to Menu Bar
    menuBar->Append(fileMenu, L"File");
    menuBar->Append(levelMenu, L"Level");
    menuBar->Append(helpMenu, L"Help");

    // Add options to fileMenu dropdown
    fileMenu->Append(IDM_SOLVE, "&Solve", "Solution");
    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");

    // Add options to levelMenu dropdown
    levelMenu->Append(IDM_LEVEL_0, L"&Level 0", "Change levels");
    levelMenu->Append(IDM_LEVEL_1, L"&Level 1", "Change levels");
    levelMenu->Append(IDM_LEVEL_2, L"&Level 2", "Change levels");
    levelMenu->Append(IDM_LEVEL_3, L"&Level 3", "Change levels");

    // Add options to helpMenu
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    // Set the Menu Bar
    SetMenuBar(menuBar);
    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
}

/**
* Exit menu option handlers
* @param event
*/
void MainFrame::OnExit(wxCommandEvent& event)
{
    //mGameView->Stop(); ///< We might need to add this line if we implement a timer.
    Close(true);
}

void MainFrame::OnClose(wxCloseEvent& event)
{

    mGameView->Stop();
    Destroy();
}

/**
*  "About" menu option handler
 *  @param event
*/
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(L"Built by Prometheus",
                 L"Action Sudoku",
                 wxOK | wxCENTRE,
                 this);
}
