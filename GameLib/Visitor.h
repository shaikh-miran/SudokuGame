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
public:
    /**
     * function to visit digit item
     * @param digit ItemDigit to visit
     */
    virtual void VisitDigit(ItemDigit * digit){}

    /**
     * function to visit given item
     * @param given ItemGiven to visit
     */
    virtual void GivenVisit(ItemGiven *given){}

    /**
     * function to visit sparty item
     * @param sparty Sparty to visit
     */
    virtual void SpartyVisit(Sparty *sparty){}

    /**
     * function to visit xray item
     * @param xray XRay to visit
     */
    virtual void XrayVisit(XRay *xray){}

    /**
     * function to visit background item
     * @param background Background to visit
     */
    virtual void BackgroundVisit(Background * background){}

    /**
     * function to visit container item
     * @param container Container to visit
     */
    virtual void ContainerVisit(ItemContainer *container){}

    /// destructor
    virtual ~Visitor() {}

protected:
    /// constructor
    Visitor(){}

};

#endif //PROJECT1_PROJECT1_GAMELIB_VISITOR_H
