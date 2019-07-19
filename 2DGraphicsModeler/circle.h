#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"

//!    Derived Class: Circle
/*!   Circle is a derived class of the ellipse class-
*     Inherits private variables from protected class of ellipse
*     Circle can be styled with different pens, colors, and brushes.
*/
class Circle : public Ellipse
{
public:
      //!Default circle class constructor
      /*!Function calls default base class constructor
      * Base Class Constructor calls setShape() and assigns
      * enum value of CIRCLE- passes object to a Circle object.
      */
    Circle():Ellipse(){setShape(CIRCLE);}

    //!   Circle Class Copy Constructor
    /*!   Copy Constructor for the circle object
    *     \param &arg sets both radius variables to be the same- creating a circle.
    *     passed by const ref.
    */
    Circle(const ShapeBuffer&);

    //!  Virtual Circle Class Destructor
    ~Circle() override {}

    //!   Setter Function that sets the ShapeBuffer to an ellipse object
    /*!   function that is passed a ShapeBuffer Object by reference
    *     \param temp sets the new rectangle objects values used in creation of ellipse/circle
    */
    void setShapeBuffer(ShapeBuffer&)override;

    //!   Setter Function that sets the circle objects dimensions
    /*!   \param int  is the x axis value
    *     \param int  is the y axis value
    *     \param int  the width int value
    *     \param int  the height int value
    *     inline, empty function
    */
    //this function has no definition- only a prototype
    void setDimension(int , int, int, int){}

    //!   Function that draws a Circle
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw a circle
    *     \param x is the left-most coordinate of the object
    *     \param y is the up-most coordinate of the object
    */
    void draw(const int x, const int y) override;

    //!   Function that draws an Circle
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw a circle
    *     calls the drawID function - which assigns an ID #
    *     calls passQPainter function and passes a nullptr
    */
    void draw()override;

    //!   Function that moves a Circle
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.
    *     If it passes the logic check, the passed parameters are saved
    *     as new values
    *     \param x is the x-axis value of the top left corner of the object
    *     \param y is the y-axis value of the top left corner of the object
    */
    void move(const int x, const int y) override;

    //!Function that returns the area of a circle
    /*! Returns a double value of pi_val * radius1 * radius1
    */
    double area() const override;

    //!Function that returns the perimeter of a circle
    /*! Returns a double value of 2 * pi_val * radius1
    */
    double perimeter() const override;
};

#endif // CIRCLE_H
