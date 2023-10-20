/**
 * @file DeclarationGiven.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONGIVEN_H
#define PROJECT1_GAMELIB_DECLARATIONGIVEN_H

#include "Declaration.h"

class Game;

class DeclarationGiven : public Declaration
{
private:
    int mValue;
    std::wstring mImage;

public:
    //// Default constructor (disabled)
    DeclarationGiven() = delete;

    /// Copy constructor (disabled)
    DeclarationGiven(const DeclarationGiven &) = delete;

    /// Assignment operator
    void operator=(const DeclarationGiven &) = delete;

    DeclarationGiven(wxXmlNode* node);
    void Create(wxXmlNode* node, Game* game) override;
    std::wstring GetImageName() { return mImage; }

};

#endif //PROJECT1_GAMELIB_DECLARATIONGIVEN_H
