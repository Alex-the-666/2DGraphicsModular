#ifndef TEXT_H
#define TEXT_H

#include "shape.h"

class Text : public Shape
{
public:
    Text() = delete;
    Text(QPaintDevice * parent, const ShapeBuffer& arg);
    void draw(const int x, const int y) override;
    void move(const int x, const int y) override;
    double area() const override;
    double perimeter()const override;
    ~Text() override{}

private:
    int x;
    int y;
    int wide;
    int tall;
    QFont font;
    Qt::AlignmentFlag alignFlag;



};

#endif // TEXT_H
