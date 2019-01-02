#include "lights.h"
#include <QSqlQuery>
#include <QSql>
#include <QtSql/QSqlDatabase>
#include <QSqlQueryModel>

#include <QSortFilterProxyModel>
lights::lights()
{

}


void lights::modifier(int pos,int etat)
{
    QSqlQuery query;
    if(etat==1||etat==0)
    {
     QString q=QString::number(etat);
     query.prepare("update lights set etat=:etat where pos=:pos");
     query.bindValue(":etat",q);
     query.bindValue(":pos",pos);


      query.exec();

     }
}


QSortFilterProxyModel* lights::displaylights()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT indexl,etat,intensity,ch_id,pos FROM lights");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Index"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Intensity"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Chamber"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Position"));
    //Model->query().exec();
    QSortFilterProxyModel *proxyModel=new QSortFilterProxyModel();
    proxyModel->setSourceModel(Model);
    proxyModel->sort(4,Qt::AscendingOrder);
    return proxyModel;
}


bool lights::deletelight(int index)
{
    QSqlQuery query;
    query.prepare("Select indexl from lights where indexl=:index");
    query.bindValue(":index",index);
            query.exec();
            if(query.next())
            {
                query.prepare("Delete from lights where indexl=:index");
                query.bindValue(":index",index);
                query.exec();
                return true;


            }
            else
                return false;

}


bool lights::addlight(int id,QString cb,int i)
{
    QSqlQuery query;
    QString q=QString::number(id);

    query.prepare("Select indexl from lights where indexl=:index");
    query.bindValue(":index",q);
            query.exec();

            if(!query.next())
            {

                query.prepare("Insert into lights (indexl,ch_id,pos) values(seq_person.nextval,:chamber,:pos)");
                query.bindValue(":index",q);
                query.bindValue(":chamber",cb);
                query.bindValue(":pos",i);
                return(query.exec());



            }
            else
                return false;
}


bool lights::findlight(int pos)
{



    QSqlQuery query;
    //QString q=QString::number(indx);
    query.prepare("Select indexl from lights where pos=:pos");
    //query.bindValue(":index",q);
    query.bindValue(":pos",pos);
            query.exec();
            if(query.next())
            {return true;}
                        else
                            {return false;}

}



bool lights::modifierintensity(int intensity,int pos)
{
    QSqlQuery query;
    if(intensity<=100&&intensity>=0)
    {
     QString q=QString::number(intensity);
     query.prepare("update lights set intensity=:intensity where pos=:pos");
     query.bindValue(":intensity", q);
     query.bindValue(":pos",pos);


      return (query.exec());
    }
    return false;

}
