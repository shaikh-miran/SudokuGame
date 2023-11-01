/**
 * @file Solution.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SOLUTION_H
#define PROJECT1_GAMELIB_SOLUTION_H

class Game;

class Solution
{
private:
    ///row of starting cell
    int mRow;
    ///col of starting cell
    int mCol;
    ///vector of solution from xml file
    std::vector<int> mSolution;

public:
    /**
     * sets vector of solution, loaded in from xml
     * @param sol
     */
    void SetSolution(std::vector<int> solution) {mSolution = solution;}
    /**
     * Sets starting row and col for solution,
     * loaded in from xml
     * @param col
     * @param row
     */
    void SetSolRowCol(double col, double row) {mCol = col; mRow = row;}
    void DisplaySolution(Game * game);
    bool CheckSolution(Game * game);

};

#endif //PROJECT1_GAMELIB_SOLUTION_H
