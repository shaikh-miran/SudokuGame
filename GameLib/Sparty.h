/**
 * @file Sparty.h
 * @author Sonia Charles Thalatoti
 *
 *
 */

#include "Item.h"
#include "DeclarationSparty.h"
#ifndef PROJECT1_GAMELIB_SPARTY_H
#define PROJECT1_GAMELIB_SPARTY_H

class Sparty: public Item
{
private:
    //headbutting
    static const double HeadbuttTime;

    /// The underlying Sparty image
    std::unique_ptr<wxImage> mSpartyImage;

    /// The bitmap we can display for this Sparty
    std::unique_ptr<wxBitmap> mSpartyBitmap;

    /// The underlying Sparty Mouth image
    std::unique_ptr<wxImage> mSpartyMouthImage;

    /// The bitmap we can display for this Sparty Mouth
    std::unique_ptr<wxBitmap> mSpartyMouthBitmap;

    /// moving mouth
    wxPoint mMouthPivot = wxPoint(39, 86);
    double mAngleOfMouth = 1;

    wxPoint mHeadPivot = wxPoint(30, 86);

    wxPoint mTargetPivot = wxPoint(72, 24);

    double mTimeHeadbutt = 0;

    double mAngleofHead = .8;

    double mTimeEating = 0;

    bool mCanMove = false;

public:
    //headbutting
    void StartHeadbutt();
    //headbutting
    void BKeyPressed(wxKeyEvent& event);

    void Headbutt();

    void Yum();

    /// Default constructor (disabled)
    Sparty() = delete;

    /// Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    /// Assignment operator
    void operator=(const Sparty &) = delete;

    /// Constructor
    Sparty(Game *game, std::wstring image1, std::wstring image2);

    void Update(double elapsed) override;

    void Draw( std::shared_ptr<wxGraphicsContext> graphics) override;
    void DrawTop( std::shared_ptr<wxGraphicsContext> graphics);
    void DrawBottom( std::shared_ptr<wxGraphicsContext> graphics);

    bool HitTest(int x, int y) override;

    /// moving mouth
    void SetMouthPivot(const wxPoint& pivot);
    void SetMouthAngle(double angle);

    void SetCanMove(bool value) { mCanMove = value; }

    void Accept(Visitor *visitor) override{
        visitor->SpartyVisit(this);
    }

    /// Update Sparty's image post-initialization
    void UpdateSpartyImage(std::wstring image1, std::wstring image2);

    /// Returns true if sparty is performing a headbutt or eating action (prevent crash if event + image change occurs
    /// concurrently)
    bool InAction() { return mTimeHeadbutt != 0 or mTimeEating != 0; }
};



#endif //PROJECT1_GAMELIB_SPARTY_H
