/**
 * @file MessageBox.cpp
 * @author Sonia Charles Thalatoti
 */

#include "MessageBox.h"
void MessageBox::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int level)
{
    // white box
    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxTRANSPARENT_PEN);
    graphics->DrawRectangle(130, 170, 700, 320);

    // black outline
    wxPen linePen(*wxBLACK, 1);
    graphics->SetPen(linePen);
    graphics->StrokeLine(130, 170, 830, 170);
    graphics->StrokeLine(830, 170, 830, 490);
    graphics->StrokeLine(130, 490, 830, 490);
    graphics->StrokeLine(130, 170, 130, 490);

    // title
    wxFont fontTitle(wxSize(0, 100),
                     wxFONTFAMILY_SWISS,
                     wxFONTSTYLE_NORMAL,
                     wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontTitle, wxColour(101, 254, 8));
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
}


