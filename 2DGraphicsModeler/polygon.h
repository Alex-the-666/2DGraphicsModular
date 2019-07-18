#ifndef POLYGON_H
#define POLYGON_H


#include "shape.h"
#include <cmath>
class Polygon : public Shape
{
public:
    Polygon():Shape(), polygon(G_DEFAULTQRECT) {setShape(POLYGON);};
    Polygon(const ShapeBuffer& buffer);
    ~Polygon()override{}
    void draw(const int x, const int y) override;
    void draw()override;
    void move(const int x, const int y)override;
    double area() const override;
    double perimeter() const override;
    void drawID();


private:
    QPolygon polygon;
    QString stringID;
};




#endif // POLYGON_H
