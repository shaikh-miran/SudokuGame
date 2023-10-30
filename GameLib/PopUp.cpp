/**
 * @file PopUp.cpp
 * @author team prometheus
 */

#include "PopUp.h"


/// Pop up message font size to use
const int PopUpMessageFontSize = 140;

/// The font color to use
const wxColour FontColor = wxColour(30, 250, 36);

/// Screen Width
const int GameWidth = 1440;
/// Screen Height
const int GameHeight = 900;

/// Score label Y location
const int ScoreLabelY = 100;


void PopUp::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int level)
{
    wxPen pen(wxColour(0, 0, 0), 3);
    graphics->SetPen(pen);

    // white box
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->DrawRectangle(130, 170, 700, 320);



    // title
    wxFont fontTitle(wxSize(0, 100),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontTitle, wxColour(34, 139, 34));
    // Construct the text string by concatenating the integer
    std::wstring text = L"Level " + std::to_wstring(level) + L" Begin";
    const wchar_t* textCStr = text.c_str();

    graphics->DrawText(textCStr, 155, 175);

    // instructions
    wxFont fontInstructions(wxSize(0, 50),
                            wxFONTFAMILY_SWISS,
                            wxFONTSTYLE_NORMAL,
                            wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontInstructions, wxColour(0,0,0));
    graphics->DrawText(L"space: Eat", 350, 300);
    graphics->DrawText(L"0-8: Regurgitate", 280, 365);
    graphics->DrawText(L"B: Headbutt", 325, 430);

    wxFont labelFont(wxSize(0, PopUpMessageFontSize),
                     wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
    graphics->SetFont(labelFont, FontColor);

    double textWidth = 0, textHeight = 0;


    if (level == 0){


    } else if (level == 1){

//        long rectangleWidth = 700;
//        long rectangleHeight = 300;
//
////        long rectangleX = (GameWidth/2) - (rectangleWidth);
//        long rectangleX = (GameWidth) - (rectangleWidth/2);
//        long rectangleY = (GameHeight/2) - (rectangleHeight/2);
//
//
//
//
//        wxBrush brush(wxColour(255, 255, 255));
//        graphics->SetBrush(brush);
//        graphics->DrawRectangle(rectangleX, rectangleY, rectangleWidth, rectangleHeight);
//
//
//
//
//        /// The font color to use for green level message
//        const wxColour FontColorGreen = wxColour(34, 139, 34);
//
//        /// Pop up message font size to use
//        const int PopUpMessageFontSize = 80;
//
//        wxFont labelFont(wxSize(0, PopUpMessageFontSize),
//                         wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
//        graphics->SetFont(labelFont, FontColorGreen);
//
//        graphics->GetTextExtent(L"Level 1 Begin", &textWidth, &textHeight);
//        graphics->DrawText(L"Level 1 Begin", rectangleX + 40 , rectangleY + 10);
//
//
//
//        /// The font color to use for black following text
//        const wxColour FontColorBlack = wxColour(0, 0, 0);
//
//        /// Pop up message font size to use
//        const int PopUpMessageFontSizeBlackText = 50;
//
//
//        wxFont labelFontBlackText(wxSize(0, PopUpMessageFontSizeBlackText),
//                                  wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL);
//        graphics->SetFont(labelFontBlackText, FontColorBlack);
//
//        graphics->GetTextExtent(L"space: Eat", &textWidth, &textHeight);
//        graphics->DrawText(L"space: Eat", rectangleX + 130 , rectangleY + 90);
//


    }

    if(level == -1){
        graphics->GetTextExtent(L"Level Complete", &textWidth, &textHeight);
        graphics->DrawText(L"Level Complete", GameWidth / 2 - textWidth / 2, GameHeight / 2);
    }
}

