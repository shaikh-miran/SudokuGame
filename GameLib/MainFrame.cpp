/**
 * @file MainFrame.cpp
 * @author haile
 */
#include "pch.h"
#include "ids.h"
#include "MainFrame.h"
#include "GameView.h"

void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Game", wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto gameView = new GameView();
    gameView->Initialize(this);

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
    fileMenu->Append(IDM_SOLVE, "&Solve", "please help me i need help waahah");
    /// ^^^ no solve implementation yet
    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);


    // Add options to levelMenu dropdown
    levelMenu->Append(IDM_LEVEL_0, L"&Level 0", "Change levels");
    levelMenu->Append(IDM_LEVEL_1, L"&Level 1", "Change levels");
    levelMenu->Append(IDM_LEVEL_2, L"&Level 2", "Change levels");
    levelMenu->Append(IDM_LEVEL_3, L"&Level 3", "Change levels");
    /// ^^^ no level load implementations yet


    // Add options to helpMenu
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);


    // Set the Menu Bar
    SetMenuBar(menuBar);


    // Create the update timer
    mUpdateTimer.Bind(wxEVT_TIMER, [this, gameView](wxTimerEvent& event) {
        // Update the Scoreboard
        gameView->UpdateScoreboard(event);
    });
    mUpdateTimer.Start(1000); // Start the timer to update every second


    // Add it to the sizer
   // sizer->Add(gameView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    //SetSizer( sizer );

    // Layout (place) the child windows.
   // Layout();

//    auto menuBar = new wxMenuBar( );
//
//    auto fileMenu = new wxMenu();
//    auto helpMenu = new wxMenu();
//    auto fishMenu = new wxMenu();
//
//    menuBar->Append(fileMenu, L"&File" );
//    menuBar->Append(fishMenu, L"&Add Fish");
//    menuBar->Append(helpMenu, L"&Help");
//
//    fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open aquarium file...");
//    fishMenu->Append(IDM_ADDFISHBETA, L"&Beta Fish", L"Add a Beta Fish");
//    fishMenu->Append(IDM_ADDcatfish, L"&Catfish", L"Add a catish MREOWWW");
//    fishMenu->Append(IDM_ADDcarp, L"&Carp", L"Add a CRAP");
//    fishMenu->Append(IDM_ADDDecorCastle, L"&Castle", L"Add a castle");
//
//
//    fileMenu->Append(wxID_EXIT, "&Exit\tAlt-X", "Quit this program");
//    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
//    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save aquarium as...");
//    // fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open aquarium file...");
//
//    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
//
//    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
//
//
//    SetMenuBar( menuBar );
//
//    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );


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
