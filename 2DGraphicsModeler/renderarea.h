#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QObject>
#include <QWidget>
#include "shape.h"
#include "line.h"
#include "vector.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    void passBuffer(const ShapeBuffer& fromParent);
    custom::vector<Shape*> getShapeVector();
    void tripFlag();//test function
protected:
    void addShape(const ShapeBuffer& buffer);
    void paintEvent(QPaintEvent *event) override;
    void testAddLines();
signals:

public slots:
private:
    ShapeBuffer buffer;
    custom::vector<Shape*> shapeVector;
    bool add = false;
    int offset=0;

};

#endif // RENDERAREA_H
