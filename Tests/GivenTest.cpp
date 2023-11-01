/**
 * @file GivenTest.cpp
 * @author Navya Singh
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <DeclarationGiven.h>
#include <Game.h>

TEST(DeclarationGivenTest, Constructor) {
    // Create a wxXmlNode for testing
    wxXmlNode node(wxXML_ELEMENT_NODE, "DeclarationGiven");
    node.AddAttribute("image", "item.png");
    node.AddAttribute("value", "42");

    DeclarationGiven declaration(&node);

    EXPECT_EQ(declaration.GetImageName(), L"images/item.png");
}
