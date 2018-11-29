#include "lights.h"

Lights::Lights()
{

}

Lights::Lights(int index,int etat,int intensity)
{
    this->indexl=index;
    this->etat=etat;
    this->intensity=intensity;

}
void Lights::setindex(int index)
{

    this->indexl=index;
}

bool Lights::modifierintensity(int intensity,int id)
{
    QSqlQuery query;
    if(intensity<=100&&intensity>=0)
    {
    this->intensity=intensity;
     QString q=QString::number(intensity);
     query.prepare("update lights set intensity=:intensity where indexl=:index");
     query.bindValue(":intensity", q);
     query.bindValue(":index",id);


      return (query.exec());
    }
    return false;

}

bool Lights::modifieretat(int etat,int index)
{
    QSqlQuery query;
    if(etat==1||etat==0)
    {
     QString q=QString::number(etat);
     query.prepare("update lights set etat=:etat where indexl=:index");
     query.bindValue(":etat", q);
     query.bindValue(":index", index);

      query.exec();
      return true;
    }
    else
        return false;

}

bool Lights::deletelight(int index)
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

bool Lights::addlight(int id,QString cb)
{
    QSqlQuery query;
    QString q=QString::number(id);

    query.prepare("Select indexl from lights where indexl=:index");
    query.bindValue(":index",q);
            query.exec();

            if(!query.next())
            {

                query.prepare("Insert into lights (indexl,ch_id) values(:index,:chamber)");
                query.bindValue(":index",q);
                query.bindValue(":chamber",cb);
                return(query.exec());



            }
            else
                return false;

}


QSqlQueryModel* Lights::displaylights()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT indexl,etat,intensity,ch_id FROM lights");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Index"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Intensity"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Chamber"));
    return Model;
}

