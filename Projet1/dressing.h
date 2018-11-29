#ifndef DRESSING_H
#define DRESSING_H
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class dressing
{
public:
    dressing();
    dressing(int,QString,QString);
    int get_id();
    QString get_couleur();
    QString get_categorie();
    bool Ajouter_dressing();
    QSqlQueryModel * Afficher_dressing();
    bool Modifier_dressing(int);
    bool Supprimer_dressing(int);
    QSqlQueryModel * tri_dressing();
private:
    int id;
    QString couleur;
    QString categorie;
};

#endif // DRESSING_H
