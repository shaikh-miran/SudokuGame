/**
 * @file Declaration.h
 * @author Navya Singh
 *
 *
 */


#ifndef PROJECT1_GAMELIB_DECLARATION_H
#define PROJECT1_GAMELIB_DECLARATION_H


class Game;
class Declaration
{
private:
    Game *mGame;
    std::string mId;
    double mWidth;
    double mHeight;

protected:
    /// The underlying fish image
    std::unique_ptr<wxImage> mDeclarationImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mDeclarationBitmap;

public:
    Declaration(Game* game, const std::wstring &filename);
    virtual ~Declaration() {;}

    /// Default constructor (disabled)
    Declaration() = delete;
    /// Copy constructor (disabled)
    Declaration(const Declaration &) = delete;
    /// Assignment operator
    void operator=(const Declaration &) = delete;

    virtual void XmlLoad(wxXmlNode *node);

    void SetId(std::string id) {mId = id;}
};

#endif //PROJECT1_GAMELIB_DECLARATION_H
