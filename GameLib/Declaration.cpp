/**
 * @file Declaration.cpp
 * @author Team Prometheus
 */

#include "pch.h"
#include "Declaration.h"

/**
 * Decalaration constructor implementation - retrieves and stores data from declaration nodes in level XML files.
 * @param node the associated node to get data from
 */
Declaration::Declaration(wxXmlNode *node)
{
    mId = node->GetAttribute(L"id").ToStdString();
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}