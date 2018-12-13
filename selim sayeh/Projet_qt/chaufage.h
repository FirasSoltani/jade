#ifndef CHAUFAGE_H
#define CHAUFAGE_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QTableWidget>
#include "qcustomplot.h"

namespace Ui {
class Chaufage;
}

class Chaufage : public QDialog
{
    Q_OBJECT

public:
    explicit Chaufage(QWidget *parent = nullptr);
    ~Chaufage();
Chaufage();
int get_temp();
int get_id();
bool ajouter_temp();
bool supprimer(int);
void afficher(QTableView *tab);
bool modifier(int IDC,int temp);
QVector<double> stat_ticks();
void tri_stat_nom(QVector<double>& t1);
void makeplot(QCustomPlot *customPlot) ;
QSqlQueryModel * stats();
private slots:


void on_dial_sliderReleased();

void on_dial_valueChanged(int value);

void on_dial_2_valueChanged(int value);

void on_dial_2_sliderReleased();

void on_pb_ajouter_clicked();

void on_pb_supprimer_clicked();



void on_pushButton_clicked();

void on_pb_supprimer_2_clicked();

void on_pushButton_2_clicked();

private:
    Ui::Chaufage *ui;
    int tempc;
    int idc;
};

#endif // CHAUFAGE_H

