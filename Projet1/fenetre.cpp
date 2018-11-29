#include "fenetre.h"
#include <QDebug>
Fenetre::Fenetre()
{
    id=0;
    niveau=0;
}

Fenetre::Fenetre(int id,int niveau)
{
    this->id=id;
    this->niveau=niveau;
}

int Fenetre::get_id()
{
    return id;
}

int Fenetre::get_niveau()
{
    return niveau;
}

bool Fenetre::Ajouter_fenetre()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString rez=QString::number(niveau);
    query.prepare("INSERT INTO FENETRE (ID, NIVEAU) "
                        "VALUES (:id, :niveau)");
    query.bindValue(":id", res);
    query.bindValue(":niveau", rez);

    return    query.exec();
}

QSqlQueryModel * Fenetre::Afficher_fenetre()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from FENETRE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NIVEAU "));
    return model;
}

bool Fenetre::Modifier_fenetre(int id)
{
    QSqlQuery query;
    query.prepare(  "UPDATE FENETRE SET NIVEAU= :niveau where id= :id ");
    query.bindValue(":id", id);
    query.bindValue(":niveau", niveau);
    return   query.exec();
}

bool Fenetre::Supprimer_fenetre(int id)
{
    QSqlQuery query,q;
    int tmp=-1;
    bool success=false;
    q.prepare("SELECT ID from FENETRE where ID= :id");
    q.bindValue(":id",id);
    q.exec();
    while(q.next())
        tmp=q.value(0).toInt();
    if(tmp==id)
    {
    query.prepare("Delete from FENETRE where ID = :id ");
    query.bindValue(":id", id);
    success=query.exec();
    }
    return    success;
}
