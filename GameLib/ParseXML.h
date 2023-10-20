/**
 * @file ParseXML.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
#define PROJECT1_PROJECT1_GAMELIB_PARSEXML_H

#include <wx/xml/xml.h>

/**
 * Class that handles the XML loading aspect of the program.
 */
class ParseXML
{
private:
    int numDeclarations = 0;
    int numItems = 0;


public:
    void LoadDeclarations(wxXmlNode * declaration);
    void LoadGame(wxXmlNode * game);
    void LoadItems(wxXmlNode * items);
    void Load(wxXmlDocument xmlDoc);
    int GetNumDeclarations() {return numDeclarations;}
    int GetNumItems() {return numItems;}


};

#endif //PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
