/**
 * @file LoadXML.cpp
 * @author haile
 */

#include "pch.h"
#include "LoadXML.h"

void LoadXML::Load(wxXmlDocument xmlDoc)
{

    /// Temporary message, delete later lolz
    wxMessageBox("Reading selected file... YIPPEEEEEE");

    /// Get the XML document root node
    auto root = xmlDoc.GetRoot(); // getattribute

    /// Get Window and Tile dimensions >> doesn't load, only prints currently :) will add that functionality soon
    wxMessageBox("Window: " + root->GetAttribute("width") + "x" + root->GetAttribute("height"));
    wxMessageBox("Tile: " + root->GetAttribute("tilewidth") + "x" + root->GetAttribute("tileheight"));

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

        }
        else if (categoryName == "game")
        {

        }
        else if (categoryName == "items")
        {

        }

        /// Tester code that runs through all of the nodes and displays them. Implement this into the if statements
        /// to handle specific category types.
        /// BEGIN TESTER CODE

        auto message = categoryName + "\n";

        /// Loop through all entries
        auto entry = category->GetChildren();
        for ( ; entry; entry = entry->GetNext())
        {
            auto entryName = entry->GetName();
            message += entryName + " ";
        }

        wxMessageBox(message);

        /// END TESTER CODE
    }
}

