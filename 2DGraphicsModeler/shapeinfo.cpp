#include "mainwindow.h"
#include "shape.h"
#include "shapeinfo.h"
#include "shapebuffer.h"
#include "ui_shapeinfo.h"
#include "vector.h"
#include <regex>

ShapeInfo::ShapeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapeInfo)
{
    ui->setupUi(this);
    setWindowTitle(tr("Shape Info"));
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
    custom::vector<Shape*>& shp = w->renderArea ->getShapeVector();
    QTreeWidgetItem *item = new QTreeWidgetItem;

    for(auto i = shp.begin(); i != shp.end(); i++)
    {
        ShapeBuffer temp;
        (*i)->setShapeBuffer(temp);
        item = addTreeRoot("ID #" + QString::number(temp.getShapeID()));
        addTreeChild(item, "Shape: " + static_cast<ShapeInfo*>(&temp) -> printShapeType());
        addTreeChild(item, "Dimensions: " + static_cast<ShapeInfo*>(&temp) -> printShapeDimensions());
        addTreeChild(item, "Area: " + QString::number((*i) -> area()));
        addTreeChild(item, "Perimeter: " + QString::number((*i) -> perimeter()));
        switch(static_cast<ShapeInfo*>(&temp) -> getShape())
        {
        case LINE:
        case POLYLINE: addTreeChild(item, static_cast<ShapeInfo*>(&temp) -> printPen()); break;
        case POLYGON:
        case RECTANGLE:
        case SQUARE:
        case ELLIPSE:
        case CIRCLE:
        {
            addTreeChild(item, static_cast<ShapeInfo*>(&temp) -> printPen());
            addTreeChild(item, static_cast<ShapeInfo*>(&temp) -> printBrush().trimmed());
        }
            break;
        case TEXT:
        {
           addTreeChild(item, "TextString: " + static_cast<ShapeInfo*>(&temp) -> getQStringText());
           addTreeChild(item, "TextColor: " + static_cast<ShapeInfo*>(&temp) -> printGobalColor(pen.color()));
           addTreeChild(item, "TextAlignment: " + static_cast<ShapeInfo*>(&temp) -> printAlign());
           addTreeChild(item, static_cast<ShapeInfo*>(&temp) -> printFont());
        }break;
        }

    }
    //ui->treeWidget->setColumnCount(1);
    //delete item;
    item = nullptr;
}

ShapeInfo::~ShapeInfo()
{
    delete ui;
}


QTreeWidgetItem* ShapeInfo::addTreeRoot(QString name)
{
    QString temp;
    ShapeBuffer buffer;
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0, name);
    return treeItem;
}

void ShapeInfo::addTreeChild(QTreeWidgetItem *parent,
                  QString name)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, name);
    parent->addChild(treeItem);
}
