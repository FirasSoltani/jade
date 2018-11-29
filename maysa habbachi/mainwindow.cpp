#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include "interface1.h"
#include "notification.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix("C:/Users/loume/Desktop/qt/back.jpg");
    ui->label->setPixmap(pix.scaled(900,657,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //hide();
    interface1 show;
    show.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    notification afficher;
    afficher.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}
