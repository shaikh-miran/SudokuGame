/**
 * @file ItemTest.cpp
 * @author Sonia Charles Thalatoti
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <XRay.h>
#include <Game.h>

using namespace std;

TEST(XrayTest, Constructor)
{
    Game game;
    const std::wstring &filename = L"images/xray.png";
    XRay xRay(&game,filename);
}

TEST(XrayTest, GettersSetters)
{
    Game game;
    const std::wstring &filename = L"images/xray.png";
    XRay xRay(&game,filename);

    ASSERT_NEAR(0, xRay.GetX(), 0.0001);
    ASSERT_NEAR(0, xRay.GetY(), 0.0001);

    xRay.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, xRay.GetX(), 0.0001);
    ASSERT_NEAR(17.2, xRay.GetY(), 0.0001);

    xRay.SetLocation(-72, -107);
    ASSERT_NEAR(-72, xRay.GetX(), 0.0001);
    ASSERT_NEAR(-107, xRay.GetY(), 0.0001);
}

TEST(XRayTest, HitTest) {
    
    Game game;
    const std::wstring &filename = L"images/xray.png";
    XRay xRay(&game,filename);

    xRay.SetLocation(100, 200);

    ASSERT_TRUE(xRay.HitTest(100, 200));

    ASSERT_FALSE(xRay.HitTest(10, 200));

    ASSERT_FALSE(xRay.HitTest(200, 200));

    ASSERT_FALSE(xRay.HitTest(100, 0));

    ASSERT_FALSE(xRay.HitTest(100, 300));
}

