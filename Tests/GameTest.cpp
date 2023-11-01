/**
 * @file GameTest.cpp
 * @author Sonia Charles Thalatoti
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

using namespace std;


int ExpectedNumDeclarations = 24;
int ExpectedNumItems = 84;

class GameTest : public ::testing::Test
{
protected:
    /**
    * Create a path to a place to put temporary files
    */
    wxString TempPath()
    {
        // Create a temporary filename we can use
        auto path =  L"levels";
        if(!wxFileName::DirExists(path))
        {
            wxFileName::Mkdir(path);
        }
        return path;
    }
    /**
    * Read a file into a wstring and return it.
    * @param filename Name of the file to read
    * @return File contents
    */
    wstring ReadFile(const wxString &filename)
    {
        ifstream t(filename.ToStdString());
        wstring str((istreambuf_iterator<char>(t)),
                    istreambuf_iterator<char>());

        return str;
    }


};

TEST_F(GameTest, Construct)
{
    Game game;
}


TEST_F(GameTest,LoadItemsTest)
{
    auto path = TempPath();
    Game *x = nullptr;
    ParseXML game(x);
    wxXmlDocument file = path + L"/level2.xml";
    wxXmlNode* itemsNode = file.GetRoot()->GetChildren();
    if (itemsNode->GetName() == "items")
    {
        ASSERT_TRUE(itemsNode);
        game.Load(file);
        ASSERT_FALSE(itemsNode);
    }
}


TEST_F(GameTest, DeclarationsTest)
{
    auto path = TempPath();
    Game *x = nullptr ;
    ParseXML game(x);
    wxXmlDocument file = path + L"/level2.xml";
    wxXmlNode* Node = file.GetRoot();

    int numDeclarations ;
    wxXmlNode* declarationsNode = nullptr;

    wxXmlNode* child = Node->GetChildren();
    for (; child; child = child->GetNext())
    {
        if (child->GetName() == "declarations")
        {
            declarationsNode = child;
            break;
        }
    }
    if (declarationsNode != nullptr)
    {
        game.LoadDeclarations(declarationsNode);
        numDeclarations = game.GetNumDeclarations();
        ASSERT_EQ(numDeclarations, ExpectedNumDeclarations);
    }
}

TEST_F(GameTest, ItemsTest)
{
    auto path = TempPath();
    Game *x = nullptr ;
    ParseXML game(x);
    wxXmlDocument file = path + L"/level1.xml";
    wxXmlNode* Node = file.GetRoot();

    int numItems ;
    wxXmlNode* itemsNode = nullptr;

    wxXmlNode* child = Node->GetChildren();
    for (; child; child = child->GetNext())
    {
        if (child->GetName() == "items")
        {
            itemsNode = child;
            break;
        }
    }
    if (itemsNode != nullptr)
    {
        game.LoadDeclarations(itemsNode);
        numItems = game.GetNumDeclarations();
        ASSERT_EQ(numItems, ExpectedNumItems);
    }
}
