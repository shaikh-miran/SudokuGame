/**
 * @file SpartyTest.cpp
 * @author Sonia Charles Thalatoti
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Sparty.h>
#include <Game.h>

using namespace std;

TEST(SpartyTest, Construct)
{
    Game game;
    const std::wstring &filename1 = L"images/sparty-1.png";
    const std::wstring &filename2 = L"images/sparty-2.png";
    Sparty sparty(&game, filename1, filename2);
}

TEST(SpartyTest,GettersSetters)
{
    Game game;
    const std::wstring &filename1 = L"images/sparty-1.png";
    const std::wstring &filename2 = L"images/sparty-2.png";
    Sparty sparty(&game, filename1, filename2);

    //Test initial values
    ASSERT_NEAR(0, sparty.GetX(), 0.0001);
    ASSERT_NEAR(0, sparty.GetY(), 0.0001);

    //Test SetLocation GetX, and GetY
    sparty.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, sparty.GetX(), 0.0001);
    ASSERT_NEAR(17.2, sparty.GetY(), 0.0001);

    //Test a second with different valyes
    sparty.SetLocation(-72, -107);
    ASSERT_NEAR(-72, sparty.GetX(), 0.0001);
    ASSERT_NEAR(-107, sparty.GetY(), 0.0001);
}


TEST(SpartyTest, HitTest) {
    // Create a fish to test
    Game game;
    const std::wstring &filename1 = L"images/sparty-1.png";
    const std::wstring &filename2 = L"images/sparty-2.png";
    Sparty sparty(&game, filename1, filename2);
    // Give it a location
    // Always make the numbers different, in case they are mixed up
    sparty.SetLocation(100, 200);

    // Center of the fish should be a true
    ASSERT_TRUE(sparty.HitTest(100, 200));

    // Left of the fish
    ASSERT_FALSE(sparty.HitTest(10, 200));

    // Right of the fish
    ASSERT_FALSE(sparty.HitTest(200, 200));

    // Above the fish
    ASSERT_FALSE(sparty.HitTest(100, 0));

    // Below the fish
    ASSERT_FALSE(sparty.HitTest(100, 300));

    // On a fish transparent pixel
    ASSERT_FALSE(sparty.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}

TEST(SpartyTest, RegurgitateTest)
{
    Game game;
    const std::wstring &filename1 = L"images/sparty-1.png";
    const std::wstring &filename2 = L"images/sparty-2.png";
    Sparty sparty(&game, filename1, filename2);

    std::shared_ptr<ItemDigit> item0 = std::make_shared<ItemDigit>(&game, L"images/0.png");
    game.AddItem(item0);

/// incomplete test

}