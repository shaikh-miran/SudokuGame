/**
 * @file Solution.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SOLUTION_H
#define PROJECT1_GAMELIB_SOLUTION_H

class Game;

/**
 * solution class
 * solution is shown when show solution event invoked
 */
class Solution
{
private:
    /// Starting cell row
    int mRow;
    /// Starting cell col
    int mCol;
    /// Vector for all digits in Solution
    std::vector<int> mSolution;

public:
    /**
     * Sets vector of solution, loaded in from xml
     * @param solution vector
     */
    void SetSolution(std::vector<int> solution) {mSolution = solution;}

    /**
     * Sets starting row and col for solution,
     * loaded in from xml
     * @param col double
     * @param row double
     */
    void SetSolRowCol(double col, double row) {mCol = col; mRow = row;}

    /**
     * Solve Game entirely
     * @param game object
     */
    void SolveGame(Game * game);

    /**
     * Check game solution
     * @param game object
     * @return
     */
    bool CheckSolution(Game * game);

    /**
     * Check if grid is full
     * @param game object
     * @return
     */
    bool GridFull(Game *game);

};

#endif //PROJECT1_GAMELIB_SOLUTION_H
