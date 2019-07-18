#ifndef LINE_H
#define LINE_H

#include "shape.h"

//!    Derived Class: Line
/*!   Line is a derived class of the shape class-
*     Takes two points, and draws a line between them.
*     Line can be styled with different pens and brushes.
*/
class Line: public Shape
{
public:

      //!Delete the default constructor
    Line() = delete;

    //!   Line Class Constructor
    /*!   Constructor for the line object
    *     \param &buffer is a ShapeBuffer object
    *     passed by const ref.
    */
    Line(const ShapeBuffer& buffer);

     //!  Virtual Line Class Destructor
    virtual ~Line()override;

    //!   Function that returns a QPoint value
    /*!    QPoint function returns QPoint one
    *     QPoint one is made up of two int values
    *      that correspond to (x,y) coordinates on the screen
    */
    QPoint getQPointOne()const;

    //!   Function that returns a QPoint value
    /*!    QPoint function returns QPoint two
    *     QPoint one is made up of two int values
    *      that correspond to (x,y) coordinates on the screen
    */
    QPoint getQPointTwo()const;

    //!   Inline Setter Function that sets QPoint one
    /*!   Inline function that is passed two int values
    *     \param x sets the x coordinate of the object's 1st point
    *     \param y sets the y coordinate of the object's 1st point
    */
    void setPointOne(int x,int y){one.setX(x); one.setY(y);}

    //!   Inline Setter Function that sets QPoint two
    /*!   Inline function that is passed two int values
    *     \param x sets the x coordinate of the object's 2nd point
    *     \param y sets the y coordinate of the object's 2nd point
    */
    void setPointTwo(int x,int y){two.setX(x); two.setY(y);}

    //!   Function that draws a line
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw a line
    *     \param one is the starting point of the line
    *     \param two is the ending point of the line
    */
    void draw (const int x, const int y)override;

    //!   Function that draws a line
    /*!   Sets the QPainter objects pen
    *     Sets the QPainter objects brush
    *     Sets the QPainter coordinates from which to draw a line
    *     calls the drawID function - which checks if out of bounds
    *     calls passQPainter function and passes a nullptr
    *     \param one is the starting point of the line
    *     \param two is the ending point of the line
    */
    void draw()override;

    //!   Function that moves an object
    /*!   Checks to make sure that the new coordinates that are
    *     passes as parameters does not force the object off the screen.
    *     If it passes the logic check, the passed parameters are saved
    *     as new QPoint one and two
    *     \param x is the x-axis value of the top left corner of the object
    *     \param y is the y-axis value of the top left corner of the object
    */
    void move(const int x,const int y) override;

    //!Function that returns the area of the line
    /*! Function returns 0- no area for a line
    */
    double area() const override;

    //!Function that returns the perimeter of the line
    /*! Returns the square root of QPoint function dotProduct.
    *   dotProduct takes QPoint one and two as parameters
    */
    double perimeter() const override;

    //!Function to find the top left corner of an object
    /*!Compares the first x axis point with the second x axis point-
    * the smaller number is the left most point.
    * Compares the first y axis point with the second y axis point-
    * the smaller number is the highest-up(upmost) point.
    */
    void drawID();

private:

    //! A variable of type QPoint- takes two int values for (x,y) coordinates for each variable
    QPoint one;
    //! A variable of type QPoint- takes two int values for (x,y) coordinates for each variable
    QPoint two;
    //! QString object to store a string value
    QString stringID;
};



//    QString getPenStyle()
//    {
//        if(getPen().style()==Qt::SolidLine)
//            return "Solid  Line";
//        else if(getPen().style()==Qt::DashDotDotLine)
//            return "DashDotDotLine";
//        else if(getPen().style()==Qt::DashDotLine)
//            return "DashDotLine";
//        else if(getPen().style()==Qt::DotLine)
//            return "DotLine";
//        else if(getPen().style()==Qt::DashLine)
//            return "DashLine";
//    }
//    QString getPenColor()
//    {
//        if(getPen().color()==Qt::blue)
//            return "blue";
//        else if(getPen().color()==Qt::green)
//            return "green";
//    }
//    QString getPenCapStyle()
//    {
//        if(getPen().capStyle()==Qt::FlatCap)
//            return "FlatCap";
//        else if(getPen().capStyle()==Qt::RoundCap)
//            return "RoundCap";
//    }
//    QString getPenJoint()
//    {
//        if(getPen().joinStyle()==Qt::MiterJoin)
//            return "MiterJoin";
//        else if(getPen().joinStyle()==Qt::RoundJoin)
//            return "RoundJoin";
//    }


#endif // LINE_H
