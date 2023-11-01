/**
 * @file ContainerTest.cpp
 * @author Sonia Charles Thalatoti
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <DeclarationContainer.h>
#include <Game.h>

TEST(ContianerTest, Constructor) {
    // Create a wxXmlNode for testing
    wxXmlNode node(wxXML_ELEMENT_NODE, "DeclarationContainer");
    node.AddAttribute("image", "pumpkin.png");

    DeclarationContainer declaration(&node);

    EXPECT_EQ(declaration.GetImage1Name(), L"images/pumpkin.png");
}

TEST(ContainerTest, Create) {
    // Create a mock XML node (you may need a real XML library for this)
    wxXmlNode node(wxXML_ELEMENT_NODE, "DeclarationContainer");
    node.AddAttribute("row", "2");
    node.AddAttribute("col", "3");

    // Create a Game object
    Game game;

    // Create a DeclarationContainer object (or use a mock if available)
    DeclarationContainer declarationContainer(&node);

    // Call the Create function
    std::shared_ptr<Item> item = declarationContainer.Create(&node, &game);

    // Check if the item is created correctly
    EXPECT_TRUE(item != nullptr);
}