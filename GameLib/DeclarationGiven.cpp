/**
 * @file DeclarationGiven.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "DeclarationGiven.h"
#include "ItemGiven.h"
#include "Game.h"

DeclarationGiven::DeclarationGiven(wxXmlNode* node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
    node->GetAttribute(L"value", L"0").ToInt(&mValue);
}

void DeclarationGiven::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    auto item = std::make_shared<ItemGiven>(game, GetImageName());
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation((col) * game->GetTileWidth(), (row+0.25) * game->GetTileHeight());

    game->AddItem(item);
}