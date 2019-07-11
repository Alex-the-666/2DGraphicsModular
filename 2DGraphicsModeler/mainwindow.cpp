#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>

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

void MainWindow::on_actionLogin_triggered()
{
    admin = new adminLogin(this);
    admin -> show();
}

void MainWindow::on_TestAddShape_released()
{
    renderArea->arthurTest=true;
    renderArea->update();
}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath=QFileDialog::getOpenFileName(this, "save.txt");
    QDir d = QFileInfo(filePath).absoluteDir();
    QString absolute=d.absolutePath();
    //todo implement load all shapes from QFileInfo
}

void MainWindow::on_actionSave_triggered()
{
    QString path = QFileDialog::getSaveFileName(nullptr, tr("Save"), ".txt");
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    //todo write entire shape vector to QFile
    file.write("testing");
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
