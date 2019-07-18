#ifndef PALETTE_H
#define PALETTE_H
#include <QDialog>

namespace Ui {
class Palette;
}

class Palette : public QDialog
{
    Q_OBJECT

public:
    explicit Palette(QWidget *parent = nullptr);
    ~Palette();

private slots:
    //Line
    void on_pushButton_clicked();
    //Polyline
    void on_pushButton_2_clicked();
    //Polygon
    void on_pushButton_3_clicked();
    //Rectangle
    void on_pushButton_4_clicked();
    //Elipse
    void on_pushButton_5_clicked();
    //Text
    void on_pushButton_6_clicked();
    //Shape R
    void on_horizontalSlider_6_actionTriggered(int action);
    //Shape G
    void on_horizontalSlider_5_actionTriggered(int action);
    //Shape B
    void on_horizontalSlider_4_actionTriggered(int action);
    //Background R
    void on_horizontalSlider_valueChanged(int value);
    //Background G
    void on_horizontalSlider_2_valueChanged(int value);
    //Background B
    void on_horizontalSlider_3_valueChanged(int value);

private:
    Ui::Palette *ui;
    int backgroundR;
    int backgroundG;
    int backgroundB;
    int shapeR;
    int shapeG;
    int shapeB;
    void updateBackground();
};

#endif // PALETTE_H
