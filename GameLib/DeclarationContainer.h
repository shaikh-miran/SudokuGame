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
/// Call Game class
class Game;

/**
 * Declaration class of Container.
 */
class DeclarationContainer : public Declaration
{
private:

    /// Container's image.
    std::wstring mImage1;
    /// Container's front image.
    std::wstring mImage2;

public:
    //// Default constructor (disabled)
    DeclarationContainer() = delete;

    /// Copy constructor (disabled)
    DeclarationContainer(const DeclarationContainer &) = delete;

    /// Assignment operator
    void operator=(const DeclarationContainer &) = delete;

    /// Gets the image of the container.
    std::wstring GetImage1Name() { return mImage1; }

    /// Gets the front image of the container.
    std::wstring GetImage2Name() { return mImage2; }

    DeclarationContainer(wxXmlNode* node);

    std::shared_ptr<Item> Create(wxXmlNode* node, Game* game) override;





};

#endif //PROJECT1_GAMELIB_DECLARATIONCONTAINER_H
