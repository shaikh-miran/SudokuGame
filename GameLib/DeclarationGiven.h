/**
 * @file DeclarationGiven.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONGIVEN_H
#define PROJECT1_GAMELIB_DECLARATIONGIVEN_H

#include "Declaration.h"
/// Forward declaration of Game class
class Game;

/**
 * DeclarationGiven class - a type of Declaration; handles Declaration nodes that have the "name" attribute of
 * "given"
 */
class DeclarationGiven : public Declaration
{
private:
    /// Value of the given
    int mValue;

    /// given image's filename
    std::wstring mImage;

public:
    //// Default constructor (disabled)
    DeclarationGiven() = delete;

    /// Copy constructor (disabled)
    DeclarationGiven(const DeclarationGiven &) = delete;

    /// Assignment operator
    void operator=(const DeclarationGiven &) = delete;

    /// Constructor
    DeclarationGiven(wxXmlNode* node);

    /// Declaration::Create override; modified to accept "given" specific attributes
    void Create(wxXmlNode* node, Game* game) override;

    /**
     * Return the given image filename
     * @return string form of the image's filename
     */
    std::wstring GetImageName() { return mImage; }

};

#endif //PROJECT1_GAMELIB_DECLARATIONGIVEN_H
