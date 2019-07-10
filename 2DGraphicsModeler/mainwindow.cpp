#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QPixmap quitIcon("quit.png");
     QAction *quitAction = new QAction(quitIcon, "&Quit", this);
     QAction *saveAction = new QAction("&Save", this);
     QAction *openAction = new QAction("&Open", this);
     quitAction->setShortcut(Qt::CTRL + Qt::Key_Q);
     saveAction->setShortcut(Qt::CTRL + Qt::Key_S);
     openAction->setShortcut(Qt::CTRL + Qt::Key_O);
     QMenu *file = menuBar()->addMenu("File");
     file->addAction(quitAction);
     file->addAction(saveAction);
     file->addAction(openAction);
     connect(quitAction, &QAction::triggered, qApp, &QApplication::quit);
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


