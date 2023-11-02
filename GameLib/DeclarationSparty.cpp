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

    node->GetAttribute(L"target-x").ToDouble(&mTargetX);
    node->GetAttribute(L"target-y").ToDouble(&mTargetY);

    mIsLevel3 = node->HasAttribute(L"image3");
    if (mIsLevel3)
    {
        mImage3 = L"images/" + node->GetAttribute(L"image3").ToStdWstring();
    }

    /// Save Head Attributes
    node->GetAttribute(L"head-pivot-angle").ToDouble(&mHeadPivotAngle);
    node->GetAttribute(L"head-pivot-x").ToDouble(&mHeadPivotX);
    node->GetAttribute(L"head-pivot-y").ToDouble(&mHeadPivotY);

    /// Save Mouth Attributes
    node->GetAttribute(L"mouth-pivot-angle").ToDouble(&mMouthPivotAngle);
    node->GetAttribute(L"mouth-pivot-x").ToDouble(&mMouthPivotX);
    node->GetAttribute(L"mouth-pivot-y").ToDouble(&mMouthPivotY);

    /// Save Target Pivot Coordinates
    node->GetAttribute(L"target-x").ToDouble(&mTargetX);
    node->GetAttribute(L"target-y").ToDouble(&mTargetY);
}

/**
 * Applies xml data to the sparty object/item. Adds sparty to the associated game item list.
 * @param node the "item" node to associate the declaration node with.
 * @param game the Game object that the Item object will reside in.
 */
std::shared_ptr<Item> DeclarationSparty::Create(wxXmlNode *node, Game *game)
{
    double row, col, width, height;

    /// Get row column, width and height attributes
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);

    width = GetWidth();
    height = GetHeight();

    /// Create Sparty object (base class Item)
    auto item = std::make_shared<Sparty>(game, GetImage1Name(), GetImage2Name());

    /// If Level 3, sparty will have a third image
    /// So, if level 3, initialize the darkness image
    if (mIsLevel3)
    {
        item->IsLevel3(true);
        item->UpdateDarknessLevel(GetImage3Name());
    }

    /// Using the local attributes from above, initialize the parameters of the Item.
    item->SetWidth(width);
    item->SetHeight(height);
    double initialSpartyX = (col) * game->GetTileWidth();
    double initialSpartyY = (row) * game->GetTileHeight();

    /// Set the initial location for Sparty
    item->SetLocation(initialSpartyX, initialSpartyY);

    /// Set Sparty Attributes from the Declaration initialization
    item->SetHeadPivot(mHeadPivotX, mHeadPivotY);
    item->SetHeadAngle(mHeadPivotAngle);
    item->SetMouthPivot(mMouthPivotX, mMouthPivotY);
    item->SetMouthAngle(mMouthPivotAngle);
    item->SetTargetPivot(mTargetX, mTargetY);


    /// Call Game::SetSparty to add the Sparty pointer to the associated Game object
    game->SetSparty(item);

    ///sets the location of sparty to initial location every time the level loads.
    game->SetClickX(initialSpartyX);
    game->SetClickY(initialSpartyY);

    /// Once the Item is ready, add it to the Game object's item list
    game->AddItem(item);
    return item;
}