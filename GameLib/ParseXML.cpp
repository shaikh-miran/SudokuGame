/**
 * @file ParseXML.cpp
 * @author haile
 */

#include "pch.h"
#include "ParseXML.h"
#include "DeclarationGiven.h"
#include "Item.h"

ParseXML::ParseXML(Game * game) : mGame(game)
{

}

/**
 * Loads entries under the <declarations> node in the XML document.
 * @param declaration the parent node of all declaration entries
 */
void ParseXML::LoadDeclarations(wxXmlNode * declaration) {
    /// Loop through all entries
    auto entry = declaration->GetChildren();
    std::shared_ptr<DeclarationGiven> item;
    for ( ; entry; entry = entry->GetNext())
    {
        auto name = entry->GetName();
        if (name == L"given")
        {
            auto image = entry->GetAttribute(L"image").ToStdWstring();
            image = L"images/" + image;
            item = make_shared<DeclarationGiven>(mGame, image);
        }
        /// handle each entry declaration (ex. <given id="i362" width="48" height="48" image="0b.png" value="0" />)
        /// Types are: given/digit, sparty, xray, background (in that order)
        if (item != nullptr)
        {
            mGame->AddDeclaration(item);
            item->XmlLoad(entry);
        }
    }
}

/**
 * Loads game solution (?) from <game> child from the XML document.
 * @param game game node, containing the correct board layout.
 */
void ParseXML::LoadGame(wxXmlNode * game) {
    /// Loop through all entries
    auto entry = game->GetChildren();

    /// handle the 1 entry in game
    /// Format: <game col="6" row="3">3 2 5 6...5</game>
}

/**
 * Loads entries under the <items> child in the XML document.
 * @param items the parent node of all item entries
 */
void ParseXML::LoadItems(wxXmlNode * items) {
    /// Loop through all entries
    auto entry = items->GetChildren();
    for ( ; entry; entry = entry->GetNext())
    {
        /// handle each entry item (ex. <background id="i389" col="0.0" row="14.0" />)
        /// Types are: background, xray, given/digit, sparty (in that order)
    }
}

/**
 * Loads all attributes and items from a given XML document.
 * @param xmlDoc input document
 */
void ParseXML::Load(wxXmlDocument xmlDoc)
{
    /// Get the XML document root node
    auto root = xmlDoc.GetRoot(); // getattribute

    /// handle the window/tile sizes (maybe make them into member variables?)
    root->GetAttribute("width");
    root->GetAttribute("height");
    root->GetAttribute("tilewidth");
    root->GetAttribute("tileheight");

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
        else if (categoryName == "game")
        {
            LoadGame(category);
        }
        else if (categoryName == "items")
        {
            LoadItems(category);
        }
    }
}

