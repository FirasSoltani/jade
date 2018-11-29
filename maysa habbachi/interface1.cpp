#include "interface1.h"
#include "ui_interface1.h"
#include<QMessageBox>
#include "lampes.h"
#include "chauffage.h"
#include "ventilateurs.h"
#include <QSound>
#include <QIcon>
#include "noti.h"
#include<QPixmap>

interface1::interface1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interface1)
{
    ui->setupUi(this);
    ui->Button_ajout->setIcon(QIcon("C:/Users/loume/Desktop/qt/ajout.png"));
    ui->Button_supprimer->setIcon(QIcon("C:/Users/loume/Desktop/qt/supprimer.png"));
    ui->Button_modifier->setIcon(QIcon("C:/Users/loume/Desktop/qt/modifier.jpg"));
    ui->Button_ajout2->setIcon(QIcon("C:/Users/loume/Desktop/qt/ajout.png"));
    ui->Button_supprimer2->setIcon(QIcon("C:/Users/loume/Desktop/qt/supprimer.png"));
    ui->Button_modifier2->setIcon(QIcon("C:/Users/loume/Desktop/qt/modifier.jpg"));
    ui->Button_ajout3->setIcon(QIcon("C:/Users/loume/Desktop/qt/ajout.png"));
    ui->Button_supprimer3->setIcon(QIcon("C:/Users/loume/Desktop/qt/supprimer.png"));
    ui->Button_modifier3->setIcon(QIcon("C:/Users/loume/Desktop/qt/modifier.jpg"));
    son=new QSound("C:/Users/loume/Desktop/qt/Ajout.wav");
    son1=new QSound("C:/Users/loume/Desktop/qt/Modifier.wav");
    son2=new QSound("C:/Users/loume/Desktop/qt/supprimer.wav");


    ui->tabLampes->setModel(tmpLampes.afficher());
    ui->tabChauffage->setModel(tmpchauffage.afficher());
    ui->tabVentilateurs->setModel(tmpventilateurs.afficher());


}

interface1::~interface1()
{
    delete ui;
}
void interface1::on_lineEdit_textChanged(const QString &arg1)
{
    Lampes L;
    int id = ui->lineEdit->text().toInt();
    ui->tableView->setModel(L.recherche(id));
}

void interface1::on_lineEdit_3_textChanged(const QString &arg1)
{
    Ventilateurs V;
    int id = ui->lineEdit_3->text().toInt();
    ui->tableView_3->setModel(V.recherche(id));
}

void interface1::on_lineEdit_2_textChanged(const QString &arg1)
{
    Chauffage C;
    int id = ui->lineEdit_2->text().toInt();
    ui->tableView_2->setModel(C.recherche(id));
}



