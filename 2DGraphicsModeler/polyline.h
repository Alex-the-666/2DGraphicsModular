#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
/*! \mainpage Team Ratatouille
*
* \section intro_sec Introduction
*
* This product is a 2D Graphic Modeller that can create a variety of shapes and text objects.
* This program can read in from a text file, and save to a text file.
* The objects that appear on screen can have their: location, color, border, and text modified.
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
