#ifndef SHAPEINFO_H
#define SHAPEINFO_H
#include <QDialog>
#include <QTreeWidget>
#include <QString>


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

};
#endif // SHAPEINFO_H
