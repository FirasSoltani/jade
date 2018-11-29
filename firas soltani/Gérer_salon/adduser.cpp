#include "adduser.h"
#include "ui_adduser.h"

adduser::adduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adduser)
{
    ui->setupUi(this);
}

adduser::~adduser()
{
    U.nb*=-1;
    delete ui;
}

void adduser::on_buttonBox_accepted()
{
U.adduser(ui->Useradd_id->text(),ui->Useradd_mdp->text(),ui->combo_des->currentText());
}


