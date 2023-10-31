/**
 * @file DeclarationContainer.cpp
 * @author Sonia Charles Thalatoti
 */


#include "pch.h"
#include "DeclarationContainer.h"
#include "ItemContainer.h"
#include "ItemDigit.h"
#include "Game.h"

DeclarationContainer::DeclarationContainer(wxXmlNode *node) : Declaration(node)
{
    mImage1 = L"images/" + node->GetAttribute(L"image").ToStdWstring();
    mImage2 = L"images/" + node->GetAttribute(L"front").ToStdWstring();
}

std::shared_ptr<Item> DeclarationContainer::Create(wxXmlNode *node, Game *game)
{

    double row, col, width, height;
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);
    width = GetWidth();
    height = GetHeight();

    auto item = std::make_shared<ItemContainer>(game, GetImage1Name(),
                                                GetImage2Name(), this);

    item->SetWidth(width);
    item->SetHeight(height);
    item->SetLocation((col+2) * game->GetTileWidth(), (row-1) * game->GetTileHeight());
    //game->SetContainer(item);
    game->AddItem(item);
    item->ContainerXmlLoad(node);
//
//    auto item1 = std::make_shared<ItemContainer>(game, GetImage2Name(),this);
//    item1->SetWidth(width);
//    item1->SetHeight(height);
//    item1->SetLocation((col+2) * game->GetTileWidth(), (row-1) * game->GetTileHeight());
//    //game->SetContainer(item1);
//    game->AddItem(item1);
    return item;
}

