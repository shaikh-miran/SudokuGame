/**
 * @file DeclarationXray.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "DeclarationXray.h"
#include "XRay.h"
#include "Game.h"

DeclarationXray::DeclarationXray(wxXmlNode* node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
    node->GetAttribute(L"capacity").ToInt(&mCapacity);
}

void DeclarationXray::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    auto item = std::make_shared<XRay>(game, GetImageName());
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation((col) * game->GetTileWidth(), (row-2) * game->GetTileHeight());

    game->AddItem(item);
}