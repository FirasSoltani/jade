#ifndef CHAUFFAGE_H
#define CHAUFFAGE_H


#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>


class Chauffage
{
public:
    Chauffage();
    Chauffage(QString,int,QString,QString);
    QString get_emplacement();
    int get_id();
    QString get_temperature();
    QString get_etat();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    void setTemperature(QString temp);
    void setEtat(QString etat);
    void setEmplacement(QString emp);
    QSqlQueryModel *recherche(int id);

private:
    QString emplacement,etat,temperature;
    int id;


};
#endif // CHAUFFAGE_H
