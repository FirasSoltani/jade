#ifndef FENETRE_H
#define FENETRE_H
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Fenetre
{
public:
    Fenetre();
    Fenetre(int,int);
    int get_id();
    int get_niveau();
    bool Ajouter_fenetre();
    QSqlQueryModel * Afficher_fenetre();
    bool Modifier_fenetre(int);
    bool Supprimer_fenetre(int);
private:
    int id;
    int niveau;
};

#endif // FENETRE_H
