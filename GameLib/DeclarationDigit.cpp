/**
 * @file DeclarationDigit.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "DeclarationDigit.h"
#include "ItemDigit.h"
#include "Game.h"

/**
 * DeclarationDigit constructor implementation - takes in a declaration node with name "digit", creates an
 * object with initialized image and digit value
 * @param node declaration node with name "digit" (via GetAttribute)
 */
DeclarationDigit::DeclarationDigit(wxXmlNode* node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
    node->GetAttribute(L"value", L"0").ToInt(&mValue);
}

/**
 * DeclarationDigit override of Base class Declaration's Create function. Adjusts the function to get attributes
 * that are unique to the "digit" item nodes.
 * @param node the "item" node to associate the declaration node with.
 * @param game the Game object that the Item object will reside in.
 */
std::shared_ptr<Item> DeclarationDigit::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;

    /// Get row, column, width and height attributes
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    /// Create an ItemDigit object (base class Item)
    auto item = std::make_shared<ItemDigit>(game, GetImageName());

    /// Using the local attributes from above, initialize the parameters of the Item
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation(col * game->GetTileWidth(), (row) * game->GetTileHeight());
    item->SetValue(mValue);
    item->SetEatable(true);

    /// Once the Item is ready, add it to the Game object's item list
    game->AddItem(item);
    return item;
}

/**
 * declaration digit function to create container
 *
 * @param node
 * @param game
 * @return
 */
std::shared_ptr<Item> DeclarationDigit::CreateContainer(wxXmlNode *node, Game *game)
{
    double row, col, width, height;

    /// Get row, column, width and height attributes
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    /// Create an ItemDigit object (base class Item)
    auto item = std::make_shared<ItemDigit>(game, GetImageName());

    /// Using the local attributes from above, initialize the parameters of the Item
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation(col * game->GetTileWidth(), (row) * game->GetTileHeight());
    item->SetValue(mValue);
    item->SetEatable(true);

    return item;
}