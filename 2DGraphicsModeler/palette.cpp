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
    backgroundR = 0;
    backgroundG = 0;
    backgroundB = 0;
}

Palette::~Palette()
{
    delete ui;
}

//Line
void Palette::on_pushButton_clicked()
{
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
    ShapeBuffer buffer;
    Line* shape = new Line(buffer);
    shape->setPointOne(10, 10);
    shape->setPointOne(100, 100);
    w->renderArea->getShapeVector().push_back(shape);
    w->renderArea->repaint();
}

//Polyline
void Palette::on_pushButton_2_clicked()
{
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
    ShapeBuffer buffer;
    PolyLine* shape = new PolyLine(buffer);

    w->renderArea->getShapeVector().push_back(shape);
    w->renderArea->repaint();
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

void Palette::updateBackground(){
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());
    w->renderArea->setStyleSheet(QString("background:rgb(%1,%2,%3);").arg(backgroundR).arg(backgroundG).arg(backgroundB));
    ui->plainTextEdit->setPlainText(QString().setNum(backgroundR));
    ui->plainTextEdit_2->setPlainText(QString().setNum(backgroundG));
    ui->plainTextEdit_3->setPlainText(QString().setNum(backgroundB));
}

//Shape R
void Palette::on_horizontalSlider_6_actionTriggered(int action)
{
    shapeR = action;
}

//Shape G
void Palette::on_horizontalSlider_5_actionTriggered(int action)
{
    shapeG = action;
}

//Shape B
void Palette::on_horizontalSlider_4_actionTriggered(int action)
{
    shapeB = action;
}

//Background R
void Palette::on_horizontalSlider_valueChanged(int value)
{
    backgroundR = value;
    updateBackground();
}

//Background G
void Palette::on_horizontalSlider_2_valueChanged(int value)
{
    backgroundG = value;
    updateBackground();
}

//Background B
void Palette::on_horizontalSlider_3_valueChanged(int value)
{
    backgroundB = value;
    updateBackground();
}
