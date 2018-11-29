#ifndef USEREDIT_H
#define USEREDIT_H

#include <QDialog>
#include "user.h"
#include <QMessageBox>
#include "adduser.h"

namespace Ui {
class Useredit;
}

class Useredit : public QDialog
{
    Q_OBJECT

public:
    explicit Useredit(QWidget *parent = nullptr);
    ~Useredit();
    User U;
    QString id;

private slots:


    void on_tableView_clicked(const QModelIndex &index);


    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

private:
    Ui::Useredit *ui;
};

#endif // USEREDIT_H
