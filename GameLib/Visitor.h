/**
 * @file Visitor.h
 * @author Team Prometheus
 */

#ifndef PROJECT1_PROJECT1_GAMELIB_VISITOR_H
#define PROJECT1_PROJECT1_GAMELIB_VISITOR_H

/// class declaration
class ItemDigit;
class ItemGiven;
class Background;
class ItemContainer;
class Sparty;
class XRay;

/**
 * visitor class to visit items
 */
class Visitor
{
private:

public:
    /// function to visit digit item
    virtual void VisitDigit(ItemDigit * digit){}

    /// function to visit given item
    virtual void GivenVisit(ItemGiven *given){}

    /// function to visit sparty item
    virtual void SpartyVisit(Sparty *sparty){}

    /// function to visit xray item
    virtual void XrayVisit(XRay *xray){}

    /// function to visit background item
    virtual void BackgroundVisit(Background * background){}

    /// function to visit container item
    virtual void ContainerVisit(ItemContainer *container){}

    /// destructor
    virtual ~Visitor() {}

protected:

    /// constructor
    Visitor(){}

};

#endif //PROJECT1_PROJECT1_GAMELIB_VISITOR_H
