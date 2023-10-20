/**
 * @file DeclarationDigit.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONDIGIT_H
#define PROJECT1_GAMELIB_DECLARATIONDIGIT_H

#include "Declaration.h"

class Game;

class DeclarationDigit : public Declaration
{
private:
    int mValue;
    std::wstring mImage;

public:
    //// Default constructor (disabled)
    DeclarationDigit() = delete;

    /// Copy constructor (disabled)
    DeclarationDigit(const DeclarationDigit &) = delete;

    /// Assignment operator
    void operator=(const DeclarationDigit &) = delete;

    DeclarationDigit(wxXmlNode* node);

    void Create(wxXmlNode* node, Game* game) override;
    std::wstring GetImageName() { return mImage; }
};

#endif //PROJECT1_GAMELIB_DECLARATIONDIGIT_H