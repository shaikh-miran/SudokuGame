/**
 * @file ItemContainer.h
 * @author Team Prometheus
 */


#ifndef PROJECT1_GAMELIB_CONTAINER_H
#define PROJECT1_GAMELIB_CONTAINER_H

#include "Item.h"
#include "Game.h"
#include "DeclarationContainer.h"


/**
 * Item Container Class
 */
class ItemContainer : public Item
{
private:
    /// Container's Image
    std::unique_ptr<wxImage> mContainerImage;

    /// Container's Bitmap
    std::unique_ptr<wxBitmap> mContainerBitmap;

    /// Container's front image
    std::unique_ptr<wxImage> mContainerFrontImage;

    /// Container's front Bitmap
    std::unique_ptr<wxBitmap> mContainerFrontBitmap;

    /// Vector of digits in the container.
    std::vector<std::shared_ptr<Item>> mDigitList;

    /// A declarationContainer call to get the iD for a item.
    DeclarationContainer *mDeclaration;

public:
    ///// needed for sparty mouth
    void Accept(Visitor * visitor) override
    {
        visitor->ContainerVisit(this);
    }

    //// Default constructor (disabled)
    ItemContainer() = delete;

    /// Copy constructor (disabled)
    ItemContainer(const ItemContainer &) = delete;

    /// Assignment operator
    void operator=(const ItemContainer &) = delete;

    ItemContainer(Game* game, std::wstring image1, std::wstring image2, DeclarationContainer *declaration);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void AddDigits(std::shared_ptr<Item> digit);
    void EjectDigits();
    void ContainerXmlLoad(wxXmlNode *node);
    bool DigitExist(double x, double y);
};

#endif //PROJECT1_GAMELIB_CONTAINER_H
