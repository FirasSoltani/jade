#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lights.h"
#include "addlights.h"
#include "modifylight.h"
#include "user.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mdp="";
     ui->tabWidget->setCurrentIndex(0);
    QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
    tabBar->hide();



  }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::button()
{

    QToolButton * b = new QToolButton;
    b->setCheckable(true);
    b->setChecked(true);
    b->setAutoRaise(true);
    b->setText("Hide Tabs");
    ui->tabWidget->setCornerWidget(b);

}

void MainWindow::on_pushButton_16_clicked()
{
   ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-1);
}

void MainWindow::on_pushButton_15_clicked()
{
   ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
}

void MainWindow::on_pushButton_17_clicked()
{
   ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
}

void MainWindow::on_pushButton_20_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
}

void MainWindow::on_pushButton_22_clicked()
{
     ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_21_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-1);
}

void MainWindow::on_pushButton_19_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-1);
}



void MainWindow::on_pushButtonlights_clicked()
{
     ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButtonwindows_clicked()
{
     ui->tabWidget->setCurrentIndex(4);
     ui->tableViewWindows->setModel(wi.displaywindows());
     ui->tableViewWindows->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void MainWindow::on_backbt_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-2);
}


void MainWindow::on_backbt2_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-2);
}


void MainWindow::speak(QString q)
{

    QTextToSpeech *speech=new QTextToSpeech();
    speech->setLocale(QLocale::English);
    speech->say(q);
}


void MainWindow::on_textEdit_2_textChanged()
{


}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    l.modifierintensity(value,index);
}

/*void MainWindow::on_radioButton_2_clicked(bool checked,Lights l)
{    QMessageBox q;
     q.exec();
    if(checked)
        l.modifieretat(0);
}*/

/*void MainWindow::on_radioButton_clicked(bool checked,Lights l)
{
    QMessageBox q;
    q.exec();
    if(checked)
        l.modifieretat(1);

}*/

/*void MainWindow::on_radioButton_toggled(bool checked)
{
    QMessageBox q;
    q.exec();
    if(checked)
        l.modifieretat(1);

}*/

void MainWindow::on_pushButton_27_clicked()
{
    ui->tableViewlights->setModel(l.displaylights());
}

void MainWindow::on_tableViewlights_activated(const QModelIndex &index)
{
    this->index=ui->tableViewlights->model()->data(index).toInt();
}

void MainWindow::on_tableViewlights_doubleClicked(const QModelIndex &index)
{   Modifylight m(nullptr,this->index=ui->tableViewlights->model()->data(index).toInt(),this->ui->tableViewlights->model()->data(this->ui->tableViewlights->model()->index(index.row(),2)).toInt(),this->ui->tableViewlights->model()->data(this->ui->tableViewlights->model()->index(index.row(),1)).toInt(),this->userdesc);
    m.exec();
    ui->tableViewlights->setModel(l.displaylights());
}

void MainWindow::on_pushButton_28_clicked()
{
       Addlights w;
       w.exec();
       ui->tableViewlights->setModel(l.displaylights());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
     ui->tableViewlights->setModel(l.displaylights());
     ui->tableViewlights->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_bt_login_clicked()
{
    if(U.verification(this->ui->id_login->text(),this->ui->mdp_login->text())!="")
       { QMessageBox::information(nullptr,"Login","Login Succesfull");
         ui->tabWidget->setCurrentIndex(1);
            if(U.verification(this->ui->id_login->text(),this->ui->mdp_login->text())!="admin")
            {
                ui->addlightbt->setEnabled(0);
                ui->addwindow->setEnabled(0);
                this->userdesc=1;
            }
    }
    else
        QMessageBox::critical(nullptr,"Login","Login Failed");
}

void MainWindow::on_pushButton_clicked()
{
    Useredit Us;
     if(U.verification(this->ui->id_login->text(),this->ui->mdp_login->text())=="admin")
     {

        Us.exec();
     }
     else
     {QMessageBox::critical(nullptr,"Login","Check your login informations");
      speak("Please check your infos or you might not be an administrator");
     }
}

void MainWindow::on_pushButton_2_clicked()
{
  editchambers e;
  if(U.verification(this->ui->id_login->text(),this->ui->mdp_login->text())=="admin")
  {

    e.exec();
  }
  else
  {QMessageBox::critical(nullptr,"Login","Check your login informations");
      speak("Please check your infos or you might not be an administrator");
}
}

void MainWindow::on_tableViewWindows_clicked(const QModelIndex &index)
{
    this->index=ui->tableViewWindows->model()->data(ui->tableViewWindows->model()->index(index.row(),0)).toInt();
    this->ui->horizontalSlider_2->setValue(ui->tableViewWindows->model()->data(ui->tableViewWindows->model()->index(index.row(),2)).toInt());
    this->ui->horizontalSlider_3->setValue(ui->tableViewWindows->model()->data(ui->tableViewWindows->model()->index(index.row(),3)).toInt());
}



void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    wi.modifiernivf(value,this->index);
    ui->tableViewWindows->setModel(wi.displaywindows());
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    wi.modifiernivr(value,this->index);
    ui->tableViewWindows->setModel(wi.displaywindows());
}

void MainWindow::on_pushButton_3_clicked()
{
   addwindow aw(nullptr,ui->tableViewWindows);
   aw.exec();

}




void MainWindow::on_tableViewWindows_doubleClicked(const QModelIndex &index)
{
    if(!(this->userdesc!=0))
    {
    if(wi.deletewindow(ui->tableViewWindows->model()->data(index).toInt()))
    {QMessageBox::information(nullptr,"Deleted","The window was deleted from the DataBase");}
    ui->tableViewWindows->setModel(wi.displaywindows());
    speak("The Window was deleted");
  }
}


void MainWindow::on_addlightbt_clicked()
{
    Addlights w;
    w.exec();
    ui->tableViewlights->setModel(l.displaylights());
}
