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

    double mTargetX;
    double mTargetY;

public:
    //// Default constructor (disabled)
    DeclarationSparty() = delete;

    /// Copy constructor (disabled)
    DeclarationSparty(const DeclarationSparty &) = delete;

    /// Assignment operator
    void operator=(const DeclarationSparty &) = delete;

    /// Constructor
    DeclarationSparty(wxXmlNode* node);

    /// Declaration::Create override; modified to accept "background" specific attributes
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

    double GetTargetX() { return mTargetX; }
    double GetTargetY() { return mTargetY; }
};

#endif //PROJECT1_GAMELIB_DECLARATIONSPARTY_H
