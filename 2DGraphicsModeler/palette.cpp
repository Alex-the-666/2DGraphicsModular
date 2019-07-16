#include "palette.h"
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

}

//Polyline
void Palette::on_pushButton_2_clicked()
{

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
