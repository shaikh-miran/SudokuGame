/**
 * @file ParseXML.cpp
 * @author haile
 */

#include "pch.h"
#include "ParseXML.h"
#include "DeclarationGiven.h"
#include "DeclarationDigit.h"
#include "DeclarationXray.h"
#include "DeclarationBackground.h"
#include "Game.h"

using namespace std;

ParseXML::ParseXML(Game * game) : mGame(game) {}

/**
 * Loads all attributes and items from a given XML document.
 * @param xmlDoc input document
 */
void ParseXML::Load(wxXmlDocument xmlDoc)
{
    auto root = xmlDoc.GetRoot(); // getattribute

    /// handle the window/tile sizes (maybe make them into member variables?)
    root->GetAttribute("width").ToDouble(&mWidth);
    root->GetAttribute("height").ToDouble(&mHeight);
    root->GetAttribute("tilewidth").ToDouble(&mTileHeight);
    root->GetAttribute("tileheight").ToDouble(&mTileWidth);

    mGame->SetWidth(mWidth);
    mGame->SetHeight(mHeight);
    mGame->SetTileWidth(mTileWidth);
    mGame->SetTileHeight(mTileHeight);

    /// Get first child (category) of the xmlDoc
    auto category = root->GetChildren();
    /// Loop through all of the categories in the xmlDoc
    for ( ; category; category = category->GetNext())
    {
        /// Get name of category
        auto categoryName = category->GetName();
        /// Handle different category names
        if (categoryName == "declarations")
        {
            LoadDeclarations(category);
        }
        else if (categoryName == "items")
        {
            LoadItems(category);
        }
    }
}

/**
 * Loads entries under the <declarations> node in the XML document.
 * @param declaration the parent node of all declaration entries
 */
void ParseXML::LoadDeclarations(wxXmlNode * node) {
    /// Loop through all entries
    auto entry = node->GetChildren();
    for ( ; entry; entry = entry->GetNext())
    {
        auto name = entry->GetName();
        auto id = entry->GetAttribute(L"id").ToStdString();
        if (name == L"given")
        {
            auto declaration = make_shared<DeclarationGiven>(entry);
            mDeclarationMap[id] = declaration;
        }
        else if (name == L"digit")
        {
            auto declaration = make_shared<DeclarationDigit>(entry);
            mDeclarationMap[id] = declaration;
        }
        else if (name == L"xray")
        {
            auto declaration = make_shared<DeclarationXray>(entry);
            mDeclarationMap[id] = declaration;
        }
        else if (name == L"background")
        {
            auto declaration = make_shared<DeclarationBackground>(entry);
            mDeclarationMap[id] = declaration;
        }
        numDeclarations += 1;
    }
}


// * Loads game solution (?) from <game> child from the XML document.
// * @param game game node, containing the correct board layout.
// */
//void ParseXML::LoadGame(wxXmlNode * game) {
//    /// Loop through all entries
//    auto entry = game->GetChildren();
//
//    /// handle the 1 entry in game
//    /// Format: <game col="6" row="3">3 2 5 6...5</game>
//}

/**
 * Loads entries under the <items> child in the XML document.
 * @param items the parent node of all item entries
 */
void ParseXML::LoadItems(wxXmlNode * node) {
    /// Loop through all entries
    auto entry = node->GetChildren();
    for ( ; entry; entry = entry->GetNext())
    {
        /// handle each entry item (ex. <background id="i389" col="0.0" row="14.0" />)
        /// Types are: background, xray, given/digit, sparty (in that order)
        auto name = entry->GetName();
        auto id = entry->GetAttribute(L"id").ToStdString();
        if (name == L"given" || name == L"digit" || name == L"xray" || name == L"background")
        {
            auto declaration = mDeclarationMap[id];
            declaration->Create(entry, mGame);
        }
        numItems++;
    }
}

