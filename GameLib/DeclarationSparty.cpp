/**
 * @file DeclarationSparty.cpp
 * @author Team Prometheus
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
 * @param node the "item" node to associate the declaration node with.
 * @param game the Game object that the Item object will reside in.
 */
void DeclarationSparty::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;

    /// Get row column, width and height attributes
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);

    width = GetWidth();
    height = GetHeight();

    /// Create Sparty object (base class Item)
    auto item = std::make_shared<Sparty>(game, GetImage1Name(), GetImage2Name());

    /// Using the local attributes from above, initialize the parameters of the Item
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation((col) * game->GetTileWidth(), (row) * game->GetTileHeight());

    /// Call Game::SetSparty to add the Sparty pointer to the associated Game object
    game->SetSparty(item);

    /// Once the Item is ready, add it to the Game object's item list
    game->AddItem(item);
}