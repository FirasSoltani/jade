#ifndef MODIFYLIGHT_H
#define MODIFYLIGHT_H

#include <QDialog>
#include "lights.h"

namespace Ui {
class Modifylight;
}

class Modifylight : public QDialog
{
    Q_OBJECT

public:
    Modifylight(QWidget *parent,int,int,int);
    //Modifylight(QWidget *parent = nullptr,int);
    ~Modifylight();
    int index;
    int intensity;
    Lights l;
private slots:
    void on_pushButton_clicked();


    void on_horizontalSlider_valueChanged(int value);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

private:
    Ui::Modifylight *ui;
};

#endif // MODIFYLIGHT_H
