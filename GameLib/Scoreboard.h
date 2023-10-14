/**
 * @file Scoreboard.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_SCOREBOARD_H
#define PROJECT1_GAMELIB_SCOREBOARD_H

class Scoreboard
{
private:
    int minutes = 0;
    int seconds = 0;
    wxTimer timer;
    long lastUpdateTime; // Track the last time UpdateTime was called

public:
    Scoreboard();
    void UpdateTime(wxTimerEvent& event);
    void StartTimer();
    void StopTimer();
    void ResetTimer();
    /// Draw Scoreboard
    void OnDraw(std::shared_ptr<wxGraphicsContext> gc);
//    void Draw(wxDC* dc);

};

#endif //PROJECT1_GAMELIB_SCOREBOARD_H
