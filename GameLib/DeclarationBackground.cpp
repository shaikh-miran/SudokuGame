/**
 * @file DeclarationBackground.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "DeclarationBackground.h"
#include "Background.h"
#include "Game.h"

DeclarationBackground::DeclarationBackground(wxXmlNode *node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
}

void DeclarationBackground::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    auto item = std::make_shared<Background>(game, GetImageName());
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation(col, row);

    game->AddItem(item);
}