#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtEvents>
#include <QString>
#include <QThread>
#include <QMessageBox>
#include <QToolButton>
#include <QTabBar>
#include <QtTextToSpeech/QTextToSpeech>
#include <iostream>
#include <QSqlDatabase>
#include <QDebug>
#include <lights.h>
#include "user.h"
#include "useredit.h"
#include "editchambers.h"
#include "windows.h"
#include "addwindow.h"



namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(QString mdp){this->mdp=mdp;}
    ~MainWindow();
    void speak(QString q);





private slots:

    void on_pushButton_11_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_19_clicked();

    //void on_pushButton_12_clicked();

    void on_pushButtonlights_clicked();

    void on_pushButtonwindows_clicked();



    void on_backbt_clicked();

    void on_backbt2_clicked();

    void on_textEdit_2_textChanged();

    void on_horizontalSlider_valueChanged(int value);

  // void on_radioButton_2_clicked(bool checked,Lights l);

  // void on_radioButton_clicked(bool checked,Lights l);

    //void on_radioButton_toggled(bool checked);

   void on_pushButton_27_clicked();

   void on_tableViewlights_activated(const QModelIndex &index);

   void on_tableViewlights_doubleClicked(const QModelIndex &index);

   void on_pushButton_28_clicked();

   void on_tabWidget_currentChanged(int index);

   void on_bt_login_clicked();

   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

   void on_tableViewWindows_clicked(const QModelIndex &index);

   void on_horizontalSlider_2_valueChanged(int value);

   void on_horizontalSlider_3_valueChanged(int value);

   void on_pushButton_3_clicked();

   void on_tableViewWindows_doubleClicked(const QModelIndex &index);


   void on_addlightbt_clicked();

private:
    Ui::MainWindow *ui;
    bool test(QString);
    QTextToSpeech *m_speech;



public:
    QString mdp;
    void button();
    Lights l;
    //void setlight(Lights *l);
    int index;
    User U;
    int userdesc;
    windows wi;


};


#endif // MAINWINDOW_H
