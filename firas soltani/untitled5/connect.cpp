#include "connect.h"
#include "QSqlDatabase"
connect::connect()
{

}


bool connect::connectsql()
{
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source");
    db.setUserName("system");
    db.setPassword("Najetnader1");
    if(db.open())
    {
             return true;

    }
    else
    {


            return false;    }

}
