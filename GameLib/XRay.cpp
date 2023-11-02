/**
 * @file XRay.cpp
 * @author haile
 */

#include "pch.h"
#include "XRay.h"
#include "Game.h"
#include "ItemDigit.h"
#include <random>

/**
 * Constructor
 * @param game game this xray is a member of
 */
XRay::XRay(Game *game, std::wstring filename) : Item(game, filename) {}

/**
 * display nums function for xray
 * @param digit
 */
void XRay::DisplayNums(ItemDigit * digit)
{
    const double MaxX = GetWidth() - GetGame()->GetTileWidth();
    const double MaxY = GetHeight() - GetGame()->GetTileHeight();
    std::uniform_real_distribution<> distributionX(0, MaxX);
    std::uniform_real_distribution<> distributionY(0, MaxY);
    double x, y;

    do {
        x = GetX() + distributionX(GetGame()->GetRandom());
        y = (GetY() + GetGame()->GetTileHeight() / 1.5 + GetHeight() - GetGame()->GetTileHeight() * 1.5)
            - distributionY(GetGame()->GetRandom());
    } while (DigitExist(x, y));

    digit->SetLocation(x, y);
}

/**
 * add items to xray
 * @param item
 */
void XRay::AddItem(ItemDigit* item)
{
    if (mXrayDigits.size() <= mCapacity) {
        mXrayDigits.push_back(item);
    }
}

/**
 * check if xray is full
 * @return bool
 */
bool XRay::GetXrayFull()
{
    if (mXrayDigits.size() == mCapacity) {
        mXrayFull = true;
    } else {
        mXrayFull = false;
    }
    return mXrayFull;
}

/**
 * Allows regurgitate to happen. Removes the item specified by the input from xray.
 * @param keyPressed
 * @return
 */
void XRay::RegurgitateItemDigit(int keyPressed)
{
    for (auto it = mXrayDigits.begin(); it != mXrayDigits.end(); )
    {
        int valueDigit = (*it)->GetValue();
        if (keyPressed == valueDigit)
        {
            (*it)->SetHeight((*it)->GetHeight()*2);
            (*it)->SetWidth((*it)->GetWidth()*2);
            int clickedRow = GetGame()->GetClickX()/48;
            int clickedCol = GetGame()->GetClickY()/48;
            int b = clickedCol*GetGame()->GetTileHeight();
            int a = clickedRow*GetGame()->GetTileWidth();
            (*it)->SetLocation(a, b);
            // Remove the ItemDigit from the mXrayDigits vector
            it = mXrayDigits.erase(it);
            break;
        }
        else
        {
            ++it;
        }
    }
    /// Update mXrayFull boolean after the regurgitate process is done
    if (mXrayDigits.size() != mCapacity)
    {
        mXrayFull = false;
    }
    else
    {
        mXrayFull = true;
    }
}


/**
 * check if item exists
 * @param x
 * @param y
 * @return bool
 */
bool XRay::DigitExist(double x, double y)
{
    for (const auto& item : mXrayDigits) {
            double itemX = item->GetX();
            double itemY = item->GetY();
            double itemWidth = item->GetWidth();
            double itemHeight = item->GetHeight();

            // Check if the new position overlaps with the existing ItemDigit's position
            if (x >= itemX - 20 && x <= itemX + itemWidth + 20 &&
                y >= itemY - 20 && y <= itemY + itemHeight + 20) {
                return true; // An ItemDigit already exists at this position
            }
    }
    return false; // No ItemDigit exists at this position
}