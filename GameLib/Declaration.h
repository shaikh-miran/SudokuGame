/**
 * @file Declaration.h
 * @author Team Prometheus
 *
 *
 */


#ifndef PROJECT1_GAMELIB_DECLARATION_H
#define PROJECT1_GAMELIB_DECLARATION_H

#include <utility>
//#include "ItemContainer.h"
//#include "ParseXML.h"
#include "Item.h"

/// Forward declaration of game class
class Game;
class ItemContainer;
class ParseXML;

/**
 * Class Declaration - Stores relevant data from declaration nodes in the level XML file. Declaration objects are used
 * in conjunction with the ParseXML class to handle the creation of items displayed in the game window.
 */
class Declaration
{
private:
    /// The Game object that the (soon-to-be) item will be associated with
    Game *mGame;

    /// The XML file-specified ID of the declaration node
    std::string mId;

    /// Item width
    double mWidth;

    /// Item height
    double mHeight;

    /// item instance
    std::shared_ptr<Item> item;

    /// class ParseXML call.
    ParseXML *mLevel;

public:
    //// Default constructor (disabled)
    Declaration() = delete;

    /// Copy constructor (disabled)
    Declaration(const Declaration &) = delete;

    /// Assignment operator
    void operator=(const Declaration &) = delete;

    /// Constructor
    Declaration(wxXmlNode *node);

    /**
     * Set the declaration's id based on an input string
     * @param id the string to set the mId member variable to
     */
    void SetId(std::string id) { mId = id; }

    /**
     * SEts the level based on the xml.
     * @param level a parse xml call for the nodes.
     */
    void SetLevel(ParseXML *level){ mLevel = level;}

    /**
     * Gets the level from the xml.
     * @return returns the level.
     */
    ParseXML * GetLevel(){return mLevel;}

    /**
     * Return the declaration id (mID)
     * @return string form of the id
     */
    std::string GetId() const { return mId; }

    /**
     * Return the item declaration's width
     * @return width, in double form
     */
    double GetWidth() const { return mWidth; }

    /**
     * Return the item declaration's height
     * @return height, in double form
     */
    double GetHeight() const { return mHeight; }

    /**
     * Create the Item object with the specifications from the declaration object.
     * @param node the "item" node to associate with the "declaration" node (this)
     * @param game the Game object in which the Item object will reside in
     */
    virtual std::shared_ptr<Item> Create(wxXmlNode* node, Game *game) {return item;}

    /**
     * Create the Item object with the specifications from the declaration object and adds it to the container.
     * @param node the "item" node to associate with the "declaration" node (this)
     * @param game the Game object in which the Item object will reside in
     */
    virtual std::shared_ptr<Item> CreateContainer(wxXmlNode* node, Game* game)  {return item;}
};

#endif //PROJECT1_GAMELIB_DECLARATION_H
