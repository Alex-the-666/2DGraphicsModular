#include "shapebuffer.h"

ShapeBuffer::ShapeBuffer()
{
    shape=LINE;
}

void ShapeBuffer::readIn(QTextStream& is)
{
    try{
        QString myString = is.readLine();
        shapeID = setInt(myString);
        myString = is.readLine();
        shape = setShape(myString);
        if(!is.atEnd())
        {
    switch (shape)
    {
    case LINE:
    {
        myString = is.readLine();
        setLineDimensions(myString,one,two);
        myString = is.readLine();
        pen.setColor(setColor(myString));
        myString = is.readLine();
        pen.setWidth(setInt(myString));
        myString = is.readLine();
        pen.setStyle(setPenStyle(myString));
        myString = is.readLine();
        pen.setCapStyle(setPenCapStyle(myString));
        myString = is.readLine();
        pen.setJoinStyle(setPenJoinStyle(myString));
        brush.setStyle(Qt::NoBrush);
    }
        break;
    case POLYLINE:{
       myString = is.readLine();
       qPolygon = setPolygonDimensions(myString);
       myString = is.readLine();
       pen.setColor(setColor(myString));
       myString = is.readLine();
       pen.setWidth(setInt(myString));
       myString = is.readLine();
       pen.setStyle(setPenStyle(myString));
       myString = is.readLine();
       pen.setCapStyle(setPenCapStyle(myString));
       myString = is.readLine();
       pen.setJoinStyle(setPenJoinStyle(myString));
       brush.setStyle(Qt::NoBrush);


    } break;
    case POLYGON:{
        myString = is.readLine();
        qPolygon = setPolygonDimensions(myString);
        myString = is.readLine();
        pen.setColor(setColor(myString));
        myString = is.readLine();
        pen.setWidth(setInt(myString));
        myString = is.readLine();
        pen.setStyle(setPenStyle(myString));
        myString = is.readLine();
        pen.setCapStyle(setPenCapStyle(myString));
        myString = is.readLine();
        pen.setJoinStyle(setPenJoinStyle(myString));
        myString = is.readLine();
        brush.setColor(setColor(myString));
        myString = is.readLine();
        brush.setStyle(setBrushStyle(myString));
    }
        break;
    case ELLIPSE:
    case RECTANGLE:
    {
        myString = is.readLine();
        qRect = setQRect(myString);
        myString = is.readLine();
        pen.setColor(setColor(myString));
        myString = is.readLine();
        pen.setWidth(setInt(myString));
        myString = is.readLine();
        pen.setStyle(setPenStyle(myString));
        myString = is.readLine();
        pen.setCapStyle(setPenCapStyle(myString));
        myString = is.readLine();
        pen.setJoinStyle(setPenJoinStyle(myString));
        myString = is.readLine();
        brush.setColor(setColor(myString));
        myString = is.readLine();
        brush.setStyle(setBrushStyle(myString));

    }break;
    case SQUARE:
    {
        myString = is.readLine();
        qRect = setQRect(myString);
        myString = is.readLine();
        pen.setColor(setColor(myString));
        myString = is.readLine();
        pen.setWidth(setInt(myString));
        myString = is.readLine();
        pen.setStyle(setPenStyle(myString));
        myString = is.readLine();
        pen.setCapStyle(setPenCapStyle(myString));
        myString = is.readLine();
        pen.setJoinStyle(setPenJoinStyle(myString));
        myString = is.readLine();
        brush.setColor(setColor(myString));
        myString = is.readLine();
        brush.setStyle(setBrushStyle(myString));

    }break;
    case CIRCLE:
    {
        myString = is.readLine();
        qRect = setEllipseOrSquare(myString);
        myString = is.readLine();
        pen.setColor(setColor(myString));
        myString = is.readLine();
        pen.setWidth(setInt(myString));
        myString = is.readLine();
        pen.setStyle(setPenStyle(myString));
        myString = is.readLine();
        pen.setCapStyle(setPenCapStyle(myString));
        myString = is.readLine();
        pen.setJoinStyle(setPenJoinStyle(myString));
        myString = is.readLine();
        brush.setColor(setColor(myString));
        myString = is.readLine();
        brush.setStyle(setBrushStyle(myString));

    }
        break;
    case TEXT:
    {
        myString = is.readLine();
        qRect = setQRect(myString);
        myString = is.readLine();
        qStringText = setQStringText(myString);
        myString = is.readLine();
        brush.setColor(setColor(myString));
        myString = is.readLine();
        alignFlag = setTextAlignment(myString);
        myString = is.readLine();
        font.setPointSize(setInt(myString));
        myString = is.readLine();
        font.setFamily(setQStringText(myString));
        myString = is.readLine();
        font.setStyle(setTextFontStyle(myString));
        myString = is.readLine();
        font.setWeight(setTextFontWeight(myString));
    }
        break;
    }//end switch block
    }//end if block
}//end try block
   catch(MyException){

    }
    catch(...)
    {

    }
}

