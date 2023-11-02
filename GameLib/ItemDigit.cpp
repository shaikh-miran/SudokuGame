/**
 * @file ItemDigit.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "ItemDigit.h"

/**
 * constructor for item digit
 * @param game
 * @param filename
 */
ItemDigit::ItemDigit(Game* game, std::wstring filename) : Item(game, filename)
{
    int digitInString = filename[7] - '0';
    mValue = digitInString;
}