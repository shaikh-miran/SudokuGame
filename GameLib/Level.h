/**
 * @file Level.h
 * @author haile
 *
 *
 */

#include "pch.h"
#include "Sparty.h"

#include "Scoreboard.h"
#include <vector>
#include "XRay.h"
#include<memory> //shared_ptr
#include <random>
#include "Item.h"


#include <wx/xml/xml.h>
#include <wx/graphics.h>




#include <vector>
#include<memory> //shared_ptr
#include <random>
#include "Item.h"
#include "Scoreboard.h"


#include <wx/xml/xml.h>

#ifndef PROJECT1_PROJECT1_GAMELIB_LEVEL_H
#define PROJECT1_PROJECT1_GAMELIB_LEVEL_H

class Level
{
private:

public:
    void Load(const wxString & filename);
    void XmlSet(wxXmlNode * category);
    void DeclarationLoad(wxXmlNode * declaration);

};

#endif //PROJECT1_PROJECT1_GAMELIB_LEVEL_H
