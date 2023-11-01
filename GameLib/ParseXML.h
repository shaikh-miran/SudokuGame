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
    Game * mGame;

    double mTileWidth;
    double mTileHeight;
    double mWidth;
    double mHeight;
    std::map<std::wstring, std::shared_ptr<Declaration>> mDeclarationMap;

    int numDeclarations = 0;
    int numItems = 0;

    std::vector<int> mSolutionVector;

    Solution * mSolution = new Solution();;

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
    void LoadGame(wxXmlNode * node);

    int GetNumDeclarations() const {return numDeclarations;}
    int GetNumItems() const {return numItems;}
    std::shared_ptr<Declaration> FindDeclaration(std::wstring id);
};

#endif //PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
