#include "palette.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);
}

Palette::~Palette()
{
    delete ui;
}

void Palette::on_horizontalSlider_sliderMoved(int position)
{

}

void Palette::on_horizontalSlider_2_sliderMoved(int position)
{

}

void Palette::on_horizontalSlider_3_sliderMoved(int position)
{

}

void Palette::on_plainTextEdit_textChanged()
{

}

void Palette::on_plainTextEdit_2_textChanged()
{

}

void Palette::on_textEdit_3_textChanged()
{

}
