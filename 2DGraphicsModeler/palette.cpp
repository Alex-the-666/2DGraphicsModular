#include "palette.h"
#include "shape.h"
#include "mainwindow.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);
    setWindowTitle(tr("Palette"));
}

Palette::~Palette()
{
    delete ui;
}

//Line
void Palette::on_pushButton_clicked()
{
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
    //Line* shape = new Line(w->renderArea, w->buffer);
   // shape->setDimension(0, 0, 100, 100);
   // w->renderArea->shapeVector.push_back(shape);
}

//Polyline
void Palette::on_pushButton_2_clicked()
{
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
   // PolyLine* shape = new PolyLine(w->renderArea, w->buffer);
    //shape->setPoints(int nPoints, int firstx, int firsty, ...)
    //shape->move(10,10); //,200,200,300,440,223,345);//shape->setDimension(0, 0, 100, 100);
   // w->renderArea->shapeVector.push_back(shape);
}

//Polygon
void Palette::on_pushButton_3_clicked()
{

}
//Rectangle
void Palette::on_pushButton_4_clicked()
{

}
//Elipse
void Palette::on_pushButton_5_clicked()
{

}
//Text
void Palette::on_pushButton_6_clicked()
{

}