int ShapeBuffer::setInt(QString& arg)const
{
    QStringList myList = arg.split(' ');
    return myList[1].toInt();
}
ShapeType ShapeBuffer::setShape(QString& string3)const
{    if (string3.contains("Polyline"))
    return POLYLINE;
else if (string3.contains("Line"))
    return LINE;
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
    else if(x.contains("DashDotDotLine"))
        return Qt::DashDotDotLine;
    else if(x.contains("DashDotLine"))
        return Qt::DashDotLine;
    else if(x.contains("DotLine"))
        return Qt::DotLine;
    else if(x.contains("DashLine"))
        return Qt::DashLine;
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

Qt::AlignmentFlag ShapeBuffer::setTextAlignment(QString & x) const
{
    if(x.contains("AlignLeft"))
        return Qt::AlignLeft;
    else if(x.contains("AlignRight"))
        return Qt::AlignRight;
    else if(x.contains("AlignTop"))
        return Qt::AlignTop;
    else if(x.contains("AlignBottom"))
        return Qt::AlignBottom;
    else if(x.contains("AlignCenter"))
        return Qt::AlignCenter;
    else
        throw MyException();

}

QFont::Style ShapeBuffer::setTextFontStyle(QString & x) const
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

QFont::Weight ShapeBuffer::setTextFontWeight(QString & x) const
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

void ShapeBuffer::setLineDimensions\
(QString & x, QPoint& one, QPoint& two)
{
    x.remove(',');
    QStringList myList = x.split(' ');
    one.setX(myList[1].toInt());
    one.setY(myList[2].toInt());
    two.setX(myList[3].toInt());
    two.setY(myList[4].toInt());
}

QPolygon ShapeBuffer::setPolygonDimensions(QString & x) const
{
    x.remove(',');
    QStringList myList = x.split(' ');
    QPolygon temp;
    for (int i=1; i<myList.size(); i += 2)
        temp << QPoint(myList[i].toInt(),myList[i+1].toInt());
    return temp;
}

QRect ShapeBuffer::setQRect(QString & x) const
{
    x.remove(',');
    QStringList myList = x.split(' ');
    QRect temp(myList[1].toInt(),myList[2].toInt(),\
            myList[3].toInt(),myList[4].toInt());
    //constructor variables
    //(int x, int y, int width, int height)
    return temp;


}

QRect ShapeBuffer::setEllipseOrSquare(QString & x) const
{
    x.remove(',');
    QStringList myList = x.split(' ');
    QRect temp(myList[1].toInt(),myList[2].toInt(),\
            myList[3].toInt(),myList[3].toInt());
    //constructor variables
    //(int x, int y, int width, int height)
    return temp;
}

QString ShapeBuffer::setQStringText(QString & x) const
{
    QStringList myList = x.split(':');
    QString temp = myList[1];
    return temp.trimmed();
}
