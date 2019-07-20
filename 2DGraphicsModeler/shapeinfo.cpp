//#include "shapeinfo.h"
//#include "shape.h"
#include "mainwindow.h"
//#include "ui_shapeinfo.h"
#include "shape.h"
#include "shapeinfo.h"
#include "shapebuffer.h"
#include "ui_shapeinfo.h"
#include "vector.h"

ShapeInfo::ShapeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapeInfo)
{

    ui->setupUi(this);
    setWindowTitle(tr("Shape Info"));
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
    custom::vector<Shape*>& shp = w->renderArea ->getShapeVector();

//    for(auto i = shp.begin(); i <shp.end(); i++)
//    {
//        if(w -> readOut)
//        {

//        }
//    }
    //        // Set the number of columns in the tree
    ui->treeWidget->setColumnCount(1);
    //this->ui->
    //  ui->treeWidget->editItem(item, column);

    //         // Add root nodes
    addTreeRoot("ID 1", "");
    addTreeRoot("ID 2", "");
    addTreeRoot("ID 3", "");
    addTreeRoot("ID 4", "");
    addTreeRoot("ID 5", "");
    addTreeRoot("ID 6", "");
    addTreeRoot("ID 7", "");
}

//void ShapeInfo::onTreeWidgetItemDoubleClicked(QTreeWidgetItem * item, int column)
//{

//      // ui.treeWidget->editItem(item, column);

//}

ShapeInfo::~ShapeInfo()
{
    delete ui;
}


void ShapeInfo::addTreeRoot(QString name, QString description)
{
    QString temp;

    ShapeBuffer buffer;

    Shape* shape = new Line(buffer);

    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);
   //temp=shape->getPen();
    addTreeChild(treeItem,  "PenStyle", "");
     addTreeChild(treeItem,  "PenColor" ,  ""); // shape->getPenColor()); //shape->getPenColor());
     addTreeChild(treeItem,  "PenWidth"," "); // shape->getPenStyle());
    addTreeChild(treeItem,  "ShapeId", " "); //shape->getPenStyle());
    addTreeChild(treeItem,  "PenCapStyle", " "); //shape->getPenCapStyle());
    addTreeChild(treeItem,  "PenJoinStyle", " "); //shape->getPenJoint());

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

//void ShapeBuffer::readOut(QTextStream & os)
//{
//    os << "ShapeId: " << getShapeID() << endl;
//    os << "ShapeType: " << printShapeType() << endl;
//    os << "ShapeDimensions: " << printShapeDimensions() << endl;
//    switch(shape)
//    {
//    case LINE:
//    case POLYLINE: os<< printPen() << endl; break;
//    case POLYGON:
//    case RECTANGLE:
//    case SQUARE:
//    case ELLIPSE:
//    case CIRCLE: os<< printPen() << endl << printBrush(); break;
//    case TEXT:
//    {
//        os << "TextString: " << qStringText <<endl;
//        os << "TextColor: " << printGobalColor(pen.color()) << endl;
//        os << "TextAlignment: " << printAlign() << endl;
//        os << printFont() << endl;
//    }break;
//    }
//}
