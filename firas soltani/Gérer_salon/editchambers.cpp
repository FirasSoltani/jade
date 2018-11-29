#include "editchambers.h"
#include "ui_editchambers.h"

editchambers::editchambers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editchambers)
{
    ui->setupUi(this);
    ui->tableView->setModel(ch.afficher());
}

editchambers::~editchambers()
{
    delete ui;
}
