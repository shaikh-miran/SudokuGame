/**
 * @file Background.cpp
 * @author haile
 */

#include "Background.h"

/**
 * Background Constructor implementation - passes parameters to parent class Item constructor.
 * @param game The associated game
 * @param filename The filename of the background image
 */
Background::Background(Game *game, std::wstring filename) : Item(game, filename) {}