/**
 * @file DeclarationXray.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "DeclarationXray.h"
#include "XRay.h"
#include "Game.h"

/**
 * DeclarationXray constructor implementation - takes in a declaration node with name "xray", creates an
 * object with initialized image, and capacity attribute
 * @param node declaration node with name "xray" (via GetAttribute)
 */
DeclarationXray::DeclarationXray(wxXmlNode* node) : Declaration(node)
{
    mImage = L"images/" + node->GetAttribute(L"image").ToStdWstring();
    node->GetAttribute(L"capacity").ToInt(&mCapacity);
}

/**
 * DeclarationXray override of Base class Declaration's Create function. Adjusts the function to get attributes
 * that are unique to the "xray" item nodes.
 * @param node the "item" node to associate the declaration node with.
 * @param game the Game object that the Item object will reside in.
 */
std::shared_ptr<Item> DeclarationXray::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;

    /// Get row, column, height and width attributes
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    /// Create XRay object (base class Item)
    auto item = std::make_shared<XRay>(game, GetImageName());

    /// Using the local attributes from above, initialize the parameters of the Item
    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation((col) * game->GetTileWidth(), (row+1 - (width/game->GetTileHeight())) * game->GetTileHeight());
    item->SetCapacity(mCapacity);

    /// Once the Item is ready, add it to the Game object's item list
    game->AddItem(item);
    return item;
}