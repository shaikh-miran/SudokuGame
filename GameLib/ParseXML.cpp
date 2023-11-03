/**
 * @file ParseXML.cpp
 * @author haile
 */

#include "pch.h"
#include <wx/wx.h>
#include <vector>
#include <sstream>
#include <string>
#include "ParseXML.h"
#include "DeclarationGiven.h"
#include "DeclarationDigit.h"
#include "DeclarationSparty.h"
#include "DeclarationXray.h"
#include "DeclarationContainer.h"
#include "DeclarationBackground.h"
#include "Game.h"

using namespace std;

/**
 * Constructor.
 * @param game
 */
ParseXML::ParseXML(Game * game) : mGame(game)
{

}

/**
 * Loads entries under the <declarations> node in the XML document.
 * @param declaration the parent node of all declaration entries
 */
void ParseXML::LoadDeclarations(wxXmlNode * node)
{
    /// Loop through all entries
    auto entry = node->GetChildren();
    for ( ; entry; entry = entry->GetNext())
    {
        auto name = entry->GetName();
        auto id = entry->GetAttribute(L"id").ToStdWstring();
        if (name == L"given")
        {
            auto declaration = make_shared<DeclarationGiven>(entry);
            mDeclarationMap[id] = declaration;
            declaration->SetLevel(this);
        }
        else if (name == L"digit")
        {
            auto declaration = make_shared<DeclarationDigit>(entry);
            mDeclarationMap[id] = declaration;
            declaration->SetLevel(this);

        }
        else if (name == L"sparty")
        {
            auto declaration = make_shared<DeclarationSparty>(entry);
            mDeclarationMap[id] = declaration;
            declaration->SetLevel(this);

        }
        else if (name == L"xray")
        {
            auto declaration = make_shared<DeclarationXray>(entry);
            mDeclarationMap[id] = declaration;
            declaration->SetLevel(this);

        }
        else if (name == L"background")
        {
            auto declaration = make_shared<DeclarationBackground>(entry);
            mDeclarationMap[id] = declaration;
            declaration->SetLevel(this);

        }
        else if (name == L"container")
        {
            auto declaration = make_shared<DeclarationContainer>(entry);
            mDeclarationMap[id] = declaration;
            declaration->SetLevel(this);

        }
        numDeclarations += 1;
    }
}

/**
 * Loads game solution from <game> child from the XML document.
 * @param game game node, containing the correct board layout.
 */
void ParseXML::LoadGame(wxXmlNode * node)
{
    double row, col;
    node->GetAttribute(L"row").ToDouble(&row);
    node->GetAttribute(L"col").ToDouble(&col);

    mGame->GetSolution()->SetSolRowCol(col, row);

    // Get the text content of the XML tag
    auto solution = node->GetNodeContent().ToStdString();

    // Create an input string stream for parsing
    std::istringstream iss(solution);

    // Vector to store the extracted numbers
    int number;

    // Loop through the string and extract numbers
    while(iss >> number)
    {
        mSolutionVector.push_back(number);
    }

    mGame->GetSolution()->SetSolution(mSolutionVector);
}

/**
 * Finds the declaration in the Map using iD.
 * @param id Id of each item.
 * @return declaration associated with the id in the Map.
 */
std::shared_ptr<Declaration> ParseXML::FindDeclaration(std::wstring id)
{
    auto declaration = mDeclarationMap[id];
    return declaration;
}

/**
 * Loads entries under the <items> child in the XML document.
 * @param items the parent node of all item entries
 */
void ParseXML::LoadItems(wxXmlNode * node)
{
    /// Loop through all entries
    auto entry = node->GetChildren();
    for ( ; entry; entry = entry->GetNext())
    {
        auto name = entry->GetName();
        auto id = entry->GetAttribute(L"id").ToStdWstring();
        if (name == L"given" || name == L"digit" || name == L"sparty" || name == L"background" || name == L"xray")
        {
            auto declaration = mDeclarationMap[id];
            declaration->Create(entry, mGame);
        }

        else if(name == L"container")
        {
            auto containerDeclaration = mDeclarationMap[id];
            containerDeclaration->Create(entry, mGame);
        }

        numItems++;
    }
}

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
        else if (categoryName == "game")
        {
            LoadGame(category);
        }
    }
}

