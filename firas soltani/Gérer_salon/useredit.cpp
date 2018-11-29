#include "useredit.h"
#include "ui_useredit.h"

Useredit::Useredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Useredit)
{

    ui->setupUi(this);
    ui->tableView->setModel(U.displayusers());
}

Useredit::~Useredit()
{
    delete ui;
}



void Useredit::on_tableView_clicked(const QModelIndex &index)
{

    ui->lineEdit_pass->setEnabled(1);
    ui->lineEdit_pass->setText(ui->tableView->model()->data(this->ui->tableView->model()->index(index.row(),1)).toString());
    ui->lineEdit_des->setEnabled(1);
    ui->lineEdit_des->setText(ui->tableView->model()->data(this->ui->tableView->model()->index(index.row(),2)).toString());
    U.setid(ui->tableView->model()->data(this->ui->tableView->model()->index(index.row(),0)).toString());
    }




void Useredit::on_buttonBox_accepted()
{

    U.modifierpass(ui->lineEdit_pass->text(),U.getid());
    U.modifierdes(ui->lineEdit_des->text(),U.getid());
}

void Useredit::on_pushButton_clicked()
{
    adduser a;
    a.exec();
}

void Useredit::on_lineEdit_search_textChanged(const QString &arg1)
{
    ui->tableView->setModel(U.search(arg1));}
