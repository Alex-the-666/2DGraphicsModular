#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

//!    Derived Class: Rectangle
/*!   Rectangle is a derived class of the shape class-
*     Takes integer values to form dimensions of the rectangle
*     Rectangle can be styled with different pens, colors, and brushes.
*/
class Rectangle : public Shape
{
private:
//! A variable of type int, holds the left-most x value
  int x;
//! A variable of type int, holds the up-most y value
  int y;
//! A variable of type int, holds the width between two points
  int width;
//! A variable of type int, holds the height between two points
  int height;
//! A variable of type QString, used for testing purposes in drawId()
  QString stringID;
//! A variable of type QRect
/*! Rectangle object used to set the private variables of
*   the rectangle class
*/
  QRect xyWH;

public:
    /*CONSTRUCTORS*/
    //!Default rectangle class constructor
    /*!Function calls default base class constructor
    * Base Class Constructor calls setShape() and assigns
    * enum value of RECTANGLE- passes object to rectangle class.
    */
    Rectangle(): Shape(), width{200},height{100},\
        x{50}, y{50} {setShape(RECTANGLE);}

      //!   Rectangle Class Copy Constructor
      /*!   Copy Constructor for the rectangle object
      *     \param &arg is a ShapeBuffer object
      *     passed by const ref.
      */
    Rectangle(const ShapeBuffer& arg);

    /*DESTRUCTOR*/
    //!  Virtual Rectangle Class Destructor
    ~Rectangle()override;

    //!   Setter Function that sets the ShapeBuffer to a Rectangle object
    /*!   function that is passed a ShapeBuffer Object by reference
    *     \param temp sets the new Rectangle objects values
    */
    void setShapeBuffer(ShapeBuffer&)override;

    //!   Function that draws a Rectangle
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw a rectangle
    *     \param x is the left-most coordinate of the object
    *     \param y is the up-most coordinate of the object
    */
    void draw(int, int)override;

    //!   Function that draws a Rectangle
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw a rectangle
    *     calls the drawID function - which checks if out of bounds
    *     calls passQPainter function and passes a nullptr
    */
    void draw()override;

    //!   Function that moves a Rectangle
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.
    *     If it passes the logic check, the passed parameters are saved
    *     as new values
    *     \param px is the x-axis value of the top left corner of the object
    *     \param py is the y-axis value of the top left corner of the object
    */
    void move(int, int)override;

    //!Function that returns the area of a rectangle
    /*! Returns a double value of the height * width
    */
    double area() const override;

    //!Function that returns the perimeter of a rectangle
    /*! Returns a double value of (2 * width) + (2 * height)
    */
    double perimeter() const override;

    //!Function to find the top left corner of an object
    /*!Finds the top - left corner of an object, and assigns
    * an integer value to the object that displays on screen.
    */
    void drawID();
};

#endif // RECTANGLE_H
