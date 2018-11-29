#include "mainwindow.h"
#include <QApplication>
#include "connect.h"
#include "QMessageBox"
//#include<QSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connect c;
    if(c.connectsql())
    {
     QMessageBox::information(nullptr,"","Access Granted");
    }
    else
        QMessageBox::information(nullptr,"","Acess Denied");


    w.mdp="1234";

    w.show();
    w.button();
    //   w.n1(event);
    w.update();
    //.deletelight(12);

    return a.exec();
}
