/**
 * @file DeclarationSparty.cpp
 * @author Maui Baba
 */

#include "pch.h"
#include "DeclarationSparty.h"
#include "Sparty.h"
#include "Game.h"

/**
 * Constructor
 * @param node the XML node that contains the data for the sparty object
 */
DeclarationSparty::DeclarationSparty(wxXmlNode* node) : Declaration(node)
{
    mImage1 = L"images/" + node->GetAttribute(L"image1").ToStdWstring();
    mImage2 = L"images/" + node->GetAttribute(L"image2").ToStdWstring();
}

/**
 * Applies xml data to the sparty object/item. Adds sparty to the associated game item list.
 * @param node
 * @param game
 */
void DeclarationSparty::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);

    width = GetWidth();
    height = GetHeight();

    auto item = std::make_shared<Sparty>(game, GetImage1Name(), GetImage2Name());
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation((col) * game->GetTileWidth(), (row) * game->GetTileHeight());

    game->SetSparty(item);

    game->AddItem(item);
}