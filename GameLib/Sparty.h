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

    /// (Level 3) The darkness image name
    std::wstring mDarknessImageFilename;

    /// (Level 3) The underlying Sparty darkness image
    std::unique_ptr<wxImage> mDarknessImage;

    /// (Level 3) The bitmap we can display for the darkness image
    std::unique_ptr<wxBitmap> mDarknessBitmap;

    /// Mouth Attributes
    wxPoint mMouthPivot;
    double mMouthAngle;

    /// Head Attributes
    wxPoint mHeadPivot;
    double mHeadAngle;

    wxPoint mTargetPivot;

    double mTimeHeadbutt = 0;



    double mTimeEating = 0;

    bool mCanMove = false;

    bool mIsLevel3 = false;

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

    bool HitTest(int x, int y) override;

    void SetCanMove(bool value) { mCanMove = value; }

    void Accept(Visitor *visitor) override{
        visitor->SpartyVisit(this);
    }

    /// Update Sparty's darkness level (Level 3 sparty)
    void UpdateDarknessLevel(std::wstring image3);

    /// Returns true if sparty is performing a headbutt or eating action (prevent crash if event + image change occurs
    /// concurrently)
    bool InAction() { return (mTimeHeadbutt != 0 || mTimeEating != 0); }

    /// Set whether this sparty is level 3
    void IsLevel3(bool input) { mIsLevel3 = input; }

    void SetHeadPivot(double x, double y) { mHeadPivot = wxPoint(x, y); }
    void SetHeadAngle(double angle) { mHeadAngle = angle; }
    void SetMouthPivot(double x, double y) { mMouthPivot = wxPoint(x, y); }
    void SetMouthAngle(double angle) { mMouthAngle = angle; }
    void SetTargetPivot(double x, double y) { mTargetPivot = wxPoint(x, y); }
};



#endif //PROJECT1_GAMELIB_SPARTY_H
