/**
 * @file ParseXML.cpp
 * @author haile
 */

#include "pch.h"
#include "ParseXML.h"

/**
 * Loads entries under the <declarations> node in the XML document.
 * @param declaration the parent node of all declaration entries
 */
void ParseXML::LoadDeclarations(wxXmlNode * declaration) {
//    // Check if the input node is not NULL
//    if (!declaration) {
//        // Handle error or return
//        return;
//    }
    /// Loop through all entries
    auto entry = declaration->GetChildren();
    for ( ; entry; entry = entry->GetNext())
    {
        wxString entryName = entry->GetName();
        /// handle each entry declaration (ex. <given id="i362" width="48" height="48" image="0b.png" value="0" />)
        /// Types are: given/digit, sparty, xray, background (in that order)
        entry->GetAttribute("id");
        entry->GetAttribute("width");
        entry->GetAttribute("height");

        if (entryName == "given" || entryName == "digit" )
        {
            entry->GetAttribute("image");
            entry->GetAttribute("value");
        }
        if (entryName == "sparty")
        {
            entry->GetAttribute("front");
            entry->GetAttribute("head-pivot-angle");
            entry->GetAttribute("head-pivot-x");
            entry->GetAttribute("head-pivot-y");
            entry->GetAttribute("image1");
            entry->GetAttribute("image2");
            entry->GetAttribute("mouth-pivot-angle");
            entry->GetAttribute("mouth-pivot-x");
            entry->GetAttribute("mouth-pivot-y");
            entry->GetAttribute("target-x");
            entry->GetAttribute("target-y");
        }
        if (entryName == "xray")
        {
            entry->GetAttribute("image");
            entry->GetAttribute("capacity");
        }
        if (entryName == "background")
        {
            entry->GetAttribute("image");
        }
        numDeclarations += 1;
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
    entry->GetAttribute("col");
    entry->GetAttribute("row");
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
        entry->GetAttribute("id");
        entry->GetAttribute("col");
        entry->GetAttribute("row"); /// does this call do anything??
        numItems++;
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

