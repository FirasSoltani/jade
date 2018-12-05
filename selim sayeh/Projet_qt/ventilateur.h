#ifndef VENTILATEUR_H
#define VENTILATEUR_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QTableWidget>


namespace Ui {
class Ventilateur;
}

class Ventilateur : public QDialog
{
    Q_OBJECT

public:
    explicit Ventilateur(QWidget *parent = nullptr);
    ~Ventilateur();
    Ventilateur();
    int get_temp();
    int get_idv();
    bool ajouter_temp();
    bool supprimer(int idd);
    void afficher(QTableView *tab);
    bool modifier(int IDC,int temp);

private slots:
    void on_dial_valueChanged(int value);

    void on_dial_2_valueChanged(int value);

    void on_dial_sliderReleased();

    void on_dial_2_sliderReleased();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pb_modifier_clicked();



private:
    Ui::Ventilateur *ui;
    int tempv;
    int idv;
};

#endif // VENTILATEUR_H
