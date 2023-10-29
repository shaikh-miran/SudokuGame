/**
 * @file Visitor.h
 * @author haile
 *
 *
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_VISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_VISITOR_H
class ItemDigit;
class ItemGiven;
class Background;
class ItemContainer;
class Sparty;
class XRay;

class Visitor
{
private:

public:
    virtual void DigitVisit(ItemDigit * digit){}
    virtual void GivenVisit(ItemGiven *given){}
    virtual void SpartyVisit(Sparty *sparty){}
    virtual void XrayVisit(XRay *xray){}

    virtual void BackgroundVisit(Background * background){}
    virtual void ContainerVisit(ItemContainer *container){}
    virtual ~Visitor() {}

protected:

    Visitor(){}

};

#endif //PROJECT1_PROJECT1_GAMELIB_VISITOR_H
