//#include "shapeinfo.h"
//#include "shape.h"
#include "mainwindow.h"
//#include "ui_shapeinfo.h"

#include "shapeinfo.h"
#include "ui_shapeinfo.h"

ShapeInfo::ShapeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapeInfo)
{
    ui->setupUi(this);
        setWindowTitle(tr("Shape Info"));
}

ShapeInfo::~ShapeInfo()
{
    delete ui;
}

////Line
//void ShapeInfo::on_pushButton_clicked()
//{

//}

////Polyline
//void ShapeInfo::on_pushButton_2_clicked()
//{

//}

////Polygon
//void ShapeInfo::on_pushButton_3_clicked()
//{

//}
////Rectangle
//void ShapeInfo::on_pushButton_4_clicked()
//{

//}
////Elipse
//void ShapeInfo::on_pushButton_5_clicked()
//{

//}
////Text
//void ShapeInfo::on_pushButton_6_clicked()
//{


void ShapeInfo::updateBackground(){
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
 //   w->renderArea->setStyleSheet(QString("background:rgb(%1,%2,%3);").arg(backgroundR).arg(backgroundG).arg(backgroundB));
}
