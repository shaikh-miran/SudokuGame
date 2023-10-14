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
    int minutes = 0;
    int seconds = 0;
    wxTimer timer;
    long lastUpdateTime; // Track the last time UpdateTime was called

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
