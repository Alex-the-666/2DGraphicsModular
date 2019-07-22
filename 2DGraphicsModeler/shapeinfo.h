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
    enum SortType{ID,AREA,PERIM};
    explicit ShapeInfo(QWidget *parent = nullptr);
    explicit ShapeInfo(QWidget *parent = nullptr, SortType = ID);

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
