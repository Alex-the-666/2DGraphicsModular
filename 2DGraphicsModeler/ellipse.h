#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse():Shape(),myRect(G_DEFAULTQRECT){setShape(ELLIPSE);}
    Ellipse(const ShapeBuffer&);
    ~Ellipse() override {}

    void setShapeBuffer(ShapeBuffer&)override;
    void setDimension(int x, int y, int r1, int r2);
    void draw(const int x, const int y) override;
    void draw()override;
    void move(const int x, const int y) override;
    double area() const override;
    double perimeter() const override;
    void drawID();


protected:
    int radius1;
    int radius2;
    int x;
    int y;
    QRect myRect;
    QString stringID;
};

#endif // ELLIPSE_H
