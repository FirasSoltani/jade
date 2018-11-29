#include "user.h"

User::User()
{

}


QString User::getid()
{

   return(this->id);
}

void User::setid(QString id)
{

    this->id=id;
}


void User::setindex(QModelIndex *index)
{
 this->index=index;

}
 bool User::adduser(QString id,QString mdp,QString des)
 {


     QSqlQuery query;
     /*QString id=QString::number(U.getid());
     QString mdp=U.getmdp();
     QString des=U.getdes();*/

     query.prepare("Select id from users where id=:index");
     query.bindValue(":index",id);
             query.exec();

             if(!query.next())
             {
                 query.prepare("Insert into Users (id,mdp,des) values(:index,:mdp,:des)");
                 query.bindValue(":index",id);
                 query.bindValue(":mdp",mdp);
                 query.bindValue(":des",des);
                 return (query.exec());


             }
             return false;



 }

 bool User::modifierpass(QString pass,QString id)
 {
     QSqlQuery query;
      query.prepare("update users set mdp= :mdp where id= :index");
      query.bindValue(":mdp", pass);
      query.bindValue(":index",id);


       return (query.exec());
     }

QString User::verification(QString id,QString mdp)
 {

     QSqlQuery query;
     query.prepare("Select des from users where ((id=:id)and(mdp=:mdp))");
     query.bindValue(":id",id);
     query.bindValue(":mdp",mdp);
     query.exec();
     if(query.next())
        {if((query.value(0).toString().toUpper())=="ADMIN")
         return query.value(0).toString();
             else
               return "1";}
                else
                    return "";

 }


QSqlQueryModel* User::displayusers()
{
    QSqlQueryModel* Model=new QSqlQueryModel;
    Model->setQuery("SELECT id,mdp,des FROM users");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("Mot de passe"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Designation"));
    return Model;
}



bool User::modifierdes(QString des,QString id)
{
    QSqlQuery query;
     query.prepare("update users set des=:des where id=:index");
     query.bindValue(":des", des);
     query.bindValue(":index",id);


      return (query.exec());
    }


QSqlQueryModel * User::search(QString s)
{
    QSqlQueryModel * q=new QSqlQueryModel();
    q->setQuery("select * from users where id like'%"+s+"%'");
    q->setHeaderData(0,Qt::Horizontal,QObject::tr("ID "));
    q->setHeaderData(1,Qt::Horizontal,QObject::tr("Pass "));
    q->setHeaderData(2,Qt::Horizontal,QObject::tr("Designation "));

        return q;
}
