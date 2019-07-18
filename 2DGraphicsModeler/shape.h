#ifndef SHAPE_H
#define SHAPE_H
#include <Qt>
#include <QFont>
#include <QPainter>
#include "vector.h"
#include <cmath>
#include "shapebuffer.h"

//!     Base Class Shape
/*!   Shape is the base class for the shape objects-
*     all other shapes are derived from this class.
*     contains Pure virtual functions.
*     Abstract Base Class.
*/
class Shape
{
public:
    Shape(): painter{nullptr}, shapeId {getCount()}{}

     //!Delete the object created by the default copy constructor
    Shape(Shape&) = delete;

    //!Delete the object created by the default assignment operator
    /*!Allows for operator overloading in derived classes
    */
    Shape& operator =(Shape&)= delete;

    //!   Shape Class Constructor
    /*!   Constructor for the shape object
    *     \param &buffer is a ShapeBuffer object
    *     passed by const ref.
    */
    Shape(const ShapeBuffer&);

    //!   Overloaded Equality Operator for Shape objects
    /*!    Overloaded equality operator: returns true if
    *       shapeId == the shapeId of the passed paramater
    *       \param rhs is a shape object passed by reference
    */
    bool operator ==(Shape& rhs){return (shapeId==rhs.shapeId);}

    //!   Overloaded Less-Than/Equal To Operator for Shape objects
    /*!    Overloaded less than/equal to operator: returns true if
    *      shapeId <= the shapeId of the passed paramater
    *      \param rhs is a shape object passed by reference
    */
    bool operator <(Shape& rhs){return (shapeId<=rhs.shapeId);}

    //!   Overloaded Greater-Than Operator for Shape objects
    /*!    Overloaded greater than operator: returns true if
    *      shapeId > the shapeId of the passed paramater
    *      \param rhs is a shape object passed by reference
    */
    bool operator >(Shape& rhs) {return (area()>rhs.area());}

    //!   Get functions returns a string of the QT pen style
    /*!    Get function returns a string, depending on the pen.style
    *      function verifies that the style is a valid QT style,
    *      and returns a string of the style
    */
    QString getPenStyle()
    {
        if(pen.style()==Qt::SolidLine)
            return "Solid  Line";
        else if(pen.style()==Qt::DashDotDotLine)
            return "DashDotDotLine";
        else if(pen.style()==Qt::DashDotLine)
            return "DashDotLine";
        else if(pen.style()==Qt::DotLine)
            return "DotLine";
        else if(pen.style()==Qt::DashLine)
            return "DashLine";

    }
//        QString getPenColor()
//        {
//            if(pen.color()==Qt::blue)
//                return "blue";
//            else if(getPen().color()==Qt::green)
//                return "green";
//        }
//        QString getPenCapStyle()
//        {
//            if(pen.capStyle()==Qt::FlatCap)
//                return "FlatCap";
//            else if(getPen().capStyle()==Qt::RoundCap)
//                return "RoundCap";
//        }
//        QString getPenJoint()
//        {
//            if(getPen().joinStyle()==Qt::MiterJoin)
//                return "MiterJoin";
//            else if(getPen().joinStyle()==Qt::RoundJoin)
//                return "RoundJoin";
//        }

    //!   Shape Class Destructor
    virtual ~Shape();

    //!    Get function to return a shape object
    ShapeType getShape() const;

    //!    Get function to return a brush object
    const QBrush& getBrush()const;

    //!    Get function to return a pen object
    const QPen& getPen()const;
    void passQPainter(QPainter* arg ){painter=arg;}

    //!    Set function to assign a shape object
    /*!    Takes a shapetype obj, assigns it to Shape
    *     \param arg is a ShapeType object
    */
    void setShape(ShapeType arg);

    //!    Set function to assign a pen object
    /*!    Takes QT styles and assigns them to the pen object
    *     \param gc is a QT style to set the color of the pen
    *     \param width is an int variable to set the width of the pen
    *     \param ps is a QT style to set the pen style
    *     \param pcs is a QT style to set the pen cap style
    *     \param pjs is a QT style to set the join style of the pen
    */
    void setPen(Qt::GlobalColor gc1, int width,\
                 Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs);
    void setPen(QPen qP){pen= qP;}

      //!    Set function to assign to a brush object
      /*!   Takes QT styles as paramaters and assigns them to the brush object
      *     \param gc is a QT style for global color- sets the brush color
      *     \param bs is a QT style to set the brush style
      */
    void setBrush(Qt::GlobalColor gc2, Qt::BrushStyle bs);
    void setBrush(QBrush qB){brush = qB;}

    //!Pure virtual function- allows for operator overloading of derived classes
    virtual void draw(const int x, const int y) = 0;

    //!Pure virtual function- allows for operator overloading of derived classes
    virtual void draw()=0;

    //!Pure virtual function- allows for operator overloading of derived classes
    virtual void move(const int x,const int y) = 0;

    //!Pure virtual function- allows for operator overloading of derived classes
    virtual double area() const = 0;

    //!Pure virtual function- allows for operator overloading of derived classes
    virtual double perimeter() const =0;
protected:

      //!     Function returns *this pointer, a pointer of type QPainter
    QPainter* getQPainter();

private:
    //! A pointer of type QPainter
    QPainter* painter;
    //! int shapeId assigns shape based on value
    int shapeId;
    //! Shapetype object created, passed to derived classes and shapeBuffer
    ShapeType shape;
    //! QPen object to set the pen styles
    QPen pen;
    //! QBrush object to set the brush styles
    QBrush brush;
    static int getCount();

};

#endif // SHAPE_H
