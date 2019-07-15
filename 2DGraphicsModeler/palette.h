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

private:
    Ui::Palette *ui;
};

#endif // PALETTE_H
