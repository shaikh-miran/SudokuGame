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


int ExpectedNumDeclarations = 21;
int ExpectedNumItems = 83;

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


TEST_F(GameTest,Load)
{
    auto path = TempPath();
    ParseXML game;
    wxXmlDocument file = path + L"/level0.xml";
    game.Load(file);


}



TEST_F(GameTest,LoadItemsTest)
{
    auto path = TempPath();
    ParseXML game;
    wxXmlDocument file = path + L"/level0.xml";
    wxXmlNode* itemsNode = file.GetRoot()->GetChildren();
    if (itemsNode->GetName() == "items")
    {
        ASSERT_TRUE(itemsNode);
        game.LoadItems(itemsNode);
        ASSERT_FALSE(itemsNode);


    }
}

TEST_F(GameTest,LoadGameTest)
{
    auto path = TempPath();
    ParseXML game;
    wxXmlDocument file = path + L"/level0.xml";
    wxXmlNode* gameNode = file.GetRoot()->GetChildren();
    if (gameNode->GetName() == "game")
    {
        ASSERT_TRUE(gameNode);
        game.LoadGame(gameNode);
        ASSERT_FALSE(gameNode);
    }
}

TEST_F(GameTest, DeclarationsTest)
{
    auto path = TempPath();
    ParseXML game;
    wxXmlDocument file = path + L"/level0.xml";
    wxXmlNode* Node = file.GetRoot();

    int numDeclarations;
    int numItems;
    wxXmlNode* declarationsNode = nullptr;
    wxXmlNode* itemsNode = nullptr;

    wxXmlNode* child = Node->GetChildren();
    for (; child; child = child->GetNext())
    {
        if (child->GetName() == "declarations")
        {
            declarationsNode = child;
            break;
        }

        if (child->GetName() == "items")
        {
            itemsNode = child;
            break;
        }

    }

    if (declarationsNode != nullptr)
    {
        game.LoadDeclarations(declarationsNode);
        numDeclarations = game.GetNumDeclarations();
        ASSERT_EQ(numDeclarations, ExpectedNumDeclarations);

    }

    if (itemsNode != nullptr)
    {
        game.LoadItems(itemsNode);
        numItems = game.GetNumItems();
        ASSERT_EQ(numItems, ExpectedNumItems);

    }

}
