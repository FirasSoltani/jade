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
    ui->tabWidget->setCurrentIndex(4);
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
   ui->tabWidget->setCurrentIndex(3);
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

void MainWindow::on_pushButton_12_clicked()
{
     ui->tabWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->tabWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->tabWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_23_clicked()
{
     ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-3);
}

void MainWindow::on_pushButton_26_clicked()
{
  ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-3);
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-3);
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-3);
}


void MainWindow::speak()
{

    QTextToSpeech *speech=new QTextToSpeech();
    speech->setLocale(QLocale::English);
    speech->say("Hello");
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
    ui->tableView->setModel(l.displaylights());
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    this->index=ui->tableView->model()->data(index).toInt();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{   Modifylight m(nullptr,this->index=ui->tableView->model()->data(index).toInt(),this->ui->tableView->model()->data(this->ui->tableView->model()->index(index.row(),2)).toInt(),this->ui->tableView->model()->data(this->ui->tableView->model()->index(index.row(),1)).toInt());

    m.exec();
    ui->tableView->setModel(l.displaylights());
}

void MainWindow::on_pushButton_28_clicked()
{
       Addlights w;
       w.exec();
       ui->tableView->setModel(l.displaylights());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
     ui->tableView->setModel(l.displaylights());
     ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_bt_login_clicked()
{
    if(U.verification(this->ui->id_login->text(),this->ui->mdp_login->text())!="")
       { QMessageBox::information(nullptr,"Login","Login Succesfull");
         ui->tabWidget->setCurrentIndex(1);
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
         QMessageBox::critical(nullptr,"Login","Check your login informations");
}

void MainWindow::on_pushButton_2_clicked()
{

}
