/**
 * @file Scoreboard.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SCOREBOARD_H
#define PROJECT1_GAMELIB_SCOREBOARD_H

class Game;


class Scoreboard
{
private:
    int mMinutes = 0;
    int mSeconds = 0;
    wxTimer mTimer;

public:
    Scoreboard();
    void UpdateTime(wxTimerEvent& event);
    void StartTimer();
    void StopTimer();
    void ResetTimer();
    /// Draw Scoreboard
    void OnDraw(std::shared_ptr<wxGraphicsContext> gc, Game* level);

    int GetMinutes() { return mMinutes; }
    int GetSeconds() { return mSeconds; }

    void SetTime(int minutes, int seconds) { mMinutes = minutes; mSeconds = seconds; }

};

#endif //PROJECT1_GAMELIB_SCOREBOARD_H
