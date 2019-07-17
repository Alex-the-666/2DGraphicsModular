#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "renderarea.h"

#include "contact.h"
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
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionQuit_triggered();

    void on_TestAddShape_released();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    ShapeBuffer buffer;
};

#endif // MAINWINDOW_H
