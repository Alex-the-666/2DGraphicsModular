#include "shapebuffer.h"

ShapeBuffer::ShapeBuffer()
{
    shape=LINE;
}

void ShapeBuffer::reset()
{
    shape=LINE;
    qPointVector.resize(0);
    qRect.setRect(0,0,0,0);
    //qPolygon.set
    //I don't know how to use QPolygon
    defaultStyle();

}

void ShapeBuffer::defaultStyle()
{
    pen.setColor(Qt::black);
    pen.setWidth(0);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::RoundJoin);
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    //Going to need default QFont

}

void ShapeBuffer::readIn(QTextStream&)
{
    QString path = "D:/test.txt";
    QString string1 = "ShapeId: 1";
    QString string3 = "Line";
    QString string2 = "ShapeDimensions: 20, 90, 100, 20";
    QStringList list = string1.split(' ');
/*
    QFile file(path);
    file.open(QIODevice::WriteOnly);

    QTextStream out(&file);
    out << list.at(1).toInt();

    string2.remove(',');
    list = string2.split(' ');
    for (int i= 1; i < list.size(); i++)
    {
        out << list.at(i).toInt();
    }
  */
    if (string3.contains("Line"))
        shape = LINE;
    if (string3.contains("Polyline"))
        shape = POLYLINE;
    if (string3.contains("Polygon"))
        shape = POLYGON;
    if (string3.contains("Square"))
        shape = SQUARE;
    if (string3.contains("Rectangle"))
        shape = RECTANGLE;
    if (string3.contains("Ellipse"))
        shape = ELLIPSE;
    if (string3.contains("Circle"))
        shape = CIRCLE;
    if (string3.contains("Text"))
        shape = TEXT;

}
