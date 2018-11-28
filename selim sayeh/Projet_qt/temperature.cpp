#include "temperature.h"
#include "ui_temperature.h"

Temperature::Temperature(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temperature)
{
    ui->setupUi(this);
    QPixmap pix3("C:/Users/selim/Desktop/selim sayeh/Projet_qt/images/ventilateur.png");
    ui->label1->setPixmap(pix3);
    QPixmap pix4("C:/Users/selim/Desktop/selim sayeh/Projet_qt/images/chaufage.png");
    ui->label_2->setPixmap(pix4);

}

Temperature::~Temperature()
{
    delete ui;
}

void Temperature::on_pushButton_clicked()
{
    C= new Chaufage(this);
  C->show();
}

void Temperature::on_pushButton_2_clicked()
{
    V= new Ventilateur(this);
  V->show();
}
