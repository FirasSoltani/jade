#ifndef EDITCHAMBERS_H
#define EDITCHAMBERS_H

#include <QDialog>
#include <chambers.h>

namespace Ui {
class editchambers;
}

class editchambers : public QDialog
{
    Q_OBJECT

public:
    explicit editchambers(QWidget *parent = nullptr);
    ~editchambers();

private:
    Ui::editchambers *ui;
    chambers ch;
};

#endif // EDITCHAMBERS_H
