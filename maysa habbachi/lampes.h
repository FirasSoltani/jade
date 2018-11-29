#ifndef LAMPES_H
#define LAMPES_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>


class Lampes
{
public:
    Lampes();
    Lampes(QString,int,QString,QString);
    QString get_emplacement();
    int get_id();
    QString get_voltage();
    QString get_etat();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    void setEmplacement(QString emp);
    void setEtat(QString etat);
    void setVoltage(QString volt);
    QSqlQueryModel *recherche(int id);

private:
    QString emplacement,etat,voltage;
    int id;


};

#endif // LAMPES_H

