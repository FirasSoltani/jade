#include "addlights.h"
#include "ui_addlights.h"
#include "lights.h"
#include "QMessageBox"

Addlights::Addlights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addlights)
{
    ui->setupUi(this);
    ui->comboBox->setModel(ch.afficher());
}

Addlights::~Addlights()
{
    delete ui;
}

void Addlights::on_buttonBox_accepted()
{
    if(l.addlight(this->ui->lineEdit->text().toInt(),this->ui->comboBox->currentText()))
    {    QMessageBox::information(nullptr,"","Added");
         this->close();

    }
    else
        QMessageBox::information(nullptr,"","Exists");
}


