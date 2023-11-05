/**
 * @file Solution.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "Solution.h"
#include "Game.h"
#include "DigitVisitor.h"
#include "ItemDigit.h"

void Solution::SolveGame(Game* game) {
    int i = mRow;
    int j = mCol;
    int index = 0;

    DigitVisitor visitor;

    while (i < mRow + 9) {
        while (j < mCol + 9) {
            auto grabbedItem = game->HitTest(j * game->GetTileWidth(), i * game->GetTileHeight());

            if (grabbedItem == nullptr) {
                int value = mSolution[index];
                visitor.SetValue(value);
                visitor.SetDigit(nullptr);
                game->Accept(&visitor);
                if (visitor.GetDigit() != nullptr) {
                    visitor.GetDigit()->SetEatable(false);
                    visitor.GetDigit()->SetLocation(j * game->GetTileWidth(), i * game->GetTileHeight());
                }
            }
            j++;
            index++;
        }
        i++;
        j = mCol;
    }
}

bool Solution::CheckSolution(Game *game)
{
    int i = mRow;
    int j = mCol;
    int index = 0;

    while (i < mRow + 9) {
        while (j < mCol + 9) {
            auto grabbedItem = game->HitTest(j*game->GetTileWidth(), i*game->GetTileHeight());
            int value = grabbedItem->GetValue();
            int ind = mSolution[index];
            if (grabbedItem == nullptr) {
                return false;
            } else if (grabbedItem->GetValue() != mSolution[index]) {
                return false;
            }
            index++;
            j++;
        }
        i++;
        j = mCol;
    }
    return true;
}

bool Solution::GridFull(Game *game)
{
    int i = mRow;
    int j = mCol;
    int index = 0;

    while (i < mRow + 9) {
        while (j < mCol + 9) {
            auto grabbedItem = game->HitTest(j*game->GetTileWidth(), i*game->GetTileHeight());
            if (grabbedItem == nullptr) {
                return false;
            }
            index++;
            j++;
        }
        i++;
        j = mCol;
    }
    return true;
}