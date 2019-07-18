#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
private:
  int x;
  int y;
  int width;
  int height;

  QString stringID;
  QRect xyWH;

public:
    /*CONSTRUCTORS*/
    Rectangle(): Shape(), width{100},height{100},\
        x{50}, y{50} {setShape(RECTANGLE);}
    Rectangle(const ShapeBuffer& arg);

    /*DESTRUCTOR*/
    ~Rectangle()override;

      void setShapeBuffer(ShapeBuffer&)override;
    void draw(int, int)override;
    void draw()override;

    void move(int, int)override;
    double area() const override;
    double perimeter() const override;

    void drawID();
};

#endif // RECTANGLE_H
