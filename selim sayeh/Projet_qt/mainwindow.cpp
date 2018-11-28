#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1("C:/Users/selim/Desktop/selim sayeh/Projet_qt/images/car.png");
    ui->label1->setPixmap(pix1);
    QPixmap pix2("C:/Users/selim/Desktop/selim sayeh/Projet_qt/images/temperature.png");
    ui->label_2->setPixmap(pix2);

    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/son.mp3")) ;
    music->play();
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
