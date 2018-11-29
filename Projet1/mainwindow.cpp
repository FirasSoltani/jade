#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fenetre.h"
#include "lampes.h"
#include "dressing.h"
#include <QMessageBox>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMediaPlayer *music=new QMediaPlayer();
        music->setMedia(QUrl("qrc:son/son/debut.mp3")) ;
        music->play();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_fenetre_ajouter_clicked()
{
    int id = ui->lineEdit_f->text().toInt();
    int niveau= ui->comboBox_f->currentIndex()+1;
    if(id==0)
    {QMessageBox::information(nullptr, QObject::tr("ERROR SAISI"),
                              QObject::tr("ID doit etre superieur a 0 ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
  Fenetre f(id,niveau);
  bool test=f.Ajouter_fenetre();
  if(test)
{ui->tabfenetre->setModel(tmpfenetre.Afficher_fenetre());
QMessageBox::information(nullptr, QObject::tr("Ajouter une Fenetre"),
                  QObject::tr("Fenetre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Fenetre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_fenetre_modifier_clicked()
{
    int id = ui->lineEdit_m->text().toInt();
    int niveau= ui->comboBox_f_2->currentIndex()+1;
  Fenetre f(id,niveau);
  bool test=f.Modifier_fenetre(id);
  if(test)
{ui->tabfenetre->setModel(tmpfenetre.Afficher_fenetre());
QMessageBox::information(nullptr, QObject::tr("Modifier une Fenetre"),
                  QObject::tr("Fenetre Modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une Fenetre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_fenetre_supprimer_clicked()
{
    int id = ui->lineEdit_ids->text().toInt();
    bool test=tmpfenetre.Supprimer_fenetre(id);
    if(test)
    {ui->tabfenetre->setModel(tmpfenetre.Afficher_fenetre());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Fenetre"),
                    QObject::tr("Fenetre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Fenetre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lampes_ajouter_clicked()
{
    int id = ui->lineEdit_l->text().toInt();
    QString couleur = ui->lineEdit_2l->text();
    int luminosite = ui->comboBox_l->currentText().toInt();
  Lampes l(id,couleur,luminosite);
  bool test=l.Ajouter_lampe();
  if(test)
{ui->tablampes->setModel(tmplampes.Afficher_lampe());
QMessageBox::information(nullptr, QObject::tr("Ajouter une Lampe"),
                  QObject::tr("Lampe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Lampe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lampes_modifier_clicked()
{
    int id = ui->lineEdit_4l->text().toInt();
    QString couleur = ui->lineEdit_3l->text();
    int luminosite = ui->comboBox_2l->currentText().toInt();
  Lampes l(id,couleur,luminosite);
  bool test=l.Modifier_lampe(id);
  if(test)
{ui->tablampes->setModel(tmplampes.Afficher_lampe());
QMessageBox::information(nullptr, QObject::tr("Modifier une Lampe"),
                  QObject::tr("Lampe modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une Lampe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_lampes_supprimer_clicked()
{
    int id = ui->lineEdit_13l->text().toInt();
    bool test=tmplampes.Supprimer_lampe(id);
    if(test)
    {ui->tablampes->setModel(tmplampes.Afficher_lampe());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Fenetre"),
                    QObject::tr("Fenetre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Fenetre"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_dressing_ajouter_clicked()
{
    int id = ui->lineEdit_d->text().toInt();
    QString couleur = ui->lineEdit_2_d->text();
    QString categorie= ui->comboBox_d->currentText();
  dressing d(id,couleur,categorie);
  bool test=d.Ajouter_dressing();
  if(test)
{ui->tabdressing->setModel(tmpdressing.Afficher_dressing());
QMessageBox::information(nullptr, QObject::tr("Ajouter vetement"),
                  QObject::tr("Fenetre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter vetement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_dressing_supprimer_clicked()
{
    int id = ui->lineEdit_15s->text().toInt();
    bool test=tmpdressing.Supprimer_dressing(id);
    if(test)
    {ui->tabdressing->setModel(tmpdressing.Afficher_dressing());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer vetement"),
                    QObject::tr("Fenetre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer vetement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Trie_dressing_clicked()
{
    ui->tabdressingtri->setModel(tmpdressing.tri_dressing());
}
