/**
 * @file Declaration.h
 * @author Navya Singh
 *
 *
 */


#ifndef PROJECT1_GAMELIB_DECLARATION_H
#define PROJECT1_GAMELIB_DECLARATION_H

#include "Item.h"

class Game;
class Declaration
{
private:
    Game *mGame;
    std::string mId;
    double mWidth;
    double mHeight;

public:
    //// Default constructor (disabled)
    Declaration() = delete;
    
    /// Copy constructor (disabled)
    Declaration(const Declaration &) = delete;
    
    /// Assignment operator
    void operator=(const Declaration &) = delete;
    
    
    Declaration(wxXmlNode *node);

    void SetId(std::string id) {mId = id;}

    std::string GetId() const {return mId;}
    double GetWidth() const {return mWidth;}
    double GetHeight() const {return mHeight;}

    virtual void Create(wxXmlNode* node, Game *game) {}
};

#endif //PROJECT1_GAMELIB_DECLARATION_H
