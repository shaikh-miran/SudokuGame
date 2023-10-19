/**
 * @file Declaration.cpp
 * @author Navya Singh
 */

#include "Declaration.h"

using namespace std;

Declaration::Declaration(Game *game, const std::wstring &filename) : mGame(game)
{
    mDeclarationImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mDeclarationBitmap = make_unique<wxBitmap>(*mDeclarationImage);
}

void Declaration::XmlLoad(wxXmlNode *node)
{
    auto id = node->GetAttribute(L"id").ToStdString();
    mId = id;
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}