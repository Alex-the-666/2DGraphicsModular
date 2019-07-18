//#include "shapeinfo.h"
//#include "shape.h"
#include "mainwindow.h"
//#include "ui_shapeinfo.h"
#include "shape.h"
#include "shapeinfo.h"
#include "ui_shapeinfo.h"

ShapeInfo::ShapeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapeInfo)
{
    ui->setupUi(this);
        setWindowTitle(tr("Shape Info"));

        // Set the number of columns in the tree
         ui->treeWidget->setColumnCount(2);

         // Add root nodes
         addTreeRoot("Line", "");
         addTreeRoot("Polyline", "");
         addTreeRoot("Rectangle", "");
         addTreeRoot("Square", "");
         addTreeRoot("Ellipse", "");
         addTreeRoot("Circle", "");
         addTreeRoot("Polygon", "");
}

ShapeInfo::~ShapeInfo()
{
    delete ui;
}


void ShapeInfo::addTreeRoot(QString name, QString description)
{
    QString temp;
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
    ShapeBuffer buffer;

    Line* shape = new Line(buffer);

    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);
   // temp=shape->getPen();
    addTreeChild(treeItem,  "ShapeId", " ");
    addTreeChild(treeItem,  "PenColor", " ");
    addTreeChild(treeItem,  "PenWidth", " ");
    addTreeChild(treeItem,  "PenStyle", " ");
    addTreeChild(treeItem,  "PenCapStyle", " ");
    addTreeChild(treeItem,  "PenJoinStyle", " ");
}

void ShapeInfo::addTreeChild(QTreeWidgetItem *parent,
                  QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);
}
