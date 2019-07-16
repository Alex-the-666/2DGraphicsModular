#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QTextStream>
#include <iostream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderArea = new RenderArea(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionOpen_triggered()
{
    QString path=QFileDialog::getOpenFileName(this, "save.txt");
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream instream(&file);
        renderArea->createShapeBuffer(instream);
    }
    file.close();

}

void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(nullptr, tr("Save"), ".txt");
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    /*
    custom::vector<Shape*> shapeVector = renderArea->getShapeVector();
    std::stringstream ss;
    for(Shape* shape : shapeVector){
        shape->write(ss);
        ss << std::endl;
    }
    std::string str = ss.str();
    file.write(str.c_str());*/
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_TestAddShape_released()
{
    //renderArea->testValue=(!renderArea->testValue);
    renderArea->update();

}
