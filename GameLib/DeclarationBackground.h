/**
 * @file DeclarationBackground.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONBACKGROUND_H
#define PROJECT1_GAMELIB_DECLARATIONBACKGROUND_H

#include "Declaration.h"

/// Forward declaration of Game class
class Game;

/**
 * DeclarationBackground class - a type of Declaration; handles Declaration nodes that have the "name" attribute of
 * "background"
 */
class DeclarationBackground : public Declaration
{
private:
    /// Background image filename
    std::wstring mImage;

public:


    //// Default constructor (disabled)
    DeclarationBackground() = delete;

    /// Copy constructor (disabled)
    DeclarationBackground(const DeclarationBackground &) = delete;

    /// Assignment operator
    void operator=(const DeclarationBackground &) = delete;

    /// Constructor
    DeclarationBackground(wxXmlNode* node);

    /// Declaration::Create override; modified to accept "background" specific attributes
    void Create(wxXmlNode* node, Game* game) override;

    /**
     * Return the background image filename
     * @return string form of the image's filename
     */
    std::wstring GetImageName() { return mImage; }


};

#endif //PROJECT1_GAMELIB_DECLARATIONBACKGROUND_H
