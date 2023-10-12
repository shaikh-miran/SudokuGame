/**
 * @file MainFrame.cpp
 * @author haile
 */
#include "pch.h"
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