void interface1::on_Button_ajout_clicked()
{
    noti n;

    int id = ui->lineEdit_id->text().toInt();
    QString emplacement= ui->comboBox_emplacement->currentText();
    QString etat= ui->comboBox_etat->currentText();
    QString voltage = ui->comboBox_voltage->currentText();


  Lampes l(emplacement,id,voltage,etat);
  bool test=l.ajouter();
  if(test)
{ui->tabLampes->setModel(tmpLampes.afficher());//refresh
      son->play();
n.Alerte_Ajout(ui->lineEdit_id->text().toInt(),2);
QMessageBox::information(nullptr, QObject::tr("Ajouter une lampe"),
                  QObject::tr("Lampe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      n.Alerte_Ajout(ui->lineEdit_id->text().toInt(),1);
      /*QMessageBox::critical(nullptr, QObject::tr("Ajouter une lampe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/


}

void interface1::on_Button_ajout2_clicked()
{
    noti n ;
    int id = ui->lineEdit_4->text().toInt();
    QString emplacement= ui->comboBox_10->currentText();
    QString etat= ui->comboBox_12->currentText();
    QString temperature = ui->comboBox_11->currentText();


  Chauffage c(emplacement,id,temperature,etat);
  bool test=c.ajouter();
  if(test)
{ui->tabChauffage->setModel(tmpchauffage.afficher());//refresh
      son->play();
      n.Alerte_Ajout2(ui->lineEdit_4->text().toInt(),2);

QMessageBox::information(nullptr, QObject::tr("Ajouter un chauffage"),
                  QObject::tr("chauffage ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      n.Alerte_Ajout2(ui->lineEdit_4->text().toInt(),1);

      /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un chauffage"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/
}

void interface1::on_Button_ajout3_clicked()
{
    noti n ;
    int id = ui->lineEdit_id3->text().toInt();
    QString emplacement= ui->comboBox_16->currentText();
    QString etat= ui->comboBox_17->currentText();
    QString intensite= ui->comboBox_18->currentText();
 Ventilateurs v(emplacement,id,intensite,etat);
  bool test=v.ajouter();
  if(test)
{ui->tabVentilateurs->setModel(tmpventilateurs.afficher());//refresh
      son->play();
      n.Alerte_Ajout3(ui->lineEdit_id3->text().toInt(),2);

QMessageBox::information(nullptr, QObject::tr("Ajouter un ventilateur"),
                  QObject::tr("ventilateur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      n.Alerte_Ajout3(ui->lineEdit_id->text().toInt(),1);

      /*QMessageBox::critical(nullptr, QObject::tr("Ajouter un ventilateur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);*/

}

void interface1::on_Button_modifier_clicked()
{
    noti n ;
    Lampes L;
    int id=ui->lineEdit_id_2->text().toInt();
    QString emplacement=ui->comboBox_emplacement_2->currentText();
    L.setEmplacement(emplacement);
    QString etat=ui->comboBox_etat_2->currentText();
    L.setEtat(etat);
    QString voltage=ui->comboBox_voltage_2->currentText();
    L.setVoltage(voltage);

    bool test=L.modifier(id);
    if(test)
    {
        ui->tabLampes->setModel(tmpLampes.afficher());
        son1->play();
       n.Alerte_Modifier(ui->lineEdit_id_2->text().toInt(),3);
        QMessageBox::information(nullptr, QObject::tr("modifier une lampe"),
                    QObject::tr("lampe modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        n.Alerte_Ajout(ui->lineEdit_id_2->text().toInt(),4);
    {
        /*QMessageBox::critical(nullptr, QObject::tr("modifier une lampe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

    }
}

void interface1::on_Button_modifier2_clicked()
{
    noti n ;
    Chauffage C;
    int id=ui->lineEdit_12->text().toInt();
    QString emplacement=ui->comboBox_21->currentText();
    C.setEmplacement(emplacement);
    QString etat=ui->comboBox_20->currentText();
    C.setEtat(etat);
    QString temperature=ui->comboBox_19->currentText();
    C.setTemperature(temperature);

    bool test=C.modifier(id);
    if(test)
    {
        ui->tabChauffage->setModel(tmpchauffage.afficher());
        son1->play();
        n.Alerte_Modifier2(ui->lineEdit_12->text().toInt(),3);

        QMessageBox::information(nullptr, QObject::tr("modifier un chauffage"),
                    QObject::tr("chauffage modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        n.Alerte_Modifier2(ui->lineEdit_12->text().toInt(),4);

      /*  QMessageBox::critical(nullptr, QObject::tr("modifier un chauffage"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

    }


}

void interface1::on_Button_modifier3_clicked()
{
    noti n ;
    Ventilateurs V;
    int id=ui->lineEdit_id3_2->text().toInt();
    QString emplacement=ui->comboBox_22->currentText();
    V.setEmplacement(emplacement);
    QString etat=ui->comboBox_23->currentText();
    V.setEtat(etat);
    QString intensite=ui->comboBox_24->currentText();
    V.setIntensite(intensite);

    bool test=V.modifier(id);
    if(test)
    {
        ui->tabVentilateurs->setModel(tmpventilateurs.afficher());
        son1->play();
        n.Alerte_Modifier3(ui->lineEdit_id3_2->text().toInt(),3);


        QMessageBox::information(nullptr, QObject::tr("modifier un ventilateur"),
                    QObject::tr("ventilateur modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        n.Alerte_Modifier3(ui->lineEdit_id3_2->text().toInt(),4);

        /*QMessageBox::critical(nullptr, QObject::tr("modifier un ventilateur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

    }

}

void interface1::on_Button_supprimer_clicked()
{
    noti n ;
    int id = ui->lineEdit_7->text().toInt();
    bool test=tmpLampes.supprimer(id);
    if(test)
    {ui->tabLampes->setModel(tmpLampes.afficher());//refresh
        son2->play();
n.Alerte_Supprimer(ui->lineEdit_7->text().toInt(),5);
        QMessageBox::information(nullptr, QObject::tr("Supprimer une lampe"),
                    QObject::tr("Lampe supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        n.Alerte_Ajout(ui->lineEdit_7->text().toInt(),6);
        /*QMessageBox::critical(nullptr, QObject::tr("Supprimer une Lampe"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/


}

void interface1::on_Button_supprimer2_clicked()
{
    noti n ;
    int id = ui->lineEdit_10->text().toInt();
    bool test=tmpchauffage.supprimer(id);
    if(test)
    {ui->tabChauffage->setModel(tmpchauffage.afficher());//refresh
        son2->play();
        n.Alerte_Supprimer2(ui->lineEdit_10->text().toInt(),5);

        QMessageBox::information(nullptr, QObject::tr("Supprimer un chauffage"),
                    QObject::tr("Chauffage supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        n.Alerte_Supprimer3(ui->lineEdit_10->text().toInt(),6);

       /* QMessageBox::critical(nullptr, QObject::tr("Supprimer un Chauffage"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

}

void interface1::on_Button_supprimer3_clicked()
{
    noti n ;
    int id = ui->lineEdit_11->text().toInt();
    bool test=tmpventilateurs.supprimer(id);
    if(test)
    {ui->tabVentilateurs->setModel(tmpventilateurs.afficher());//refresh
        son2->play();
        n.Alerte_Supprimer3(ui->lineEdit_11->text().toInt(),5);

        QMessageBox::information(nullptr, QObject::tr("Supprimer un ventilateur"),
                    QObject::tr("ventilateur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        n.Alerte_Supprimer3(ui->lineEdit_11->text().toInt(),6);

        /*QMessageBox::critical(nullptr, QObject::tr("Supprimer un ventilateur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);*/

}



void interface1::on_pushButton_clicked()
{
    close();
}

void interface1::on_pushButton_3_clicked()
{
close();
}

void interface1::on_pushButton_4_clicked()
{
    close();
}

void interface1::on_pushButton_2_clicked()
{
    close();
}
