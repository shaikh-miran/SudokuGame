/**
 * @file DeclarationXray.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONXRAY_H
#define PROJECT1_GAMELIB_DECLARATIONXRAY_H

#include "Declaration.h"

class Game;

class DeclarationXray : public Declaration
{
private:
    int mCapacity;
    std::wstring mImage;

public:
    //// Default constructor (disabled)
    DeclarationXray() = delete;
    
    /// Copy constructor (disabled)
    DeclarationXray(const DeclarationXray &) = delete;
    
    /// Assignment operator
    void operator=(const DeclarationXray &) = delete;

    DeclarationXray(wxXmlNode* node);
    void Create(wxXmlNode* node, Game* game) override;
    std::wstring GetImageName() { return mImage; }
};

#endif //PROJECT1_GAMELIB_DECLARATIONXRAY_H
