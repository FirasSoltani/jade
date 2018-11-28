#include "connexion.h"
#include <QDebug>
Connexion::Connexion()
{

}
bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_qt");
db.setUserName("sihou");//inserer nom de l'utilisateur
db.setPassword("sihou");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
