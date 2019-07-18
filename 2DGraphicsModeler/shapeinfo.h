#ifndef SHAPEINFO_H
#define SHAPEINFO_H
#include <QDialog>
#include <QTreeWidget>
#include <QString>
#include <QPen>


namespace Ui {
class ShapeInfo;
}

class ShapeInfo: public QDialog
{
    Q_OBJECT

public:
    explicit ShapeInfo(QWidget *parent = nullptr);
    ~ShapeInfo();

private slots:
    void addTreeRoot(QString name, QString description);
    void addTreeChild(QTreeWidgetItem *parent,
                         QString name, QString description);

private:
    Ui::ShapeInfo *ui;
    QBrush brush;
    QPen pen;

};
#endif // SHAPEINFO_H
