/**
 * @file PopUp.h
 * @author team prometheus
 *
 *
 */

#ifndef PROJECT1_GAMELIB_POPUP_H
#define PROJECT1_GAMELIB_POPUP_H

/**
 * Class that draws the pop up message prior to every level
 */
class PopUp
{
private:

public:
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int level);

};



#endif //PROJECT1_GAMELIB_POPUP_H
