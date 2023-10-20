/**
 * @file ParseXML.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
#define PROJECT1_PROJECT1_GAMELIB_PARSEXML_H

#include <wx/xml/xml.h>
#include <map>
#include "DeclarationGiven.h"
#include "Declaration.h"

class Game;

/**
 * Class that handles the XML loading aspect of the program.
 */
class ParseXML
{
private:
    Game * mGame;

    double mTileWidth;
    double mTileHeight;
    double mWidth;
    double mHeight;
    std::map<std::string, std::shared_ptr<Declaration>> mDeclarationMap;

public:
    /// Default constructor (disabled)
    ParseXML() = delete;
    /// Copy constructor (disabled)
    ParseXML(const ParseXML &) = delete;
    /// Assignment operator
    void operator=(const ParseXML &) = delete;

    ParseXML(Game *game);

    void Load(wxXmlDocument xmlDoc);
    void LoadDeclarations(wxXmlNode *node);
    void LoadItems(wxXmlNode *node);
};

#endif //PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
