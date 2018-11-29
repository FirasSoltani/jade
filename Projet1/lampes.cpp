#include "lampes.h"
#include <QDebug>

Lampes::Lampes()
{
    id=0;
    couleur="";
    luminosite=0;
}

Lampes::Lampes(int id,QString couleur,int luminosite)
{
    this->id=id;
    this->couleur=couleur;
    this->luminosite=luminosite;
}

int Lampes::get_id()
{
    return id;
}

QString Lampes::get_couleur()
{
    return couleur;
}

int Lampes::get_luminosite()
{
    return luminosite;
}

bool Lampes::Ajouter_lampe()
{
    QSqlQuery query;
    query.prepare("INSERT INTO LAMPES(ID, COULEUR, LUMINOSITE) VALUES(:id, :couleur, :luminosite)");
    query.bindValue(":id", id);
    query.bindValue(":couleur", couleur);
    query.bindValue(":luminosite",luminosite);

    return    query.exec();
}

QSqlQueryModel * Lampes::Afficher_lampe()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from LAMPES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("COULEUR "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("LUMINOSITE"));
    return model;
}

bool Lampes::Modifier_lampe(int id)
{
    QSqlQuery query;
   // QSqlQuery queryy;
    //query.prepare(  "UPDATE LAMPES SET COULEUR=:couleur where ID=:id ");
    query.prepare(  "UPDATE LAMPES SET COULEUR=:couleur, LUMINOSITE=:luminosite where ID=:id ");
  //  queryy.prepare("UPDATE LAMPES SET LUMINOSITE= :luminosite where id= :id");
    query.bindValue(":id", id);
    query.bindValue(":couleur", couleur);
    query.bindValue("luminosite", luminosite);
    //queryy.exec();
    return   query.exec();
}

bool Lampes::Supprimer_lampe(int id)
{
    QSqlQuery query,q;
    int tmp=-1;
    bool success=false;
    q.prepare("SELECT ID from LAMPES where ID= :id");
    q.bindValue(":id",id);
    q.exec();
    while(q.next())
        tmp=q.value(0).toInt();
    if(tmp==id)
    {
    query.prepare("Delete from LAMPES where ID = :id ");
    query.bindValue(":id", id);
    success=query.exec();
    }
    return    success;
}
