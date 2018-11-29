#include "noti.h"
#include <QSystemTrayIcon>

noti::noti()
{

}

void noti::Alerte_Ajout(int id,int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==1)
       {

       notifyIcon->showMessage("Lampes","On peut pas ajouter une lampe ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==2)
       {
         notifyIcon->showMessage("Lampes","Une nouveau lampe avec un identifiant N°"+res+" a été ajouté",QSystemTrayIcon::Information,15000);
       }
}
void noti::Alerte_Modifier(int id, int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==4)
       {

       notifyIcon->showMessage("Lampes","On peut pas modifier une lampe ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==3)
       {
         notifyIcon->showMessage("Lampes","Une lampe avec un identifiant N°"+res+" a été modifié",QSystemTrayIcon::Information,15000);
       }
}
void noti::Alerte_Supprimer(int id, int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==6)
       {

       notifyIcon->showMessage("Lampes","On peut pas supprimer une lampe ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==5)
       {
         notifyIcon->showMessage("Lampes","Une lampe avec un identifiant N°"+res+" a été supprimé",QSystemTrayIcon::Information,15000);
       }
}
void noti::Alerte_Ajout2(int id,int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==1)
       {

       notifyIcon->showMessage("Chauffage","On peut pas ajouter un chauffage ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==2)
       {
         notifyIcon->showMessage("Chauffage","Un nouveau chauffage avec un identifiant N°"+res+" a été ajouté",QSystemTrayIcon::Information,15000);
       }
}

void noti::Alerte_Modifier2(int id, int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==4)
       {

       notifyIcon->showMessage("chauffage","On peut pas modifier un chauffage ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==3)
       {
         notifyIcon->showMessage("chauffage","Un chauffage avec un identifiant N°"+res+" a été modifié",QSystemTrayIcon::Information,15000);
       }
}
void noti::Alerte_Supprimer2(int id, int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==6)
       {

       notifyIcon->showMessage("chauffage","On peut pas supprimer un  chauffage ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==5)
       {
         notifyIcon->showMessage("chauffage","Un chauffage avec un identifiant N°"+res+" a été supprimé",QSystemTrayIcon::Information,15000);
       }
}
void noti::Alerte_Ajout3(int id,int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==1)
       {

       notifyIcon->showMessage("ventilateurs","On peut pas ajouter un ventilateur ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==2)
       {
         notifyIcon->showMessage("ventilateurs","Un nouveau ventilateur avec un identifiant N°"+res+" a été ajouté",QSystemTrayIcon::Information,15000);
       }
}

void noti::Alerte_Modifier3(int id, int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==4)
       {

       notifyIcon->showMessage("ventilateurs","On peut pas modifier un ventilateur ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==3)
       {
         notifyIcon->showMessage("ventilateurs","Un ventilateur avec un identifiant N°"+res+" a été modifié",QSystemTrayIcon::Information,15000);
       }
}
void noti::Alerte_Supprimer3(int id, int i)
{

    QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    //notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

       notifyIcon->show();

       if (i==6)
       {

       notifyIcon->showMessage("ventilateurs","On peut pas supprimer unventilateur ",QSystemTrayIcon::Warning,15000);
       }
       else if (i==5)
       {
         notifyIcon->showMessage("ventilateurs","Un ventilateurs avec un identifiant N°"+res+" a été supprimé",QSystemTrayIcon::Information,15000);
       }
}
