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

void MainWindow::pushBufferToRenderArea()
{

}

bool MainWindow::loadShapes()
{
    bool loaded = false;
    bool corrupt = false;
    while(loaded==false)//This is just a placeholder
        //It simiulates the flag until it finishes reading
        //it the file/buffer
    {
        ShapeBuffer parentBuffer;
        /*
         Code to read input into the buffer
         should have a way to trip
         corrupt flag in event
         of txt corruption.
         */
        renderArea->passBuffer(parentBuffer);
        if(corrupt == true)
            return false;
        loaded=true;
    }
return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLogin_triggered()
{
    admin = new adminLogin(this);
    admin -> show();
}

void MainWindow::on_TestAddShape_released()
{
    renderArea->tripFlag();
    renderArea->update();
}

void MainWindow::on_actionOpen_triggered()
{
    QString path=QFileDialog::getOpenFileName(this, "save.txt");
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream instream(&file);
        Shape* shape = nullptr;
        while(!instream.atEnd()){
            QString line = instream.readLine();
            if(line.contains("LINE")){
                if(shape != nullptr){
                    this->renderArea->getShapeVector().push_back(shape);
                }
                shape = new Line(this->renderArea);
            }
            if(shape != nullptr){
                //read in details from stream
            }
        }
    }

}

void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(nullptr, tr("Save"), ".txt");
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    custom::vector<Shape*> shapeVector = renderArea->getShapeVector();
    std::stringstream ss;
    for(Shape* shape : shapeVector){
        shape->write(ss);
        ss << std::endl;
    }
    std::string str = ss.str();
    file.write(str.c_str());
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
