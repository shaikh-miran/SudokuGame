/**
 * @file ItemTest.cpp
 * @author Sonia Charles Thalatoti
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <XRay.h>
#include <Game.h>

using namespace std;

TEST(XrayTest, Construct)
{
    XRay xray(Game *game);
}

TEST(XrayTest, GettersSetters)
{
    Game game;
    XRay xRay(&game);

    //Test initial values
    ASSERT_NEAR(0, xRay.GetX(), 0.0001);
    ASSERT_NEAR(0, xRay.GetY(), 0.0001);

    //Test SetLocation GetX, and GetY
    xRay.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, xRay.GetX(), 0.0001);
    ASSERT_NEAR(17.2, xRay.GetY(), 0.0001);

    //Test a second with different valyes
    xRay.SetLocation(-72, -107);
    ASSERT_NEAR(-72, xRay.GetX(), 0.0001);
    ASSERT_NEAR(-107, xRay.GetY(), 0.0001);
}

TEST(XrayTest, HitTest)
{
    // Create a fish to test
    Game game;
    XRay xRay(&game);

    // Give it a location
    // Always make the numbers different, in case they are mixed up
    xRay.SetLocation(100, 200);

    // Center of the fish should be a true
    ASSERT_TRUE(xRay.HitTest(100, 200));

    // Left of the fish
    ASSERT_FALSE(xRay.HitTest(10, 200));

    // Right of the fish
    ASSERT_FALSE(xRay.HitTest(200, 200));

    // Above the fish
    ASSERT_FALSE(xRay.HitTest(100, 0));

    // Below the fish
    ASSERT_FALSE(xRay.HitTest(100, 300));

}
