#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QObject>
#include <QWidget>
#include "shape.h"
#include "line.h"
#include "polyline.h"
#include "vector.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    void addShape(Shape* rhs);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:
private:
    custom::vector<Shape*> shapeVector;
};

#endif // RENDERAREA_H
