/**
 * @file DeclarationBackground.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "DeclarationBackground.h"
#include "Background.h"
#include "Game.h"

/**
 * DeclarationBackground constructor implementation - takes in a declaration node with name "background", creates an
 * object with initialized image
 * @param node declaration node with name "background" (via GetAttribute)
 */
DeclarationBackground::DeclarationBackground(wxXmlNode *node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
}

/**
 * DeclarationBackground override of Base class Declaration's Create function. Adjusts the function to get attributes
 * that are unique to the "background" item nodes.
 * @param node the "item" node to associate the declaration node with.
 * @param game the Game object that the Item object will reside in.
 */
std::shared_ptr<Item> DeclarationBackground::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;
    /// Get row and column attributes
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);

    /// Get width and height of the Declaration object
    width = GetWidth();
    height = GetHeight();

    /// Create an Background object (base class Item)
    auto item = std::make_shared<Background>(game, GetImageName());

    /// Using the local attributes from above, initialize the parameters of the Item
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation(col * game->GetTileWidth(), (row+1) * game->GetTileHeight() - height);
    //item->SetLocation(col * game->GetTileWidth(), row/game->GetTileHeight());

    /// Once the Item is ready, add it to the Game object's item list
    game->AddItem(item);
    return item;
}
