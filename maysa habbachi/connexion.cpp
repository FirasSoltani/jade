#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source");
db.setUserName("maysa");//inserer nom de l'utilisateur
db.setPassword("123456789");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
