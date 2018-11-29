#include "chauffage.h"
#include <QDebug>
Chauffage::Chauffage()
{
    id=0;
    emplacement="";
    etat="";
    temperature="";
}


Chauffage::Chauffage(QString emp,int idd,QString temp,QString et)
{
    this->id=idd;
    this->emplacement=emp;
    this->etat=et;
    this->temperature=temp;
}

QString Chauffage::get_emplacement(){return  emplacement;}
QString Chauffage::get_etat(){return etat;}
int Chauffage::get_id(){return  id;}
QString Chauffage::get_temperature(){return  temperature;}

void Chauffage::setTemperature(QString temp){temperature=temp;}
void Chauffage::setEtat(QString et){etat=et;}
void Chauffage::setEmplacement(QString emp){emplacement=emp;}

bool Chauffage::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Chauffage (ID, EMPLACEMENT,ETAT,temperature) "
                    "VALUES (:id, :emplacement, :etat, :temperature)");
query.bindValue(":id", res);
query.bindValue(":emplacement", emplacement);
query.bindValue(":etat", etat);
query.bindValue(":temperature", temperature);

return    query.exec();
}

QSqlQueryModel * Chauffage::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Chauffage");
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("emplacement "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("temperature"));
    return model;
}

bool Chauffage::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Chauffage where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Chauffage::modifier(int id)
{
    QSqlQuery Q;
    QString res= QString::number(id);
    Q.prepare("UPDATE  chauffage set EMPLACEMENT=:emplacement,ETAT=:etat,Temperature=:Temperature where ID=:ID");
    Q.bindValue(":ID", res);
    Q.bindValue(":emplacement", emplacement);
    Q.bindValue(":etat", etat);
    Q.bindValue(":Temperature", temperature);


    return    Q.exec();


}
QSqlQueryModel *Chauffage::recherche(int id)
{
    QString res= QString::number(id);
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from CHAUFFAGE where (ID LIKE '"+res+"%' ) ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Emplacement "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("temperature"));

    return model;
}


