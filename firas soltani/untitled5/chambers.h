#ifndef CHAMBERS_H
#define CHAMBERS_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class chambers
{
public:
    chambers();

    bool addchamber(QString,QString);
    QSqlQueryModel * afficher();
    bool deletechamber(QString);
};

#endif // CHAMBERS_H
