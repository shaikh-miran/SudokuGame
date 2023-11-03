/**
 * @file PopUp.cpp
 * @author team prometheus
 */
#include "pch.h"
#include "PopUp.h"


/// Pop up message font size to use
const int PopUpMessageFontSize = 140;

/// The font color to use
const wxColour FontColor = wxColour(30, 250, 36);

/// Screen Width
const int GameWidth = 1440;
/// Screen Height
const int GameHeight = 900;



/**
 *
 * Intro Pop up for each level.
 * @param graphics
 * @param level The current level.
 * @param width width of the frame respective to the level.
 * @param height height of the frame respective to the level.
 */
void PopUp::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int level, int width, int height)
{

    /// rectangle height
    const int rectangleHeight = 320;

/// rectangle Width
    const int rectangleWidth = 700;


    wxPen pen(wxColour(0, 0, 0), 3);
    graphics->SetPen(pen);

    if (level == 2){
        width = 1440;
        height = 960;
    }

    // white box
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->DrawRectangle(width/2 - rectangleWidth/2, height/2 - rectangleHeight/2, rectangleWidth, rectangleHeight);


    // title
    wxFont fontTitle(wxSize(0, 100),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontTitle, wxColour(34, 139, 34));
    // Construct the text string by concatenating the integer
    std::wstring text = L"Level " + std::to_wstring(level) + L" Begin";
    const wchar_t* textCStr = text.c_str();

//    graphics->DrawText(textCStr, 155, 175);
    graphics->DrawText(textCStr,width/2 - rectangleWidth/2 + 28 , height/2 - rectangleHeight/2 + 5);

    // instructions
    wxFont fontInstructions(wxSize(0, 50),
                            wxFONTFAMILY_SWISS,
                            wxFONTSTYLE_NORMAL,
                            wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontInstructions, wxColour(0,0,0));
    graphics->DrawText(L"space: Eat", width/2 - rectangleWidth/2 + 210, height/2 - rectangleHeight/2 + 110);
    graphics->DrawText(L"0-8: Regurgitate", width/2 - rectangleWidth/2 + 160, height/2 - rectangleHeight/2 + 175);
    graphics->DrawText(L"B: Headbutt", width/2 - rectangleWidth/2 + 200, height/2 - rectangleHeight/2 + 240);
}

/**
 * A message that pop ups when an level completed with correct solution.
 * @param graphics
 * @param level the current level
 * @param width width of the frame respective to the level.
 * @param height height of the frame respective to the level.
 */
void PopUp::OnLevelCompletion(std::shared_ptr<wxGraphicsContext> graphics,int level,int width, int height)
{
    if (level == 2){
        width = 1440;
        height = 960;
    }
    wxFont fontTitle(wxSize(0, 100),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontTitle, wxColour(34, 139, 34));
    double textWidth = 0, textHeight = 0;

    graphics->GetTextExtent(L"Level Complete", &textWidth, &textHeight);

    graphics->DrawText("Level Complete !",width/2 - textWidth /2, height/2 );
}

/**
 * A message that pop ups when an incorrect solution.
 * @param graphics
 * @param level the current level
 * @param width width of the frame respective to the level.
 * @param height height of the frame respective to the level.
 */
void PopUp::OnIncorrect(std::shared_ptr<wxGraphicsContext> graphics,int level,int width, int height)
{
    if (level == 2){
        width = 1440;
        height = 960;
    }
    wxFont fontTitle(wxSize(0, 100),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontTitle, wxColour(34, 139, 34));
    double textWidth = 0, textHeight = 0;

    graphics->GetTextExtent(L"Incorrect!", &textWidth, &textHeight);

    graphics->DrawText("Incorrect !",width/2 - textWidth /2, height/2 );
}


/**
 * pop up that is drawn upon sparty being full
 *
 * @param graphics
 * @param level
 * @param width
 * @param height
 */
void PopUp::OnSpartyFull(std::shared_ptr<wxGraphicsContext> graphics, int level, int width, int height)
{
    /// rectangle height
    const int rectangleHeight = 60;

    /// rectangle Width
    const int rectangleWidth = 190;

    wxPen pen(wxColour(0, 0, 0), 3);
    graphics->SetPen(pen);

    if (level == 2){
        width = 1440;
        height = 960;
    }

    // white box
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->DrawRectangle(width/2 - rectangleWidth/2, height/2 - rectangleHeight/2, rectangleWidth, rectangleHeight);


    wxFont fontTitle(wxSize(0, 45),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontTitle, wxColour(255, 0, 0));
    double textWidth = 0, textHeight = 0;

    graphics->GetTextExtent(L"I'm Full!", &textWidth, &textHeight);

    graphics->DrawText("I'm Full!",width/2 - textWidth /2, height/2 - textHeight/2 );

}
