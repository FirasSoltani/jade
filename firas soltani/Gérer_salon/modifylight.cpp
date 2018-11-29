#include "modifylight.h"
#include "ui_modifylight.h"
#include "lights.h"
#include "mainwindow.h"

Modifylight::Modifylight(QWidget *parent,int index,int intensity,int etat,int desc) :
    QDialog(parent),
    ui(new Ui::Modifylight)
{
    ui->setupUi(this);
    this->index=index;
    this->ui->horizontalSlider->setValue(intensity);
    if(etat)
    {this->ui->radioButton->setChecked(1);}
    else
    {this->ui->radioButton_2->setChecked(1);
     this->ui->horizontalSlider->setDisabled(1);}
    if(desc!=0)
    {    ui->pushButton->setEnabled(0);}
}

Modifylight::~Modifylight()
{
    delete ui;
}

void Modifylight::on_pushButton_clicked()
{
      l.deletelight(this->index);
}

void Modifylight::on_horizontalSlider_valueChanged(int value)
{
    l.modifierintensity(value,this->index);
}



void Modifylight::on_radioButton_toggled(bool checked)
{
    l.modifieretat(1,this->index);
    this->ui->horizontalSlider->setDisabled(0);
}

void Modifylight::on_radioButton_2_toggled(bool checked)
{
    l.modifieretat(0,this->index);
    this->ui->horizontalSlider->setDisabled(1);
}
