#include "ventilateur.h"
#include "ui_ventilateur.h"
#include <QMessageBox>
#include <QtDebug>
#include <QDebug>
#include <QMediaPlayer>
Ventilateur::Ventilateur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventilateur)
{
    ui->setupUi(this);
}

//CONSTRUCTEURS

Ventilateur::~Ventilateur()
{
    delete ui;
}
Ventilateur::Ventilateur()
{
    this->idv=0;
    this->tempv=23;
}

//GETTERS

int Ventilateur::get_temp()
{return tempv;}
int Ventilateur::get_idv()
{return idv;}


// AJOUT VENTILATEUR
bool Ventilateur::ajouter_temp()
{
    QSqlQuery query;
    QString res= QString::number(idv);
    query.prepare("INSERT INTO VENTILATEUR (IDV,TEMPV) "
                        "VALUES (:idv,:tempv)");
    query.bindValue(":idv", res);
    query.bindValue(":tempv", tempv);
    return  query.exec();
}

void Ventilateur::on_dial_sliderReleased()
{
    tempv=ui->lcdNumber->value();
}

void Ventilateur::on_pb_ajouter_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/done.mp3")) ;
    music->play();
    idv=ui->lineEdit_id->text().toInt();
    on_dial_sliderReleased();
    if(ajouter_temp() )
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Ventilateur"),
                          QObject::tr("Ventilateur ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        afficher(ui->tabv);
    }
}

// LCD + DIAL
void Ventilateur::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}

void Ventilateur::on_dial_2_valueChanged(int value)
{
    ui->lcdNumber_2->display(value);
}


//MODIFICATION DE LA BASE
void Ventilateur::on_dial_2_sliderReleased()
{
    tempv=ui->lcdNumber->value();

}

//SUPPRIMER

bool Ventilateur::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from VENTILATEUR where IDV= :idv ");
query.bindValue(":idv", res);
return    query.exec();
}

void Ventilateur::on_pb_supprimer_clicked()
{
    idv=ui->lineEdit_id_2->text().toInt();

    if(supprimer(idv) )
    {

        QMessageBox::information(nullptr, QObject::tr("Supprimer un Ventilateur"),
                    QObject::tr("Ventilateur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        afficher(ui->tabv);
    }
}
void Ventilateur::afficher(QTableView *tab)
   {
       QSqlQueryModel *model =new QSqlQueryModel();
       QSqlQuery *query = new QSqlQuery();

      query->prepare("SELECT * FROM VENTILATEUR");
       query->exec();
       model->setQuery(*query);
       tab->setSelectionBehavior(QAbstractItemView::SelectRows);
       tab->setModel(model);
   }




bool Ventilateur::modifier(int IDC,int temp)
{
     QSqlQuery *ql=new QSqlQuery();
     ql->prepare("UPDATE VENTILATEUR SET TEMPV=? WHERE IDV=? ");
     ql->addBindValue(temp);
     ql->addBindValue(IDC);
     return (ql->exec());
}


void Ventilateur::on_pb_modifier_clicked()
{
    int temp , id;
    id=ui->lineEdit_id_3->text().toInt();
    temp=ui->lcdNumber_2->value();

    if(modifier(id,temp)==true)
        QMessageBox::information(nullptr, QObject::tr("Modifier  un ventilateur "),
                    QObject::tr("ventilateur modifié .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    afficher(ui->tabv);


}
void Ventilateur::rechercher()
{
    idv=ui->lineEdit->text().toInt();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
    query->prepare("Select * from VENTILATEUR where IDV=:id ");
    query->bindValue(":id",idv);
    query->exec();
    model->setQuery(*query);
    ui->tabv->setModel(model);
    qDebug()<<(model->rowCount());
    if (model->rowCount()==0)
        QMessageBox::information(nullptr, QObject::tr("Rechercher un Ventilateur "),
                    QObject::tr(" Le ventilateur n'existe pas .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


      else
        QMessageBox::information(nullptr, QObject::tr("Rechercher un Ventilateur "),
                    QObject::tr(" Le ventilateur existe .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}




void Ventilateur::on_pushButton_2_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/flash.mp3")) ;
    music->play();

   rechercher();

}

void Ventilateur::on_tabWidget_tabBarClicked(int index)
{
    afficher(ui->tabv);
}
