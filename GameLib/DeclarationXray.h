/**
 * @file DeclarationXray.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONXRAY_H
#define PROJECT1_GAMELIB_DECLARATIONXRAY_H

#include "Declaration.h"

/// Forward declaration of Game class
class Game;

/**
 * DeclarationBackground class - a type of Declaration; handles Declaration nodes that have the "name" attribute of
 * "background"
 */
class DeclarationXray : public Declaration
{
private:
    /// Capacity of the XRay object (can hold up to x digits)
    int mCapacity;

    /// XRay image filename
    std::wstring mImage;

public:
    //// Default constructor (disabled)
    DeclarationXray() = delete;

    /// Copy constructor (disabled)
    DeclarationXray(const DeclarationXray &) = delete;

    /// Assignment operator
    void operator=(const DeclarationXray &) = delete;

    /// Constructor
    DeclarationXray(wxXmlNode* node);

    /// Declaration::Create override; modified to accept "xray" specific attributes
    std::shared_ptr<Item> Create(wxXmlNode* node, Game* game) override;

    /**
     * Return the xray image filename
     * @return string form of the image's filename
     */
    std::wstring GetImageName() { return mImage; }


};

#endif //PROJECT1_GAMELIB_DECLARATIONXRAY_H
