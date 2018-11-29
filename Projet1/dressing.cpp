#include "dressing.h"
#include <QDebug>
dressing::dressing()
{
    id=0;
    couleur="";
    categorie="";
}

dressing::dressing(int id,QString couleur,QString categorie)
{
    this->id=id;
    this->couleur=couleur;
    this->categorie=categorie;
}

int dressing::get_id()
{
    return id;
}

QString dressing::get_couleur()
{
    return couleur;
}


QString dressing::get_categorie()
{
    return categorie;
}

bool dressing::Ajouter_dressing()
{
    QSqlQuery query;
    query.prepare("INSERT INTO DRESSING(ID, COULEUR, CATEGORIE) VALUES(:id, :couleur, :categorie)");
    query.bindValue(":id", id);
    query.bindValue(":couleur", couleur);
    query.bindValue(":categorie",categorie);

    return    query.exec();
}

QSqlQueryModel * dressing::Afficher_dressing()
{
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from DRESSING");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("COULEUR "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    return model;
}

QSqlQueryModel * dressing::tri_dressing()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from DRESSING order by CATEGORIE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("COULEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
    return model;
}
bool dressing::Supprimer_dressing(int id)
{
    QSqlQuery query,q;
    int tmp=-1;
    bool success=false;
    q.prepare("SELECT ID from DRESSING where ID= :id");
    q.bindValue(":id",id);
    q.exec();
    while(q.next())
        tmp=q.value(0).toInt();
    if(tmp==id)
    {
    query.prepare("Delete from DRESSING where ID = :id ");
    query.bindValue(":id", id);
    success=query.exec();
    }
    return    success;
}
