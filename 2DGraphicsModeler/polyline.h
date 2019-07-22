#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
/*! \mainpage Team Ratatouille
*
* This product is a 2D Graphic Modeller that can create a variety of shapes and text objects.
* This program can read in from a text file, and save to a text file.\n
* The objects that appear on screen can have their: location, color, border, and text modified.\n\n\n
* Created by: Alexander Rownlands, Arthur Siu, Blake Del Rey, Dylan Rossi, Matin Ghaffari, Sina Havaeeahari, and William Duong.
*/

//!    Derived Class From Base Class Shape
/*!   PolyLine is a derived class of the shape class.\n
*     PolyLine can be styled with different pens, colors, and brushes.
*/
class PolyLine: public Shape
{
public:
      //!Default PolyLine class constructor
      /*!Function calls default base class constructor.\n
      * Base Class Constructor calls setShape() and assigns
      * enum value of POLYLINE- passes object to PolyLine class.
      */
    PolyLine();
    //!   PolyLine Class Copy Constructor
    /*!   Copy Constructor for the Polyline object.
    *     Parameter is passed by const ref.
    *     \param &arg is a ShapeBuffer object
    */
    PolyLine(const ShapeBuffer& arg);

    //!  Virtual PolyLine Class Destructor
     ~PolyLine() override {}

     //!   Setter Function that sets the ShapeBuffer to a polyline object
     /*!   Function is passed a ShapeBuffer Object by reference.
     *     \param temp sets the new PolyLine objects values
     */
    void setShapeBuffer(ShapeBuffer&)override;

    //!   Function that draws a PolyLine
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a polyline.
    *     \param x is the left-most coordinate of the object
    *     \param y is the up-most coordinate of the object
    */
    void draw (const int x, const int y)override;

    //!   Function that draws a PolyLine
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a polyline.
    *     calls the drawID function - which checks if out of bounds
    *     calls passQPainter function and passes a nullptr
    */
    void draw () override;

    //!   Function that moves a PolyLine
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.\n
    *     If it passes the logic check, the passed parameters are saved
    *     as new values.
    *     \param x is the x-axis value of the top left corner of the object
    *     \param y is the y-axis value of the top left corner of the object
    */
    void move(int x, int y) override;

    //!Function that returns the area of a PolyLine
    /*! Returns a double value of the area of a polyline.
    */
    double area() const override;

    //!Function that returns the perimeter of a PolyLine
    /*! Returns a double value of the perimeter of a PolyLine.
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
    QPolygon qPolygon;
    //! A variable of type QString, used for testing purposes and in drawId()
    QString stringID;
};

#endif // POLYLINE_H
