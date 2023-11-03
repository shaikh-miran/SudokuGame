/**
 * @file ItemGiven.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "ItemGiven.h"

 /**
  * ItemGiven constructor
  * @param game the game to associate the ItemGiven to
  * @param filename the file name of the image to associate with this object
  */
ItemGiven::ItemGiven(Game* game, std::wstring filename) : Item(game, filename)
{

}