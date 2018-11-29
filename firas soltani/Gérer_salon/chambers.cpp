#include "chambers.h"

chambers::chambers()
{

}
bool chambers::addchamber(QString id,QString desc)
{

    QSqlQuery query;

    query.prepare("Select id_ch from chambers where id_ch=:index");
    query.bindValue(":index",id);
            query.exec();

            if(!query.next())
            {

                query.prepare("Insert into chambers (id_ch,descri) values(:index,:chamber)");
                query.bindValue(":index",id);
                query.bindValue(":chamber",desc);
               return(query.exec());


            }
            else
                return false;
}

QSqlQueryModel * chambers::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("Select id_ch,descri from chambers");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Description"));

    return(model);



}

bool chambers::deletechamber(QString s)
{
    QSqlQuery query;

    query.prepare("delete from chambers where id_ch=(:id)");
    query.bindValue(":id",s);
    return(query.exec());


}


