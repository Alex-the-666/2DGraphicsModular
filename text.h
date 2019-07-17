#ifndef TEXT_H
#define TEXT_H

#include "shape.h"

class Text : public Shape
{
public:
    Text() = delete;
    Text(const ShapeBuffer& arg);
    void draw(const int x, const int y) override;
    void draw()override;
    void move(const int x1, const int y1) override;
    double area() const override;
    double perimeter()const override;
    ~Text() override;

private:
    int x;
    int y;
    int wide;
    int tall;
    Qt::AlignmentFlag alignFlag;
    QString myQString;
    QFont font;
    QRect myRect;

};

#endif // TEXT_H
