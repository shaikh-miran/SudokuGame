/**
 * @file DeclarationBackground.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONBACKGROUND_H
#define PROJECT1_GAMELIB_DECLARATIONBACKGROUND_H

#include "Declaration.h"

class Game;

class DeclarationBackground : public Declaration
{
private:
    std::wstring mImage;

public:
    //// Default constructor (disabled)
    DeclarationBackground() = delete;

    /// Copy constructor (disabled)
    DeclarationBackground(const DeclarationBackground &) = delete;

    /// Assignment operator
    void operator=(const DeclarationBackground &) = delete;

    DeclarationBackground(wxXmlNode* node);

    void Create(wxXmlNode* node, Game* game) override;
    std::wstring GetImageName() { return mImage; }
};

#endif //PROJECT1_GAMELIB_DECLARATIONBACKGROUND_H
