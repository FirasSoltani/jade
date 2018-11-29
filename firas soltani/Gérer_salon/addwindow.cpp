#include "addwindow.h"
#include "ui_addwindow.h"

addwindow::addwindow(QWidget *parent,QTableView * hi) :
    QDialog(parent),
    ui(new Ui::addwindow)
{


    ui->setupUi(this);
    ui->id_ch->setModel(ch.afficher());
    this->hi=hi;
}

addwindow::~addwindow()
{
    hi->setModel(wi.displaywindows());
    delete ui;


}

void addwindow::on_buttonBox_accepted()
{
    wi.addwindows(ui->idwindowadd->text().toInt(),ui->id_ch->currentText());
}
