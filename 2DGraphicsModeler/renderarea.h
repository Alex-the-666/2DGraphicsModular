#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QObject>
#include <QWidget>
#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "square.h"
#include "vector.h"
#include "text.h"
#include "selection_sort.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    void createShapeBuffer(QTextStream&);
    bool testValue = true;
    custom::vector<Shape*>& getShapeVector();
    void readOut(QTextStream&);

protected:
    void transferToShapes();
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:
private:
    custom::vector<ShapeBuffer> buffer;
    custom::vector<Shape*> shapeVector;

    bool shapeBufferReady = false;
};

#endif // RENDERAREA_H
