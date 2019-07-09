#ifndef LINE_H
#define LINE_H

#include "shape.h"
class Line: public Shape
{
public:
    Line() = delete;
    Line (QPaintDevice *parent);
    virtual ~Line();
};

#endif // LINE_H
