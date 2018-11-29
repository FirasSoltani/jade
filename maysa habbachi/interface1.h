#ifndef INTERFACE1_H
#define INTERFACE1_H

#include <QDialog>
#include <QSound>
#include <QMainWindow>


#include "lampes.h"

#include "chauffage.h"
#include "ventilateurs.h"
namespace Ui {
class interface1;
}

class interface1 : public QDialog
{
    Q_OBJECT

public:
    explicit interface1(QWidget *parent = nullptr);
    ~interface1();

private slots:


    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);


    void on_Button_ajout_clicked();

    void on_Button_ajout2_clicked();

    void on_Button_ajout3_clicked();

    void on_Button_modifier_clicked();

    void on_Button_modifier2_clicked();

    void on_Button_modifier3_clicked();

    void on_Button_supprimer_clicked();

    void on_Button_supprimer2_clicked();

    void on_Button_supprimer3_clicked();

    void on_pbrefresh_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::interface1 *ui;
    QSound *son;
    QSound *son1;
    QSound *son2;


    Lampes tmpLampes;
    Chauffage tmpchauffage ;
    Ventilateurs tmpventilateurs ;
};

#endif // INTERFACE1_H
