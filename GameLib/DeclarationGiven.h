/**
 * @file DeclarationGiven.h
 * @author Navya Singh
 *
 *
 */

#ifndef PROJECT1_GAMELIB_DECLARATIONGIVEN_H
#define PROJECT1_GAMELIB_DECLARATIONGIVEN_H

#include "Declaration.h"
#include "Game.h"

class DeclarationGiven : public Declaration
{
private:

    int mValue;

public:
    /// Default constructor (disabled)
    DeclarationGiven() = delete;

    /// Copy constructor (disabled)
    DeclarationGiven(const DeclarationGiven &) = delete;

    /// Assignment operator
    void operator=(const DeclarationGiven &) = delete;

    DeclarationGiven(Game* game, const std::wstring &filename);
    void XmlLoad(wxXmlNode *node) override;

};

#endif //PROJECT1_GAMELIB_DECLARATIONGIVEN_H
