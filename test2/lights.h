#ifndef LIGHTS_H
#define LIGHTS_H
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>

class lights
{
public:
    lights();

    void modifier(int,int);
    QSortFilterProxyModel * displaylights();
    bool deletelight(int index);
    bool addlight(int id,QString cb,int);
    bool findlight(int pos);
     bool modifierintensity(int,int);
};

#endif // LIGHTS_H
