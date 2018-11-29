#ifndef LAMPES_H
#define LAMPES_H
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Lampes
{
public:
    Lampes();
    Lampes(int,QString,int);
    int get_id();
    QString get_couleur();
    int get_luminosite();
    bool Ajouter_lampe();
    QSqlQueryModel * Afficher_lampe();
    bool Modifier_lampe(int);
    bool Supprimer_lampe(int);
private:
    int id;
    QString couleur;
    int luminosite;
};

#endif // LAMPES_H
