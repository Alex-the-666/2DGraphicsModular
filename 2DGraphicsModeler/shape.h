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
      //!Default Inline constructor.
    Shape(): painter{nullptr}, shapeId {getCount()}{}

     //!Delete the object created by the default copy constructor
    Shape(Shape&) = delete;

    //!Delete the object created by the default assignment operator
    /*!Allows for operator overloading in derived classes
    */
    Shape& operator =(Shape&)= delete;

    //!   Shape Class Copy Constructor
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

    //!   Shape Class Destructor
    virtual ~Shape();

    //!    Get function to return a shape object
    ShapeType getShape() const;

    //!    Get function to return a brush object
    const QBrush& getBrush()const;

    //!    Get function to return a pen object
    const QPen& getPen()const;
    //!Default copy constructor
    /*!\param temp is a Shapebuffer object passed by reference
    * temp object copies its values from the shape object
    */
    virtual void setShapeBuffer(ShapeBuffer&);

    //!Function to receive a QPaint pointer
    /*!A QPainter pointer is passed to the function.
    *\param arg is a pointer of QPainter class
    */
    void passQPainter(QPainter* arg ){painter=arg;}

    //!    Set function to assign a shape object
    /*!    Takes a shapetype obj, assigns it to Shape
    *     \param arg is a ShapeType object
    */
    void setShape(ShapeType arg);

    //!    Set function to assign a pen object
    /*!    Takes QT styles and assigns them to the pen object
    *     \param gc1 is a QT style to set the color of the pen
    *     \param width is an int variable to set the width of the pen
    *     \param ps is a QT style to set the pen style
    *     \param pcs is a QT style to set the pen cap style
    *     \param pjs is a QT style to set the join style of the pen
    */
    void setPen(Qt::GlobalColor gc1, int width,\
                 Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs);

      //!    Set function to assign a pen object
      /*!    Takes QPen object and assigns it to the pen object
      *     \param qP is a QPen object to set the pen style
      */
    void setPen(QPen qP){pen= qP;}

      //!    Set function to assign to a brush object
      /*!   Takes QT styles as paramaters and assigns them to the brush object
      *     \param gc2 is a QT style for global color- sets the brush color
      *     \param bs is a QT style to set the brush style
      */
    void setBrush(Qt::GlobalColor gc2, Qt::BrushStyle bs);

    //!    Set function to assign to a brush object
    /*!   Takes QBrush object as paramater and assigns it to the brush object
    *     \param qB is a QBrush object - sets the brush color
    */
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
    //! Static member function, returns integer value referred to as count
      /*!Each function call increases count by one
      */
    static int getCount();

};

#endif // SHAPE_H
