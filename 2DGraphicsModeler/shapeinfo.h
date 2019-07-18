#ifndef SHAPEINFO_H
#define SHAPEINFO_H
#include <QDialog>


namespace Ui {
class ShapeInfo;
}

class ShapeInfo: public QDialog
{
    Q_OBJECT

public:
    explicit ShapeInfo(QWidget *parent = nullptr);
    ~ShapeInfo();

private slots:
//    //Line
//    void on_pushButton_clicked();
//    //Polyline
//    void on_pushButton_2_clicked();
//    //Polygon
//    void on_pushButton_3_clicked();
//    //Rectangle
//    void on_pushButton_4_clicked();
//    //Elipse
//    void on_pushButton_5_clicked();
//    //Text
//    void on_pushButton_6_clicked();

private:
    Ui::ShapeInfo *ui;

    void updateBackground();
};
#endif // SHAPEINFO_H
