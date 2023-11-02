/**
 * @file Solution.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "Solution.h"
#include "Game.h"
#include "DigitVisitor.h"
#include "ItemDigit.h"

/**
 * Displays the solution of curr level on the board
 * @param game
 */
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


/**
 * checks if current solution is correct
 * @param game
 * @return
 */
bool Solution::CheckSolution(Game *game)
{
    int index = 0;

    for (int i = mRow; i < mRow+9; i++)
    {
        for(int j = mCol; j < mCol + 9; j++)
        {
            auto grabbedItem = game->HitTest(j*game->GetTileWidth(), i*game->GetTileHeight());
            if (grabbedItem == nullptr)
            {
                return false;
            }
            else if (grabbedItem->GetValue() != mSolution[index])
            {
                return false;
            }
            index++;
        }


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