#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "chambers.h"
#include "windows.h"
#include <QMessageBox>
#include <QTableView>

namespace Ui {
class addwindow;
}

class addwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addwindow(QWidget *parent ,QTableView *);
    ~addwindow();
    chambers ch;
    windows wi;
    QTableView *hi;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addwindow *ui;
};

#endif // ADDWINDOW_H
