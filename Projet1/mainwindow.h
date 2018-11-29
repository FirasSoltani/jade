#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fenetre.h"
#include "lampes.h"
#include "dressing.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fenetre_ajouter_clicked();
    void on_fenetre_modifier_clicked();

    void on_fenetre_supprimer_clicked();

    void on_lampes_ajouter_clicked();

    void on_lampes_modifier_clicked();

    void on_lampes_supprimer_clicked();

    void on_dressing_ajouter_clicked();

    void on_dressing_supprimer_clicked();

    void on_Trie_dressing_clicked();

private:
    Ui::MainWindow *ui;
    Fenetre tmpfenetre;
    Lampes tmplampes;
    dressing tmpdressing;
};

#endif // MAINWINDOW_H
