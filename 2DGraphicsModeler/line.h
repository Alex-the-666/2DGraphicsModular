#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line: public Shape
{
public:
    Line() = delete;
    Line(const ShapeBuffer& buffer);
    virtual ~Line()override;

    QPoint getQPointOne()const;
    QPoint getQPointTwo()const;

    void setPointOne(int x,int y){one.setX(x); one.setY(y);}
    void setPointTwo(int x,int y){two.setX(x); two.setY(y);}


    void draw (const int x, const int y)override;
    void draw()override;
    void move(const int x,const int y) override;
    double area() const override;
    double perimeter() const override;

    void drawID();

private:
    QPoint one,two;
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
