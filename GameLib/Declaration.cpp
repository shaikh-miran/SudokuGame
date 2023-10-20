/**
 * @file Declaration.cpp
 * @author Navya Singh
 */

#include "pch.h"
#include "Declaration.h"

using namespace std;

Declaration::Declaration(wxXmlNode *node)
{
    mId = node->GetAttribute(L"id").ToStdString();
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}