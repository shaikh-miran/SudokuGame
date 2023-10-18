/**
 * @file ParseXML.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
#define PROJECT1_PROJECT1_GAMELIB_PARSEXML_H

class ParseXML
{
private:


public:
    void LoadDeclarations();
    void LoadGame();
    void LoadItems();
    void Load(wxXmlDocument xmlDoc);
};

#endif //PROJECT1_PROJECT1_GAMELIB_PARSEXML_H
