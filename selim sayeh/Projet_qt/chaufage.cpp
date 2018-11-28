#include "chaufage.h"
#include "ui_chaufage.h"
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>
Chaufage::Chaufage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chaufage)
{
    ui->setupUi(this);
}
//CONSTRUCTEURS


Chaufage::~Chaufage()
{
    delete ui;
}
Chaufage::Chaufage()
{
    this->idc=0;
    this->tempc=23;
}


//GETTERS

int Chaufage::get_temp()
{return tempc;}

int Chaufage::get_id()
{return idc;}


// AJOUT CHAUFAGE
bool Chaufage::ajouter_temp()
{
    QSqlQuery query;
 QString res= QString::number(idc);
    query.prepare("INSERT INTO CHAUFAGE (IDC,TEMPC) "
                        "VALUES (:idc, :tempc)");
    query.bindValue(":idc", res);
    query.bindValue(":tempc", tempc);
    return  query.exec();
}
void Chaufage::afficher(QTableView *tab)
   {
       QSqlQueryModel *model =new QSqlQueryModel();
       QSqlQuery *query = new QSqlQuery();

      query->prepare("SELECT * FROM CHAUFAGE");
       query->exec();
       model->setQuery(*query);
       tab->setSelectionBehavior(QAbstractItemView::SelectRows);
       tab->setModel(model);
   }
bool Chaufage::modifier(int IDC,int temp)
{
     QSqlQuery *ql=new QSqlQuery();
     ql->prepare("UPDATE Chaufage SET TEMPC=? WHERE IDC=? ");
     ql->addBindValue(temp);
     ql->addBindValue(IDC);
     return (ql->exec());
}

void Chaufage::on_pushButton_clicked()
{

    QItemSelectionModel *select=ui->tabchaufage->selectionModel();
    afficher(ui->tabchaufage);

}


void Chaufage::on_dial_sliderReleased()
{
    tempc=ui->lcdNumber->value();


}
void Chaufage::on_pb_ajouter_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/done.mp3")) ;
    music->play();
    idc=ui->lineEdit_id->text().toInt();
    on_dial_sliderReleased();
    if(ajouter_temp() )
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Chaufage"),
                          QObject::tr("Chaufage ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }

}


// MODIFIER LCD
void Chaufage::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}

void Chaufage::on_dial_2_valueChanged(int value)
{
    ui->lcdNumber_2->display(value);
}
//MODIFIER BD

void Chaufage::on_dial_2_sliderReleased()
{
    tempc=ui->lcdNumber->value();

}

// SUPRESSION
bool Chaufage::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CHAUFAGE where IDC= :idc ");
query.bindValue(":idc", res);
return    query.exec();
}

void Chaufage::on_pb_supprimer_clicked()
{
    idc=ui->lineEdit_id_2->text().toInt();
   if(supprimer(idc))
   {
   QMessageBox::information(nullptr, QObject::tr("Supprimer un Chaufage"),
            QObject::tr("Chaufage supprimé.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void Chaufage::on_pb_supprimer_2_clicked()
{
    int temp , id;
    id=ui->lineEdit_id_3->text().toInt();
    temp=ui->lcdNumber_2->value();

    if(modifier(id,temp)==true)
        QMessageBox::information(nullptr, QObject::tr("Modifier un chaufage"),
                    QObject::tr(" Chaufage modifié .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
QSqlQueryModel* Chaufage::stats()
{

    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

   query->prepare("SELECT ((SELECT SUM(TEMPC) FROM CHAUFAGE )/(SELECT COUNT(*)FROM CHAUFAGE )) FROM CHAUFAGE");
    query->exec();
    model->setQuery(*query);

    return model;
}

void Chaufage::on_pushButton_2_clicked()
{

ui->tableView->setModel(this->stats());


}
