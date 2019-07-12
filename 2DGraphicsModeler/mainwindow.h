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
    void pushBufferToRenderArea();
    bool loadShapes();
    ~MainWindow();

private slots:
    void on_actionLogin_triggered();
    void on_TestAddShape_released();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    adminLogin *admin;
    ShapeBuffer buffer;
};

#endif // MAINWINDOW_H
