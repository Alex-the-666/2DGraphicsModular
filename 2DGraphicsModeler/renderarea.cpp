#include "renderarea.h"
#include <QStyleOption>
#include <QMouseEvent>

const QSize minSize(1000,500);

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(minSize);
    setBackgroundRole(QPalette::Base);
    move(120, 36);
    setStyleSheet("background-color:white;");
    setUpdatesEnabled(true);
    setMouseTracking(true);
}

void RenderArea::mouseMoveEvent(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    for (auto it = shapeVector.begin(); it != shapeVector.end(); it++){
        (*it)->move(x, y);
    }
    repaint();
}

void RenderArea::createShapeBuffer(QTextStream& is)
{
   buffer.resize(0);
    while(!is.atEnd())
    {
        ShapeBuffer x;
        x.readIn(is);
        if(!is.atEnd())
            buffer.push_back(x);

        is.readLine();//get rid of the space
        is.flush();
    }
   shapeBufferReady=true;
}

custom::vector<Shape*>& RenderArea::getShapeVector(){
    return shapeVector;
}

void RenderArea::transferToShapes()
{
   for(auto sbIt = buffer.begin();\
       sbIt != buffer.end(); sbIt++)
   {
       ShapeType shapeType = sbIt->getShape();
       switch(shapeType)
       {
       case LINE: shapeVector.push_back(new Line(*sbIt));
           break;
       case POLYLINE: shapeVector.push_back(new PolyLine(*sbIt));
           break;
       case POLYGON: shapeVector.push_back(new Polygon(*sbIt));
           break;
       case RECTANGLE: shapeVector.push_back(new Rectangle(*sbIt));
           break;
       case SQUARE: shapeVector.push_back(new Square(*sbIt));
           break;
       case ELLIPSE: shapeVector.push_back(new Ellipse(*sbIt));
           break;
       case CIRCLE:shapeVector.push_back(new Circle(*sbIt));
           break;
       case TEXT: shapeVector.push_back(new Text(*sbIt));
           break;
       }//end of switch

   }// end of for loop

}

void RenderArea::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
     QPainter painter(this);
    if(shapeBufferReady == true)
    {
          transferToShapes();
          shapeBufferReady=false;
    }
        for (auto it = shapeVector.begin(); it != shapeVector.end(); it++)
        {
            (*it)->passQPainter(&painter);
            (*it)->draw();
        }

}

