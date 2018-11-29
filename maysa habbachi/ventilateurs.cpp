#include "ventilateurs.h"
#include <QDebug>

Ventilateurs::Ventilateurs()
{
    id=0;
    emplacement="";
    etat="";
    intensite="";
}

Ventilateurs::Ventilateurs(QString emp,int idd,QString inte,QString et)
{
    this->id=idd;
    this->emplacement=emp;
    this->etat=et;
    this->intensite=inte;
}

QString Ventilateurs::get_emplacement(){return  emplacement;}
QString Ventilateurs::get_etat(){return etat;}
int Ventilateurs::get_id(){return  id;}
QString Ventilateurs::get_intensite(){return  intensite;}

void Ventilateurs::setIntensite(QString inte){intensite=inte;}
void Ventilateurs::setEtat(QString et){etat=et;}
void Ventilateurs::setEmplacement(QString emp){emplacement=emp;}

bool Ventilateurs::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Ventilateurs (ID, EMPLACEMENT,ETAT,INTENSITE) "
                    "VALUES (:id, :emplacement, :etat, :intensite)");
query.bindValue(":id", res);
query.bindValue(":emplacement", emplacement);
query.bindValue(":etat", etat);
query.bindValue(":intensite", intensite);

return    query.exec();
}

QSqlQueryModel * Ventilateurs::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Ventilateurs");
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("emplacement "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("intensite"));
    return model;
}

bool Ventilateurs::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Ventilateurs where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Ventilateurs::modifier(int id)
{
    QSqlQuery Q;
    QString res= QString::number(id);
    Q.prepare("UPDATE  ventilateurs set EMPLACEMENT=:emplacement,ETAT=:etat,Intensite=:intensite where ID=:ID");
    Q.bindValue(":ID", res);
    Q.bindValue(":emplacement", emplacement);
    Q.bindValue(":etat", etat);
    Q.bindValue(":intensite", intensite);


    return    Q.exec();


}

QSqlQueryModel * Ventilateurs::recherche(int id)
{
    QString res= QString::number(id);
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from VENTILATEURS where (ID LIKE '"+res+"%' ) ");
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Emplacement "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("intensite"));

    return model;
}


