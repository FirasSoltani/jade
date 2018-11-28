#include "voiture.h"
#include "ui_voiture.h"
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>
Voiture::Voiture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Voiture)
{
    ui->setupUi(this);
}
// CONSTRUCTEURS

Voiture::~Voiture()
{
    delete ui;
}
Voiture::Voiture()
{
this->indexv=0;
}

//GETTERS

int Voiture::get_indexv()
{return indexv;}


// AJOUT
bool Voiture::ajouter_voit()
{
    QSqlQuery query;
 QString res= QString::number(indexv);
    query.prepare("INSERT INTO VOITURE (INDEXV) "
                        "VALUES (:indexv)");
    query.bindValue(":indexv", res);
    return  query.exec();
}

// AFFICHER
void Voiture::on_pb_ajouter_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/done.mp3")) ;
    music->play();
    indexv=ui->lineEdit_id->text().toInt();
    if(ajouter_voit() )
    {

        QMessageBox::information(nullptr, QObject::tr("Ajouter une Voiture"),
                          QObject::tr("Voiture ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


    }
}



// SUPPRIMER

bool Voiture::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Voiture where INDEXV= :indexv ");
query.bindValue(":indexv", res);
return    query.exec();
}

void Voiture::on_pb_supprimer_clicked()
{
    indexv=ui->lineEdit_id_2->text().toInt();
   if(supprimer(indexv))
   {
   QMessageBox::information(nullptr, QObject::tr("Supprimer une voiture"),
               QObject::tr("Voiture supprimée.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

    }
}
void Voiture::afficher(QTableView *tab)
   {
       QSqlQueryModel *model =new QSqlQueryModel();
       QSqlQuery *query = new QSqlQuery();

      query->prepare("SELECT * FROM VOITURE");
       query->exec();
       model->setQuery(*query);
       tab->setSelectionBehavior(QAbstractItemView::SelectRows);
       tab->setModel(model);
   }



void Voiture::on_pushButton_clicked()
{
    QItemSelectionModel *select=ui->tabvoit->selectionModel();
    afficher(ui->tabvoit);
}

void Voiture::rechercher()
{
    indexv=ui->lineEditR->text().toInt();
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
    query->prepare("Select * from VOITURE where INDEXV=:id ");
    query->bindValue(":id",indexv);
    query->exec();
    model->setQuery(*query);
    ui->tabvoit->setModel(model);
    qDebug()<<(model->rowCount());
    if (model->rowCount()==0)
        QMessageBox::information(nullptr, QObject::tr("Rechercher une voiture "),
                    QObject::tr(" La voiture n'est plus dans le garage .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


      else
        QMessageBox::information(nullptr, QObject::tr("Rechercher une voiture "),
                    QObject::tr(" La voiture est dans le garage .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
void Voiture::on_pushButton_2_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/flash.mp3")) ;
    music->play();

   rechercher();
}
