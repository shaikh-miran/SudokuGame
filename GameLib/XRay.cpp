/**
 * @file XRay.cpp
 * @author haile
 */

#include "pch.h"
#include "XRay.h"
#include "Game.h"
#include <random>

/**
 * Constructor
 * @param game game this xray is a member of
 */
XRay::XRay(Game *game, std::wstring filename) : Item(game, filename)
{
}

void XRay::DisplayNums(ItemDigit * digit)
{
    const double MaxX = GetWidth() - GetGame()->GetTileWidth();
    const double MinX = GetX();
    const double MaxY = GetHeight() - GetGame()->GetTileHeight();
    const double MinY = GetY();
    std::uniform_real_distribution<> distributionX(0, MaxX);
    std::uniform_real_distribution<> distributionY(0, MaxY);
    auto x = GetX() + distributionX(GetGame()->GetRandom());
    auto y = (GetY() + GetGame()->GetTileHeight() / 1.5 + GetHeight() - GetGame()->GetTileHeight() * 1.5)
        - distributionY(GetGame()->GetRandom());

    digit->SetLocation(x, y);
}