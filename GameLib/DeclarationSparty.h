/**
 * @file DeclarationSparty.h
 * @author Maui Baba
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONSPARTY_H
#define PROJECT1_GAMELIB_DECLARATIONSPARTY_H

#include "Declaration.h"

class DeclarationSparty : public Declaration
{
private:
    /// Main body image
    std::wstring mImage1;

    /// Mouth image
    std::wstring mImage2;

public:
    //// Default constructor (disabled)
    DeclarationSparty() = delete;

    /// Copy constructor (disabled)
    DeclarationSparty(const DeclarationSparty &) = delete;

    /// Assignment operator
    void operator=(const DeclarationSparty &) = delete;

    /// Constructor
    DeclarationSparty(wxXmlNode* node);

    void Create(wxXmlNode* node, Game* game) override;

    /// Return filename of images
    std::wstring GetImage1Name() { return mImage1; }
    std::wstring GetImage2Name() { return mImage2; }
};

#endif //PROJECT1_GAMELIB_DECLARATIONSPARTY_H
