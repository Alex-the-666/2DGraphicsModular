#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

//!    Derived Class From Base Shape Class
/*!   Ellipse is a derived class of the shape class.\n
*     Takes integer values to form dimensions of the ellipse.\n
*     Ellipse can be styled with different pens, colors, and brushes.
*/
class Ellipse : public Shape
{
public:
      //!Default ellipse class constructor
     /*!Function calls default base class constructor
     * Base Class Constructor calls setShape() and assigns
     * enum value of ELLIPSE- passes object to a rectangle object.
     */
    Ellipse():Shape(),myRect(G_DEFAULTQRECT), radius1(100), radius2(200), x(100), y(100) {setShape(ELLIPSE);}

    //!Ellipse overloaded class constructor
    /*!Function calls default base class constructor
    * Base Class Constructor calls setShape() and assigns
    * enum value of ELLIPSE- passes object to a rectangle object.
    * \param radius1 holds the height value of the object
    * \param radius2 holds the width value of the object
    * \param x holds the x-value of the coordinate of the object
    * \param y holds the y-value of the coordinate of the object
    */
    Ellipse(int radius1, int radius2, int x, int y) : Shape(), myRect(G_DEFAULTQRECT), radius1(radius1), radius2(radius2), x(x), y(y) { setShape(ELLIPSE);}
    //!   Ellipse Class Copy Constructor
    /*!   Copy Constructor for the ellipse object
    *     paramater passed by const ref. to the ellipse object.
    *     \param &arg is a ShapeBuffer object
    */
    Ellipse(const ShapeBuffer&);

    //!  Virtual Ellipse Class Destructor
    ~Ellipse() override {}


    //this function has no definition- only a prototype
    /*void setDimension(int x, int y, int r1, int r2);*/

    //!   Function that draws an Ellipse
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw an ellipse
    *     \param x is the left-most coordinate of the object
    *     \param y is the up-most coordinate of the object
    */
    void draw(const int x, const int y) override;

    //!   Function that draws an Ellipse
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw an ellipse
    *     calls the drawID function - which assigns an ID #
    *     calls passQPainter function and passes a nullptr
    */
    void draw()override;

    //!   Function that moves an Ellipse
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.
    *     If it passes the logic check, the passed parameters are saved
    *     as new values
    *     \param x is the x-axis value of the top left corner of the object
    *     \param y is the y-axis value of the top left corner of the object
    */
    void move(const int x, const int y) override;

    //!Function that returns the area of an ellipse
    /*! Returns a double value of pi_val * radius1 * radius2
    */
    double area() const override;

    //!Function that returns the perimeter of an ellipse
    /*! Returns a double value of the perimeter of the ellipse object
    */
    double perimeter() const override;

    //!Function to find the top left corner of an object
    /*!Finds the top - left corner of an object, and assigns
    * an integer value to the object that displays on screen.
    */
    void drawID();

    //!   Setter Function that sets the ShapeBuffer to a Ellipse object
    /*!   function that is passed a ShapeBuffer Object by reference
    *     \param temp sets the new Rectangle objects values used in creation of ellipse
    */
    void setShapeBuffer (ShapeBuffer&);

    //!Function that returns the x value
    int getX() const override { return x; }

    //!Function that returns the y value
    int getY() const override { return y; }
protected:
      //! A variable of type int, holds the width of the object
    int radius1;
    //! A variable of type int, holds the height of the object
    int radius2;
    //! A variable of type int, holds the left-most x value
    int x;
    //! A variable of type int, holds the up-most y value
    int y;
    //! A variable of type QRect
    /*! Rectangle object used to set the private variables of
    *   the ellipse class
    */
    QRect myRect;
    //! A variable of type QString, used for displaying Id on screen in drawId()
    QString stringID;
};

#endif // ELLIPSE_H
