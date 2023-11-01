/**
 * @file Alert.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_ALERT_H
#define PROJECT1_GAMELIB_ALERT_H

class Game;

class Alert
{
private:
    Game * mGame;

public:
    Alert(Game *game);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);

};

#endif //PROJECT1_GAMELIB_ALERT_H
