#include "lampes.h"
#include <QDebug>
Lampes::Lampes()
{
    id=0;
    emplacement="";
    etat="";
    voltage="";

}
Lampes::Lampes(QString emp,int idd,QString volt,QString et)
{
    this->id=idd;
    this->emplacement=emp;
    this->etat=et;
    this->voltage=volt;
}

QString Lampes::get_emplacement(){return  emplacement;}
QString Lampes::get_etat(){return etat;}
int Lampes::get_id(){return  id;}
QString Lampes::get_voltage(){return  voltage;}
void Lampes::setVoltage(QString volt){voltage=volt;}
void Lampes::setEtat(QString et){etat=et;}
void Lampes::setEmplacement(QString emp){emplacement=emp;}
bool Lampes::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO lampes (ID, EMPLACEMENT,ETAT,VOLTAGE) "
                    "VALUES (:id, :emplacement, :etat, :voltage)");
query.bindValue(":id", res);
query.bindValue(":emplacement", emplacement);
query.bindValue(":etat", etat);
query.bindValue(":voltage", voltage);

return    query.exec();
}

QSqlQueryModel * Lampes::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from lampes");
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("emplacement "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("voltage"));
    return model;
}

bool Lampes::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from LAMPES where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Lampes::modifier(int id)
{
    QSqlQuery Q;
    QString res= QString::number(id);
    Q.prepare("UPDATE  lampes set EMPLACEMENT=:emplacement,ETAT=:etat,Voltage=:Voltage where ID=:ID");
    Q.bindValue(":ID", res);
    Q.bindValue(":emplacement", emplacement);
    Q.bindValue(":etat", etat);
    Q.bindValue(":Voltage", voltage);


    return    Q.exec();


}
QSqlQueryModel * Lampes::recherche(int id)
{
    QString res= QString::number(id);
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from LAMPES where (ID LIKE '"+res+"%' ) ");
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Emplacement "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("VOLTAGE"));

    return model;
}



