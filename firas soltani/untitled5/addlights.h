#ifndef ADDLIGHTS_H
#define ADDLIGHTS_H

#include <QDialog>
#include "lights.h"
#include "chambers.h"
namespace Ui {
class Addlights;
}

class Addlights : public QDialog
{
    Q_OBJECT

public:
    explicit Addlights(QWidget *parent = nullptr);
    ~Addlights();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Addlights *ui;
    Lights l;
    chambers ch;

};

#endif // ADDLIGHTS_H
