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
    void tripFlag();
protected:
    void paintEvent(QPaintEvent *event) override;
    void testAddLines();
    void addShape(Shape* rhs);

signals:

public slots:
private:
    custom::vector<Shape*> shapeVector;
    bool add = false;
    int offset=0;

};

#endif // RENDERAREA_H
