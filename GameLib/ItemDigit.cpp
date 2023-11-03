/**
 * @file ItemDigit.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "ItemDigit.h"

/**
 * constructor for item digit
 * @param game the game that the ItemDigit will be associated with
 * @param filename the file name of the image to use for the object
 */
ItemDigit::ItemDigit(Game* game, std::wstring filename) : Item(game, filename)
{
    int digitInString = filename[7] - '0';
    mValue = digitInString;
}