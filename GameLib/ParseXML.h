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
#include "Solution.h"

class Game;
class Declaration;
/**
 * Class that handles the XML loading aspect of the program.
 */
class ParseXML
{
private:
    /// game instance
    Game * mGame;

    /// tile width member variable
    double mTileWidth;

    /// tile height member variable
    double mTileHeight;

    /// width member variable
    double mWidth;

    /// height member variable
    double mHeight;

    /// declaration map
    std::map<std::wstring, std::shared_ptr<Declaration>> mDeclarationMap;

    /// number of declarations
    int numDeclarations = 0;

    /// number of items
    int numItems = 0;

    /// solution vector
    std::vector<int> mSolutionVector;

    /// solution instance
    Solution * mSolution = new Solution();;

public:
    /// Default constructor (disabled)
    ParseXML() = delete;
    /// Copy constructor (disabled)
    ParseXML(const ParseXML &) = delete;
    /// Assignment operator
    void operator=(const ParseXML &) = delete;

    /// function to parse xml
    ParseXML(Game *game);

    /// load function
    void Load(wxXmlDocument xmlDoc);

    /// load declaration function
    void LoadDeclarations(wxXmlNode *node);

    /// load items function
    void LoadItems(wxXmlNode *node);

    /// load game function
    void LoadGame(wxXmlNode * node);

    /**
     * number of declarations getter
     * @return numDeclarations
     */
    int GetNumDeclarations() const {return numDeclarations;}

    /**
     * getter for numItems
     * @return numItems
     */
    int GetNumItems() const {return numItems;}

    /// find declaration function
    std::shared_ptr<Declaration> FindDeclaration(std::wstring id);
};

#endif //PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
