#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
private:
    int width;
    int height;
    int x;
    int y;

public:
    /*CONSTRUCTORS*/
    Rectangle () = delete;
    Rectangle (QPaintDevice* parent, ShapeBuffer arg);

    /*DESTRUCTOR*/
    ~Rectangle ();

    void draw (int, int);
    void move (int, int);
    double area () const;
    double perimeter () const;
};

#endif // RECTANGLE_H
