#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <cmath>

//!    Derived Class From Base Class Shape
/*!   Polygon is a derived class of the shape class.\n
*     Polygon can be styled with different pens, colors, and brushes.
*/
class Polygon : public Shape
{
public:
      //!Default Polygon class constructor
      /*!Function calls default base class constructor.\n
      * Base Class Constructor calls setShape() and assigns
      * enum value of POLYGON- passes object to Polygon class.
      */
    Polygon():Shape(), polygon(G_DEFAULTQRECT) {setShape(POLYGON);};

    //!   Polygon Class Copy Constructor
    /*!   Copy Constructor for the Polygon object.
    *     Parameter is passed by const ref.
    *     \param &buffer is a ShapeBuffer object
    */
    Polygon(const ShapeBuffer& buffer);

    //!  Virtual Polygon Class Destructor
    ~Polygon()override{}

    //!   Setter Function that sets the ShapeBuffer to a Polygon object
    /*!   Function is passed a ShapeBuffer Object by reference.
    *     \param temp sets the new polygon objects values
    */
    void setShapeBuffer(ShapeBuffer&)override;

    //!   Function that draws a Polygon
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a polygon.
    *     \param x is the left-most coordinate of the object
    *     \param y is the up-most coordinate of the object
    */
    void draw(const int x, const int y) override;

    //!   Function that draws a Polygon
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a polygon.
    *     calls the drawID function - which assigns an ID# to the object.
    *     calls passQPainter function and passes a nullptr
    */
    void draw()override;

    //!   Function that moves a Polygon
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.\n
    *     If it passes the logic check, the passed parameters are saved
    *     as new values.
    *     \param x is the x-axis value of the top left corner of the object
    *     \param y is the y-axis value of the top left corner of the object
    */
    void move(const int x, const int y)override;

    //!Function that returns the area of a Polygon
    /*! Returns a double value of the area of a polygon.
    */
    double area() const override;

    //!Function that returns the perimeter of a Polygon
    /*! Returns a double value of the perimeter of a polygon.
    */
    double perimeter() const override;

    //!Function to find the top left corner of an object
    /*!Finds the top - left corner of an object, and assigns
    * an integer value to the object that displays on screen.
    */
    void drawID();

    //!Function that returns the x value
    int getX() const override;

    //!Function that returns the y value
    int getY() const override;

private:
      //! A variable of type QPolygon, creates a QPolygon object
    QPolygon polygon;
    //! A variable of type QString, used for testing purposes and in drawId()
    QString stringID;
};




#endif // POLYGON_H
