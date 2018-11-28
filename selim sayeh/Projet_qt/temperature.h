#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QDialog>
#include "chaufage.h"
#include "ventilateur.h"
namespace Ui {
class Temperature;
}

class Temperature : public QDialog
{
    Q_OBJECT

public:
    explicit Temperature(QWidget *parent = nullptr);
    ~Temperature();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Temperature *ui;
    Chaufage *C;
    Ventilateur *V;
};

#endif // TEMPERATURE_H
