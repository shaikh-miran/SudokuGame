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

    /// draw pop up when level starts
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int level, int width, int height);

    /// draw pop up upon level completion
    void OnLevelCompletion(std::shared_ptr<wxGraphicsContext> graphics,int level, int width, int height);

    /// draw pop up upon incorrect
    void OnIncorrect(std::shared_ptr<wxGraphicsContext> graphics,int level,int width, int height);

    /// draw pop up upon sparty being full
    void OnSpartyFull(std::shared_ptr<wxGraphicsContext> graphics, int level, int width, int height);

    /// draw pop up upon given exists a location.
    void OnExists(std::shared_ptr<wxGraphicsContext> graphics, int level, int width, int height);
};



#endif //PROJECT1_GAMELIB_POPUP_H
