#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

//Hello world
class Square: public Shape
{
public:   
    Square():Shape(){setShape(SQUARE);}

    Square(const ShapeBuffer& arg);

    virtual ~Square()override{}

    void setDimension(int x, int y);

    void draw (const int x, const int y)override;
    void draw()override;
    void move(int x, int y) override;
    double area() const override;
    double perimeter() const override;
    void drawID();

private:
    int side;
    int _x;
    int _y;
    QString stringID;
};

#endif //SQUARE_H
