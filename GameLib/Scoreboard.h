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

    ///Scale double variable
    double mScale;

    ///Y and X offset doubles
    double mXOffset;
    ///Y and X offset doubles
    double mYOffset;

public:
    Scoreboard();
    void UpdateTime(wxTimerEvent& event);
    void StartTimer();
    void StopTimer();
    void ResetTimer();
    /// Draw Scoreboard
    void OnDraw(std::shared_ptr<wxGraphicsContext> gc, Game* level);
//    void Draw(wxDC* dc);

};

#endif //PROJECT1_GAMELIB_SCOREBOARD_H
