#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source");
    db.setUserName("firas");
    db.setPassword("esprit18");
    db.open();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
