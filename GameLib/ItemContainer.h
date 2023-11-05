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
    /**
     * Accept visitor
     * @param visitor object
     */
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

    /// item container constructor
    ItemContainer(Game* game, std::wstring image1, std::wstring image2, DeclarationContainer *declaration);

    /// draw function, overrides base class
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /// function to add digits
    void AddDigits(std::shared_ptr<Item> digit);

    /// function to eject digits
    void EjectDigits();

    /// function to load xml container
    void ContainerXmlLoad(wxXmlNode *node);

    /// function to check if digit exists
    bool DigitExist(double x, double y);

    /// hit test function
    bool HitTest(int x, int y) override;
};

#endif //PROJECT1_GAMELIB_CONTAINER_H
