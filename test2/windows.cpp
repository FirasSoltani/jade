#include "windows.h"

windows::windows()
{

}


bool windows::modifiernivr(int niveau,int id)
{
    QSqlQuery query;
    if(niveau<=100&&niveau>=0)
    {
     QString q=QString::number(niveau);
     query.prepare("update windows set niveaur=:niveau where indexf=:index");
     query.bindValue(":niveau", q);
     query.bindValue(":index",id);


      return (query.exec());
    }
    return false;

}

bool windows::modifiernivf(int niveau,int id)
{
    QSqlQuery query;
    if(niveau<=100&&niveau>=0)
    {
        if(niveau==0)
        {this->modifieretat(0,id);}
        else
            this->modifieretat(1,id);
     QString q=QString::number(niveau);
     query.prepare("update windows set niveauf=:niveau where indexf=:index");
     query.bindValue(":niveau", q);
     query.bindValue(":index",id);


      return (query.exec());
    }
    return false;

}


bool windows::modifieretat(int etat,int index)
{
    QSqlQuery query;
    if(etat==1||etat==0)
    {
     QString q=QString::number(etat);
     query.prepare("update windows set etat=:etat where indexf=:index");
     query.bindValue(":etat", q);
     query.bindValue(":index", index);

      query.exec();
      return true;
    }
    else
        return false;

}

bool windows::deletewindow(int index)
{
    QSqlQuery query;
    query.prepare("Select indexf from windows where indexf=:index");
    query.bindValue(":index",index);
            query.exec();
            if(query.next())
            {
                query.prepare("Delete from windows where indexf=:index");
                query.bindValue(":index",index);
                return(query.exec());


            }
            else
                return false;

}

bool windows::addwindows(int id,QString cb)
{
    QSqlQuery query;
    QString q=QString::number(id);

    query.prepare("Select indexf from windows where indexf=:index");
    query.bindValue(":index",q);
            query.exec();

            if(!query.next())
            {

                query.prepare("Insert into windows (indexf,id_ch) values(:index,:chamber)");
                query.bindValue(":index",q);
                query.bindValue(":chamber",cb);
                return(query.exec());



            }
            else
                return false;

}


QSqlQueryModel* windows::displaywindows()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT indexf,etat,niveauf,niveaur,id_ch FROM windows");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Index"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Etat"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Niveau Fenetre"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Niveau Rideau"));
    Model->setHeaderData(4,Qt::Horizontal,QObject::tr("Chamber"));
    return Model;
}