void RenderArea::readOut(QTextStream& textStream)
{
    int count;
    count = 0;
    for (auto it = buffer.begin(); it != buffer.end(); it++)
    {
        ++count;
        textStream << "ShapeId: " << (*it).getShapeID() << endl
                   << "ShapeType: ";
        if (it->getShape() == 0)
        {
            textStream << "Line";
        }
        else if (it->getShape() == 1)
        {
            textStream << "Polyline";
        }
        else if (it->getShape() == 2)
        {
            textStream << "Polygon";
        }
        else if (it->getShape() == 3)
        {
            textStream << "Rectangle";
        }
        else if (it->getShape() == 4)
        {
            textStream << "Square";
        }
        else if (it->getShape() == 5)
        {
            textStream << "Ellipse";
        }
        else if (it->getShape() == 6)
        {
            textStream << "Circle";
        }
        else if (it->getShape() == 7)
        {
            textStream << "Text";
        }
        else
        {
            textStream << "Line";
        }
        textStream << endl;
        textStream << "ShapeDimensions: ";
        switch (it->getShape())
        {
            case LINE: textStream << it->getQPointOne().rx() << ", "
                                  << it->getQPointOne().ry() << ", "
                                  << it->getQPointTwo().rx() << ", "
                                  << it->getQPointTwo().ry();
                       break;

            case POLYLINE:  for (int i = 0; i < it->getQPolygon().size(); i++)
                            {
                                textStream << it->getQPolygon().point(i).rx() << ", "
                                           << it->getQPolygon().point(i).ry();
                                if (i != it->getQPolygon().size())
                                {
                                    textStream << ", ";
                                }

                            }
                            break;
            case POLYGON: for (int i = 0; i < it->getQPolygon().size(); i++)
                          {
                              textStream << it->getQPolygon().point(i).rx() << ", "
                                         << it->getQPolygon().point(i).ry();
                              if (i != it->getQPolygon().size())
                              {
                                  textStream << ", ";
                              }

                          }
                          break;
            case RECTANGLE: textStream << it->getQRect().x() << ", "
                                       << it->getQRect().y() << ", "
                                       << it->getQRect().width() << ", "
                                       << it->getQRect().height();
                            break;
            case SQUARE: textStream << it->getQRect().x() << ", "
                                    << it->getQRect().y() << ", "
                                    << it->getQRect().height();
                         break;
            case CIRCLE: textStream << it->getQRect().x() << ", "
                                    << it->getQRect().y() << ", "
                                    << it->getQRect().width();
                         break;
            case ELLIPSE: textStream << it->getQRect().x() << ", "
                                     << it->getQRect().y() << ", "
                                     << it->getQRect().width() << ", "
                                     << it ->getQRect().height();
                           break;
            case TEXT: textStream << it->getQRect().x() << ", "
                                  << it->getQRect().y() << ", "
                                  << it->getQRect().height() << ", "
                                  << it->getQRect().width();

        }
        if (it->getShape() != TEXT)
        {
            textStream << endl;
            textStream << "PenColor: ";
            if (it->getPen().color() == Qt::white)
            {
               textStream << "white";
            }
            else if (it->getPen().color() == Qt::black)
            {
                textStream << "black";
            }
            else if (it->getPen().color() == Qt::red)
            {
                textStream << "red";
            }
            else if (it->getPen().color() == Qt::green)
            {
                textStream << "green";
            }
            else if (it->getPen().color() == Qt::blue)
            {
                textStream << "blue";
            }
            else if (it->getPen().color() == Qt::cyan)
            {
                textStream << "cyan";
            }
            else if (it->getPen().color() == Qt::magenta)
            {
                textStream << "magenta";
            }
            else if (it->getPen().color() == Qt::yellow)
            {
                textStream << "yellow";
            }
            else if (it->getPen().color() == Qt::gray)
            {
                textStream << "gray";
            }
            else
            {
                textStream << "black";
            }
            textStream << endl;
            textStream << "PenWidth: " << it->getPen().width() << endl;
            textStream << "PenStyle: ";
            if (it->getPen().style() == Qt::NoPen)
            {
                textStream << "NoPen";
            }
            else if (it->getPen().style() == Qt::SolidLine)
            {
                textStream << "SolidLine";
            }
            else if (it->getPen().style() == Qt::DashDotDotLine)
            {
                textStream << "DashDotDotLine";
            }
            else if (it->getPen().style() == Qt::DashDotLine)
            {
                textStream << "DashDotLine";
            }
            else if (it->getPen().style() == Qt::DotLine)
            {
                textStream << "DotLine";
            }
            else if (it->getPen().style() == Qt::DashLine)
            {
                textStream << "SolidLine";
            }
            else
            {
                textStream  << "NoPen";
            }
            textStream << endl;
            textStream << "PenCapStyle: ";
            if (it->getPen().capStyle() == Qt::FlatCap)
            {
                textStream << "FlatCap";
            }
            else if (it->getPen().capStyle() == Qt::SquareCap)
            {
                textStream << "SquareCap";
            }
            else if (it->getPen().capStyle() == Qt::RoundCap)
            {
                textStream << "RoundCap";
            }
            else
            {
                textStream << "Flatcap";
            }
            textStream << endl;
            textStream << "PenJoinStyle: ";
            if (it->getPen().joinStyle() == Qt::MiterJoin)
            {
                textStream << "MiterJoin";
            }
            else if (it->getPen().joinStyle() == Qt::BevelJoin)
            {
                textStream << "BevelJoin";
            }
            else if (it->getPen().joinStyle() == Qt::RoundJoin)
            {
                textStream << "RoundJoin";
            }
            else
            {
                textStream << "MiterJoin";
            }
            if (it->getShape() != LINE && it->getShape() != POLYLINE)
            {
                textStream << endl;
                textStream << "BrushColor: ";
                if (it->getBrush().color() == Qt::white)
                {
                   textStream << "white";
                }
                else if (it->getBrush().color() == Qt::black)
                {
                    textStream << "black";
                }
                else if (it->getBrush().color() == Qt::red)
                {
                    textStream << "red";
                }
                else if (it->getBrush().color() == Qt::green)
                {
                    textStream << "green";
                }
                else if (it->getBrush().color() == Qt::blue)
                {
                    textStream << "blue";
                }
                else if (it->getBrush().color() == Qt::cyan)
                {
                    textStream << "cyan";
                }
                else if (it->getBrush().color() == Qt::magenta)
                {
                    textStream << "magenta";
                }
                else if (it->getBrush().color() == Qt::yellow)
                {
                    textStream << "yellow";
                }
                else if (it->getBrush().color() == Qt::gray)
                {
                    textStream << "gray";
                }
                else
                {
                    textStream << "black";
                }
                textStream << endl;
                textStream << "BrushStyle: ";
                if (it->getBrush().style() == Qt::SolidPattern)
                {
                    textStream << "SolidPattern";
                }
                else if (it->getBrush().style() == Qt::HorPattern)
                {
                    textStream << "HorPattern";
                }
                else if (it->getBrush().style() == Qt::VerPattern)
                {
                    textStream << "VerPattern";
                }
                else if (it->getBrush().style() == Qt::NoBrush)
                {
                    textStream << "NoBrush";
                }
                else
                {
                    textStream << "NoBrush";
                }
            }
        }
        else
        {
            textStream << endl;
            textStream << "TextString: " << it->getQStringText() << endl;
            textStream << "TextColor: ";
            if (it->getPen().color() == Qt::white)
            {
               textStream << "white";
            }
            else if (it->getPen().color() == Qt::black)
            {
                textStream << "black";
            }
            else if (it->getPen().color() == Qt::red)
            {
                textStream << "red";
            }
            else if (it->getPen().color() == Qt::green)
            {
                textStream << "green";
            }
            else if (it->getPen().color() == Qt::blue)
            {
                textStream << "blue";
            }
            else if (it->getPen().color() == Qt::cyan)
            {
                textStream << "cyan";
            }
            else if (it->getPen().color() == Qt::magenta)
            {
                textStream << "magenta";
            }
            else if (it->getPen().color() == Qt::yellow)
            {
                textStream << "yellow";
            }
            else if (it->getPen().color() == Qt::gray)
            {
                textStream << "gray";
            }
            else
            {
                textStream << "black";
            }
            textStream << endl;
            textStream << "TextAlignment: ";
            if (it->getAlignFlag() == Qt::AlignLeft)
            {
                textStream << "AlignLeft";
            }
            else if (it->getAlignFlag() == Qt::AlignRight)
            {
                textStream << "AlignRight";
            }
            else if (it->getAlignFlag() == Qt::AlignTop)
            {
                textStream << "AlignTop";
            }
            else if (it->getAlignFlag() == Qt::AlignBottom)
            {
                textStream << "AlignBottom";
            }
            else if (it->getAlignFlag() == Qt::AlignCenter)
            {
                textStream << "AlignCenter";
            }
            else
            {
                textStream << "AlignLeft";
            }
            textStream << endl;
            textStream << "TextPointSize: " << it->getQFont().pointSize() << endl;
            textStream << "TextFontFamily: " << it->getQFont().family() << endl;
            textStream << "TextFontStyle: " << it->getQFont().styleName() << endl;
            textStream << "TextFontWeight: ";
            if (it->getQFont().weight() == QFont::Thin)
            {
                textStream << "Thin";
            }
            else if (it->getQFont().weight() == QFont::Normal)
            {
                textStream << "Normal";
            }
            else if (it->getQFont().weight() == QFont::Bold)
            {
                textStream << "Bold";
            }
            else
            {
                textStream << "Normal";
            }

        }
        if (count < buffer.size())
        {
            textStream << endl << endl;
        }
    }
}

