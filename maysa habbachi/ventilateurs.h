#ifndef VENTILATEURS_H
#define VENTILATEURS_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>


class Ventilateurs
{
public:
    Ventilateurs();
    Ventilateurs(QString,int,QString,QString);
    QString get_emplacement();
    int get_id();
    QString get_intensite();
    QString get_etat();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    void setIntensite(QString inte);
    void setEtat(QString etat);
    void setEmplacement(QString emp);
    QSqlQueryModel *recherche(int id);

private:
    QString emplacement,etat,intensite;
    int id;


};
#endif // VENTILATEURS_H
