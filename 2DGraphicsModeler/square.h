#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

//!    Derived Class From Base Class Square
/*!   Square is a derived class of the shape class.\n
*     Takes integer values to form dimensions of the square.\n
*     Square can be styled with different pens, colors, and brushes.
*/
class Square: public Shape
{
public:
      //!Default square class constructor
      /*!Function calls default base class constructor.
      * Base Class Constructor calls setShape() and assigns
      * enum value of SQUARE. Shape object passed to Square object.
      */
    Square():Shape(), side{100},\
        _x{50}, _y{50} {setShape(SQUARE);}

    //!   Square Class Copy Constructor
    /*!   Copy Constructor for the square object.
    *     \param &arg is a ShapeBuffer object
    *     Passed by const ref.
    */
    Square(const ShapeBuffer& arg);

    //!  Virtual Square Class Destructor
    virtual ~Square()override{}

    //!   Setter Function that sets the ShapeBuffer to a Square object
    /*!   Function that is passed a ShapeBuffer Object by reference.
    *     \param temp sets the new Square object values
    */
    void setShapeBuffer(ShapeBuffer&)override;

    //this function has no definition- only a prototype
    /*void setDimension(int x, int y);*/

    //!   Function that draws a Square
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a square.\n
    *     \param x is the left-most coordinate of the object
    *     \param y is the up-most coordinate of the object
    */
    void draw (const int x, const int y)override;

    //!   Function that draws a Square
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a square.\n
    *     Calls the drawID function.
    *     Calls passQPainter function and passes a nullptr
    */
    void draw()override;

    //!   Function that moves a Square
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.\n
    *     If it passes the logic check, the passed parameters are saved
    *     as new values.
    *     \param x is the x-axis value of the top left corner of the object
    *     \param y is the y-axis value of the top left corner of the object
    */
    void move(int x, int y) override;

    //!Function that returns the area of a square
    /*! Function returns a double value of the variable side * side
    */
    double area() const override;

    //!Function that returns the perimeter of a square
    /*! Returns a double value of the variable side * 4
    */
    double perimeter() const override;

    //!Function to find the top left corner of an object
    /*!Finds the top - left corner of an object, and assigns
    * an integer value to the object that displays on screen.
    */
    void drawID();

    //!Function that returns the _x value
    int getX() const override { return _x; }

    //!Function that returns the _y value
    int getY() const override { return _y; }

private:
      //! A variable of type int, holds the distance between two points
    int side;
    //! A variable of type int, holds the left-most x value
    int _x;
    //! A variable of type int, holds the up-most y value
    int _y;
    //! A variable of type QString, used for testing purposes in drawId()
    QString stringID;
};

#endif //SQUARE_H
