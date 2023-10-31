/**
 * @file DeclarationContainer.h
 * @author Sonia Charles Thalatoti
 *
 *
 */
#include "Declaration.h"
#include "DeclarationDigit.h"
#include "ItemDigit.h"
#ifndef PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
#define PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
class Game;
class DeclarationContainer : public Declaration
{
private:

    std::wstring mImage1;
    std::wstring mImage2;

public:
//// Default constructor (disabled)
    DeclarationContainer() = delete;

    /// Copy constructor (disabled)
    DeclarationContainer(const DeclarationContainer &) = delete;

    /// Assignment operator
    void operator=(const DeclarationContainer &) = delete;

    DeclarationContainer(wxXmlNode* node);

    std::shared_ptr<Item> Create(wxXmlNode* node, Game* game) override;

    std::wstring GetImage1Name() { return mImage1; }
    std::wstring GetImage2Name() { return mImage2; }



};

#endif //PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
