/**
 * @file ItemDigit.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "ItemDigit.h"

ItemDigit::ItemDigit(Game* game, std::wstring filename) : Item(game, filename)
{
    auto digitInString = filename[7] - '0';
    mValue = digitInString;

}