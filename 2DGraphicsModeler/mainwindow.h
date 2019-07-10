#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"
#include "adminlogin.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLogin_triggered();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    adminLogin *admin;
};

#endif // MAINWINDOW_H
