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

private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
