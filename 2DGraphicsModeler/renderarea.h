#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QObject>
#include <QWidget>
#include "line.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:
};

#endif // RENDERAREA_H
