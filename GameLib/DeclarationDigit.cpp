/**
 * @file DeclarationDigit.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "DeclarationDigit.h"
#include "ItemDigit.h"
#include "Game.h"

DeclarationDigit::DeclarationDigit(wxXmlNode* node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
    node->GetAttribute(L"value", L"0").ToInt(&mValue);
}

void DeclarationDigit::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    auto item = std::make_shared<ItemDigit>(game, GetImageName());
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation(col * game->GetTileWidth(), row * game->GetTileHeight());

    game->AddItem(item);
}