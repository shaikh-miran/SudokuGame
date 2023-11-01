/**
 * @file DeclarationDigit.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONDIGIT_H
#define PROJECT1_GAMELIB_DECLARATIONDIGIT_H

#include "Declaration.h"
/// Forward declaration of Game class
class Game;

/**
 * DeclarationDigit class - a type of Declaration; handles Declaration nodes that have the "name" attribute of
 * "digit"
 */

class DeclarationDigit : public Declaration
{
private:
    /// the Digit's value
    int mValue;

    /// Digit item image filename
    std::wstring mImage;

public:
    //// Default constructor (disabled)
    DeclarationDigit() = delete;

    /// Copy constructor (disabled)
    DeclarationDigit(const DeclarationDigit &) = delete;

    /// Assignment operator
    void operator=(const DeclarationDigit &) = delete;

    /// Constructor
    DeclarationDigit(wxXmlNode* node);

    // Declaration::Create override; modified to accept "digit" specific attributes
    std::shared_ptr<Item> Create(wxXmlNode* node, Game* game) override;

    std::shared_ptr<Item> CreateContainer(wxXmlNode* node, Game* game) override;
    /**
     * Return the digit image filename
     * @return string form of the image's filename
     */
    std::wstring GetImageName() { return mImage; }

};

#endif //PROJECT1_GAMELIB_DECLARATIONDIGIT_H
