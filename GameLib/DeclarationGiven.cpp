/**
 * @file DeclarationGiven.cpp
 * @author Navya Singh
 */

#include "DeclarationGiven.h"

DeclarationGiven::DeclarationGiven(Game *game, const std::wstring &filename) : Declaration(game, filename)
{

}

void DeclarationGiven::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    node->GetAttribute(L"value", L"0").ToInt(&mValue);
}