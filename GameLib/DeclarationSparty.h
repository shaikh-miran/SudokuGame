/**
 * @file DeclarationSparty.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONSPARTY_H
#define PROJECT1_GAMELIB_DECLARATIONSPARTY_H

#include "Declaration.h"

/// Forward declaration of Game class
class Game;

/**
 * DeclarationSparty class - a type of Declaration; handles Declaration nodes that have the "name" attribute of
 * "sparty"
 */
class DeclarationSparty : public Declaration
{
private:
    /// Main body image
    std::wstring mImage1;

    /// Mouth image
    std::wstring mImage2;

    /// Darkness image
    std::wstring mImage3;

    /// Head Angle
    double mHeadPivotAngle;

    /// Head Pivot x coordinate
    double mHeadPivotX;

    /// Head Pivot y coordinate
    double mHeadPivotY;

    /// Mouth Angle
    double mMouthPivotAngle;

    /// Mouth Pivot x coordinate
    double mMouthPivotX;

    /// Mouth Pivot y coordinate
    double mMouthPivotY;

    /// Target Pivot x coordinate
    double mTargetX;

    /// Target Pivot y coordinate
    double mTargetY;

    /// boolean member variable for is level 3
    bool mIsLevel3 = false;

public:
    //// Default constructor (disabled)
    DeclarationSparty() = delete;

    /// Copy constructor (disabled)
    DeclarationSparty(const DeclarationSparty &) = delete;

    /// Assignment operator
    void operator=(const DeclarationSparty &) = delete;

    /// Constructor
    DeclarationSparty(wxXmlNode* node);

    /**
     * Declaration::Create override; modified to accept "background" specific attributes
     * @param node node of the item
     * @param game the game that we are associating with this
     * @return Item shared pointer
     */
    std::shared_ptr<Item> Create(wxXmlNode* node, Game* game) override;

    /**
      * Return the sparty body image filename
      * @return string form of the image's filename
      */
    std::wstring GetImage1Name() { return mImage1; }

    /**
      * Return the sparty mouth image filename
      * @return string form of the image's filename
      */
    std::wstring GetImage2Name() { return mImage2; }


    /**
     * getter for image 3 name
     * @return string for of the image's filename
     */
    std::wstring GetImage3Name() { return mImage3; }
};

#endif //PROJECT1_GAMELIB_DECLARATIONSPARTY_H
