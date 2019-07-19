#ifndef TEXT_H
#define TEXT_H

#include "shape.h"

//!    Derived Class From Base Class Shape
/*!   Text is a derived class of the shape class.\n
*     Takes integer values to form dimensions of the rectangle box surrounding the text.\n
*     The text and rectangle can be styled with different pens, colors, and brushes.\n
*/
class Text : public Shape
{
public:
      //!Default text class constructor
      /*!Function calls default base class constructor.\n
      * Base Class Constructor calls setShape() and assigns
      * enum value of TEXT- passes object to shape object.\n
      * Rectangle object is assigned default properties.
      */
    Text():Shape(), myRect(G_DEFAULTQRECT), myQString(QString("cheese")), font(QFont()), alignFlag(Qt::AlignmentFlag::AlignLeft), x(x), y(y), wide(300), tall(100) {setShape(TEXT);}

    //!   Text Class Copy Constructor
    /*!   Copy Constructor for the text object..\n
    *     pShapeBufferassed by const ref.- sets values of private rectangle.
    *     \param &arg is a ShapeBuffer rectangle object
    */
    Text(const ShapeBuffer& arg);

    //!   Setter Function that sets the text object to the Shape Buffer's values
    /*!   Function that is passed a ShapeBuffer Object by reference.
    *     \param temp sets the new text objects values
    */
    void setShapeBuffer(ShapeBuffer&)override;

   //!   Function that draws Text in a Rectangle
   /*!   Sets the QPainter objects pen.\n
   *     Sets the QPainter objects brush.\n
   *     Sets the QPainter coordinates from which to draw a rectangle box for the text.\n
   *     \param x is the left-most coordinate of the object
   *     \param y is the up-most coordinate of the object
   */
    void draw(const int x, const int y) override;

    //!   Function that draws Text in a Rectangle
    /*!   Sets the QPainter objects pen.\n
    *     Sets the QPainter objects brush.\n
    *     Sets the QPainter coordinates from which to draw a rectangle box for the text.\n
    *     Calls passQPainter function and passes a nullptr.
    */
    void draw()override;

    //!   Function that moves a Text Box
    /*!   Checks to make sure that the new coordinates that are
    *     passed as parameters does not force the object off the screen.\n
    *     If it passes the logic check, the passed parameters are saved
    *     as new values.
    *     \param x1 is the x-axis value of the top left corner of the object
    *     \param y1 is the y-axis value of the top left corner of the object
    */
    void move(const int x1, const int y1) override;

    //!Function that returns the area of a text box
    /*! Returns a double value of the tall * wide
    */
    double area() const override;

    //!Function that returns the perimeter of a text box
    /*! Returns a double value of (2 * (wide + tall)
    */
    double perimeter()const override;

    //!  Virtual Text Class Destructor
    ~Text() override;

    //!Function that returns the x value
    int getX() const override { return x; }

    //!Function that returns the y value
    int getY() const override { return y; }

private:
      //! A variable of type int, holds the left-most x value
    int x;
    //! A variable of type int, holds the up-most y value
    int y;
    //! A variable of type int, holds the width between two points
    int wide;
    //! A variable of type int, holds the height between two points
    int tall;
    //! A variable of type QT class, a flag to set text alignment
    Qt::AlignmentFlag alignFlag;
    //! A variable of type QString, used for displaying the text on screen
    QString myQString;
    //! A variable of type QFont, holds the text font family and pizel size
    QFont font;
    //! A variable of type QRect, the container surrounding the text
    QRect myRect;

};

#endif // TEXT_H
