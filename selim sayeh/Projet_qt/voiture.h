#ifndef VOITURE_H
#define VOITURE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QTableWidget>

namespace Ui {
class Voiture;
}

class Voiture : public QDialog
{
    Q_OBJECT
public:
    explicit Voiture(QWidget *parent = nullptr);
    ~Voiture();
    Voiture();
bool ajouter_voit();
int get_indexv();
bool supprimer(int idd);
void  afficher();
void afficher(QTableView *tab);
void rechercher();

private slots:
void on_pb_ajouter_clicked();

void on_pb_supprimer_clicked();

void on_pushButton_2_clicked();

void on_tabWidget_tabBarClicked(int index);

private:

Ui::Voiture *ui;
    int indexv;


};

#endif // VOITURE_H
