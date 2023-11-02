/**
 * @file DeclarationGiven.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "DeclarationGiven.h"
#include "ItemGiven.h"
#include "Game.h"

/**
 * DeclarationGiven constructor implementation - takes in a declaration node with name "given", creates an
 * object with initialized image and given value
 * @param node declaration node with name "given" (via GetAttribute)
 */
DeclarationGiven::DeclarationGiven(wxXmlNode* node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
    node->GetAttribute(L"value", L"0").ToInt(&mValue);
}

/**
 * DeclarationGiven override of Base class Declaration's Create function. Adjusts the function to get attributes
 * that are unique to the "given" item nodes.
 * @param node the "item" node to associate the declaration node with.
 * @param game the Game object that the Item object will reside in.
 */
std::shared_ptr<Item> DeclarationGiven::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;

    /// Get row, column, width and height attributes
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    /// Create an ItemGiven object (base class Item)
    auto item = std::make_shared<ItemGiven>(game, GetImageName());

    /// Using the local attributes from above, initialize the parameters of the Item
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation((col) * game->GetTileWidth(), (row) * game->GetTileHeight());

    /// Once the Item is ready, add it to the Game object's item list
    game->AddItem(item);
    return item;
}