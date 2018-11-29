#ifndef NOTI_H
#define NOTI_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>



class noti
{
private:
int id;
public:
    noti();
    void Alerte_Ajout(int id, int i);
    void Alerte_Modifier(int id, int i);
    void Alerte_Supprimer(int id, int i);
    void Alerte_Ajout2(int id, int i);
    void Alerte_Modifier2(int id, int i);
    void Alerte_Supprimer2(int id, int i);
    void Alerte_Ajout3(int id, int i);
    void Alerte_Modifier3(int id, int i);
    void Alerte_Supprimer3(int id, int i);




};

#endif // NOTI_H
