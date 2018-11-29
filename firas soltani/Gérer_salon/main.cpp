#include "mainwindow.h"
#include <QApplication>
#include "connect.h"
#include "QMessageBox"
//#include<QSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connect c;
    if(c.connectsql())
    {
     QMessageBox::information(nullptr,"","Access Granted");
    }
    else
        QMessageBox::information(nullptr,"","Acess Denied");

     MainWindow w;
     w.show();

    return a.exec();
}
