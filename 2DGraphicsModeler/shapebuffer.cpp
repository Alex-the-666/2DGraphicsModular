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
    try{

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
    switch (shape)
    {
    case LINE:break;
    case POLYLINE: break;
    case POLYGON: break;
    case RECTANGLE: break;
    case SQUARE: break;
    case ELLIPSE: break;
    case CIRCLE: break;
    case TEXT: break;
    }
    }
   catch(MyException){

    }
}

ShapeType ShapeBuffer::setShape(QString& string3)const
{    if (string3.contains("Line"))
    return LINE;
else if (string3.contains("Polyline"))
    return POLYLINE;
else if (string3.contains("Polygon"))
    return POLYGON;
else if (string3.contains("Square"))
    return SQUARE;
else if (string3.contains("Rectangle"))
    return RECTANGLE;
else if (string3.contains("Ellipse"))
    return ELLIPSE;
else if (string3.contains("Circle"))
    return CIRCLE;
else if (string3.contains("Text"))
    return TEXT;
else
    throw MyException();
}

Qt::PenStyle ShapeBuffer::setPenStyle(QString& x) const
{
    if(x.contains("NoPen"))
        return Qt::NoPen;
    else if(x.contains("SolidLine"))
        return Qt::SolidLine;
    else if(x.contains("DashLine"))
        return Qt::DashLine;
    else if(x.contains("DotLine"))
        return Qt::DotLine;
    else if(x.contains("DashDotLine"))
        return Qt::DashDotLine;
    else if(x.contains("DashDotDotLine"))
        return Qt::DashDotDotLine;
    else
        throw MyException();
}

Qt::PenCapStyle ShapeBuffer::setPenCapStyle(QString& x) const
{
    if(x.contains("FlatCap"))
        return Qt::FlatCap;
    else if(x.contains("SquareCap"))
        return Qt::SquareCap;
    else if(x.contains("RoundCap"))
        return Qt::RoundCap;
    else
        throw MyException();
}

Qt::PenJoinStyle ShapeBuffer::setPenJoinStyle(QString& x) const
{
    if(x.contains("MiterJoin"))
        return Qt::MiterJoin;
    else if(x.contains("BevelJoin"))
        return Qt::BevelJoin;
    else if(x.contains("RoundJoin"))
        return Qt::RoundJoin;
    else
        throw MyException();
}

Qt::GlobalColor ShapeBuffer::setColor(QString& x) const
{
    if(x.contains("white"))
        return Qt::white;
    else if(x.contains("black"))
        return Qt::black;
    else if(x.contains("red"))
        return Qt::red;
    else if(x.contains("green"))
        return Qt::green;
    else if(x.contains("blue"))
        return Qt::blue;
    else if(x.contains("cyan"))
        return Qt::cyan;
    else if(x.contains("magenta"))
        return Qt::magenta;
    else if(x.contains("yellow"))
        return Qt::yellow;
    else if(x.contains("gray"))
        return Qt::gray;
    else
        throw MyException();
}

Qt::BrushStyle ShapeBuffer::setBrushStyle(QString & x) const
{
    if(x.contains("SolidPattern"))
        return Qt::SolidPattern;
    else if(x.contains("HorPattern"))
        return Qt::HorPattern;
    else if(x.contains("VerPattern"))
        return Qt::VerPattern;
    else if(x.contains("NoBrush"))
        return Qt::NoBrush;
    else
        throw MyException();
}

QFont::Style ShapeBuffer::getTextFontStyle(QString & x) const
{
    if(x.contains("StyleNormal"))
        return QFont::StyleNormal;
    else if(x.contains("StyleItalic"))
        return QFont::StyleItalic;
    else if(x.contains("StyleOblique"))
        return QFont::StyleOblique;
    else
        throw MyException();
}

QFont::Weight ShapeBuffer::getTextFontWeight(QString & x) const
{
    if(x.contains("Thin"))
        return QFont::Thin;
    else if(x.contains("Normal"))
        return QFont::Normal;
    else if(x.contains("Bold"))
        return QFont::Bold;
    else
        throw MyException();
}
