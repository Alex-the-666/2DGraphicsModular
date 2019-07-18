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

    Shape* shape = new Line();
    dynamic_cast<Line*>(shape)->setPointOne(10, 10);
    dynamic_cast<Line*>(shape)->setPointOne(100, 100);
    w->renderArea->getShapeVector().push_back(shape);
    w->renderArea->update();
}

//Polyline
void Palette::on_pushButton_2_clicked()
{
    MainWindow* w = dynamic_cast<MainWindow*>(this->parentWidget());

    Shape* shape = new PolyLine();

    w->renderArea->getShapeVector().push_back(shape);
    w->renderArea->update();
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
}

//Background R
void Palette::on_horizontalSlider_actionTriggered(int action)
{
    backgroundR = action;
    updateBackground();
}

//Background G
void Palette::on_horizontalSlider_2_actionTriggered(int action)
{
    backgroundG = action;
    updateBackground();
}
//Background B
void Palette::on_horizontalSlider_3_actionTriggered(int action)
{
    backgroundB = action;
    updateBackground();
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
