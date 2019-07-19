#ifndef CIRCLE_H
#define CIRCLE_H
#include "ellipse.h"

//!    Derived Class From Base Class Ellipse
/*!   Circle is a derived class of the ellipse class.\n
*     Inherits private variables from protected class of ellipse.\n
*     Circle can be styled with different pens, colors, and brushes.
*/
class Circle : public Ellipse
{
public:
      //!Default circle class constructor
      /*!Function calls default base class constructor
      * Base Class Constructor calls setShape() and assigns
      * enum value of CIRCLE- passes object to a Circle object.\n
      * Passes int values for generic size of object.
      */
    Circle():Ellipse(100, 100, 100, 100) {setShape(CIRCLE);}

    //!   Circle Class Copy Constructor
    /*!   Copy Constructor for the circle object.\n
    *     Parameter passed by const reference.
    *     \param &arg sets both radius variables to be the same- creating a circle.
    */
    Circle(const ShapeBuffer&);

    //!  Virtual Circle Class Destructor
    ~Circle() override {}

    //!   Setter Function that sets the ellipse to a ShapeBuffer object
    /*!   function that is passed a ShapeBuffer Object by reference
    *     \param temp sets the new rectangle objects values used in creation of ellipse/circle
    */
    void setShapeBuffer(ShapeBuffer&)override;


    //this function has no definition- only a prototype
    /*void setDimension(int , int, int, int){}*/

    //!   Function that draws a Circle
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a circle.\n
    *     \param x is the left-most coordinate of the object
    *     \param y is the up-most coordinate of the object
    */
    void draw(const int x, const int y) override;

    //!   Function that draws an Circle
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a circle.\n
    *     Calls the drawID function - which assigns an ID #.\n
    *     Calls passQPainter function and passes a nullptr.
    */
    void draw()override;

    //!   Function that moves a Circle
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.\n
    *     If it passes the logic check, the passed parameters are saved
    *     as new values.
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
