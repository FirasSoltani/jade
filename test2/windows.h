#ifndef WINDOWS_H
#define WINDOWS_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class windows
{
public:
    windows();

    bool modifiernivr(int,int);
    bool modifieretat(int,int);
    bool modifiernivf(int,int);
    bool deletewindow(int);
    bool addwindows(int,QString);
    QSqlQueryModel * displaywindows();
};

#endif // WINDOWS_H
