#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMediaPlayer>
#include "chaufage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1("C:/Users/selim/Desktop/selim sayeh/Projet_qt/images/car.png");
    ui->label1->setPixmap(pix1);
    QPixmap pix2("C:/Users/selim/Desktop/selim sayeh/Projet_qt/images/temperature.png");
    ui->label_2->setPixmap(pix2);
    QPixmap pix3("C:/Users/selim/Desktop/selim sayeh/Projet_qt/images/camera.png");
    ui->label->setPixmap(pix3);


    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/son.mp3")) ;
    music->play();

 /*Animation =new QPropertyAnimation(ui->label,"geometry");
     Animation->setDuration(10000);
     Animation->setStartValue(QRect(0,0,100,30));
     Animation->setEndValue(QRect(20,0,100,30));
     Animation->start();
*/
}
MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    T = new Temperature(this);
    T->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/klaxon.mp3")) ;
    music->play();
    V= new Voiture(this);
  V->show();
}

void MainWindow::on_pushButton_3_clicked()
{
  C=new Webcam(this);
  C->show();
}
