#ifndef SHAPEINFO_H
#define SHAPEINFO_H
#include <QDialog>
#include <QTreeWidget>
#include <QString>
#include <QPen>

#include "shapebuffer.h"


namespace Ui {
class ShapeInfo;
}

class ShapeInfo: public QDialog, public ShapeBuffer
{
    Q_OBJECT

public:
    explicit ShapeInfo(QWidget *parent = nullptr);

    ~ShapeInfo();

private slots:
    QTreeWidgetItem* addTreeRoot(QString name);
    void addTreeChild(QTreeWidgetItem *parent, QString name);

private:
    Ui::ShapeInfo *ui;
    QBrush brush;
    QPen pen;
      QTreeWidgetItem *item;


};
#endif // SHAPEINFO_H
