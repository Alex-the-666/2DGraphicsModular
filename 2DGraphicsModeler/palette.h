#ifndef PALETTE_H
#define PALETTE_H

#include <QWidget>

namespace Ui {
class Palette;
}

class Palette : public QWidget
{
    Q_OBJECT

public:
    explicit Palette(QWidget *parent = nullptr);
    ~Palette();

private slots:
    void on_horizontalSlider_sliderMoved(int position);
    void on_horizontalSlider_2_sliderMoved(int position);
    void on_horizontalSlider_3_sliderMoved(int position);
    void on_plainTextEdit_textChanged();
    void on_plainTextEdit_2_textChanged();
    void on_textEdit_3_textChanged();
private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
