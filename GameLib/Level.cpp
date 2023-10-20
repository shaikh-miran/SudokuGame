/**
 * @file Level.cpp
 * @author haile
 */

#include "Level.h"
#include <wx/image.h>
#include <wx/graphics.h>
#include "pch.h"
#include "Game.h"

#include <wx/xml/xml.h>
#include "XRay.h"
#include <vector>
#include <memory>
#include "Sparty.h"
#include "Item.h"
#include "GameView.h"
#include "Background.h"

/// get attributes

///load function that takes game, directory (xml directory), level chosen
/// xml doc that loads in is based off of level.
/// to make path: directory that is passed in + level that is passed in + ".xml"

/**
 * Load a level xml file given a file name
 * @param filename
 */
void Level::Load(const wxString & filename)
{
    wxXmlDocument xmlDoc;
    //<level width="20" height="15" tilewidth="48" tileheight="48">
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Error loading file: check levels folder.");
        return;
    }

    /// Temporary message, delete later lolz
    wxMessageBox("Reading selected file... YIPPEEEEEE");

    /// Get the XML document root node
    auto root = xmlDoc.GetRoot();

    /// Get first child (category) of the xmlDoc
    auto category = root->GetChildren();

    /// Loop through all of the categories in the xmlDoc
    for ( ; category; category = category->GetNext())
    {
        /// Handle the category node
        XmlSet(category);
    }
}


/**
 * Handle a category (xml node). Each category can have many entries (children), so this function handles those.
 * @param node XML node
 */
void Level::XmlSet(wxXmlNode * category)
{
    /// Get name of category
    auto categoryName = category->GetName();

    /// Handle different category names
    if (categoryName == "declarations") ///give image and value
    {
        DeclarationLoad(category);
    }
    else if (categoryName == "game") /// tells all of the solution
    {

    }
    else if (categoryName == "items") ///give row and column
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

void Level::DeclarationLoad(wxXmlNode * declaration)
{
    /// Get first child (category) of the xmlDoc
    auto category = declaration->GetChildren();

    /// Loop through all of the categories in the xmlDoc
    for ( ; category; category = category->GetNext())
    {
        /// Get name of category
        auto categoryName = category->GetName();

        if (categoryName == (L"background")){
            /// shared pointer of background object
            std::make_shared<Background>(category); ///background constructor that takes in node (node contains image name and attributes height, and width)
        }
    }
}



//function to load declarations which makes background
