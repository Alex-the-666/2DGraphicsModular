#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
/*! \mainpage My Personal Index Page
*
* \section intro_sec Introduction
*
* This is the introduction.
*
* \section install_sec Installation
*
* \subsection step1 Step 1: Opening the box
*     This comment block is saved in polyline.h for modification purposes
* etc...
*     \section list_sec Done so far:
*     shape class \n
*     line class \n
*/

class PolyLine: public Shape
{
public:
    PolyLine();
    PolyLine(const ShapeBuffer& arg);

     ~PolyLine() override {}

    void setShapeBuffer(ShapeBuffer&)override;
    void draw (const int x, const int y)override;
    void draw () override;
    void move(int x, int y) override;
    double area() const override;
    double perimeter() const override;
    void drawID();

private:
    QPolygon qPolygon;
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

#endif // POLYLINE_H
