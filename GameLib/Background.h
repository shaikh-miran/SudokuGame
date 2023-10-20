/**
 * @file Background.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H
#define PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H

class Background
{
private:


    int m_height;

    int m_width;

    wxString m_id;

    wxString m_image;

public:
    Background(wxXmlNode* node_name);

    int GetHeight () const;

    int GetWidth() const;


    wxString GetId() const;


    wxString GetImage() const;


};

#endif //PROJECT1_PROJECT1_GAMELIB_BACKGROUND_H
