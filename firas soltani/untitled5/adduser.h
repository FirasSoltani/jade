#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include "useredit.h"
#include "mainwindow.h"
#include "user.h"
namespace Ui {
class adduser;
}

class adduser : public QDialog
{
    Q_OBJECT

public:
    explicit adduser(QWidget *parent = nullptr);
    ~adduser();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::adduser *ui;
    User U;
};

#endif // ADDUSER_H
