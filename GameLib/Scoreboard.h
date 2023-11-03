/**
 * @file Scoreboard.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SCOREBOARD_H
#define PROJECT1_GAMELIB_SCOREBOARD_H

class Game;

/**
 * scoreboard class
 */
class Scoreboard
{
private:
    /// minutes member variable
    int mMinutes = 0;

    /// seconds member variable
    int mSeconds = 0;

    /// wxtimer event
    wxTimer mTimer;

    /// bool start timer
    bool mStartTimer = false;

public:
    /// constructor
    Scoreboard();

    /// update time function
    void UpdateTime(wxTimerEvent& event);

    /// start timer function
    void StartTimer();

    /// stop timer function
    void StopTimer();

    /// reset timer function
    void ResetTimer();
    /// Draw Scoreboard
    void OnDraw(std::shared_ptr<wxGraphicsContext> gc, Game* level);

    /**
     * minutes getter
     * @return mMinutes
     */
    int GetMinutes() { return mMinutes; }

    /**
     * getter seconds
     * @return mSeconds
     */
    int GetSeconds() { return mSeconds; }

    /**
     * minutes seconds setter
     * @param minutes
     * @param seconds
     */
    void SetTime(int minutes, int seconds) { mMinutes = minutes; mSeconds = seconds; }

    /**
     * start timer setter
     * @param startTimer
     */
    void SetStartTimer(bool startTimer) { mStartTimer = startTimer; }

    /**
     * start timer getter
     * @return mStartTimer
     */
    bool GetStartTimer() { return mStartTimer; }

};

#endif //PROJECT1_GAMELIB_SCOREBOARD_H
