/**
 * @file Background.cpp
 * @author haile
 */

#include "Background.h"

///create Background constructor ti pull attributes from xml

Background::Background(wxXmlNode* node) {
    // Assuming the attributes are all strings
    m_height = wxAtoi(node->GetAttribute("height", "0"));
    m_width = wxAtoi(node->GetAttribute("width", "0"));
    m_id = node->GetAttribute("id", "");
    m_image = node->GetAttribute("image", "");
}

int Background::GetHeight() const {
    return m_height;
}

int Background::GetWidth() const {
    return m_width;
}

wxString Background::GetId() const {
    return m_id;
}

wxString Background::GetImage() const {
    return m_image;
}