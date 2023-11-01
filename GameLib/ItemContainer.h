/**
 * @file ItemContainer.h
 * @author Team Prometheus
 */


#ifndef PROJECT1_GAMELIB_CONTAINER_H
#define PROJECT1_GAMELIB_CONTAINER_H

#include "Item.h"
#include "DeclarationContainer.h"

class Game;
class ItemContainer : public Item
{
private:
    std::unique_ptr<wxImage> mContainerImage;
    std::unique_ptr<wxBitmap> mContainerBitmap;
    std::unique_ptr<wxImage> mContainerFrontImage;
    std::unique_ptr<wxBitmap> mContainerFrontBitmap;

    std::vector<std::shared_ptr<Item>> mDigitList;
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
//    void DrawFront(std::shared_ptr<wxGraphicsContext> graphics);
//    void DrawImage(std::shared_ptr<wxGraphicsContext> graphics);
    void AddDigits(std::shared_ptr<Item> digit);
    void EjectDigits();
    void ContainerXmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_GAMELIB_CONTAINER_H
