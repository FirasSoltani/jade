#ifndef LIGHTS_H
#define LIGHTS_H
#include<QSqlQuery>
#include<QString>
#include<QSqlQueryModel>
#include"chambers.h"

class Lights
{
public:
    Lights();
    Lights(int,int,int);
    ~Lights(){}
     chambers ch;
private :
    int indexl;
    bool etat;
    float intensity;
public :
    void setindex(int);
    int getindex(){return (indexl);}
    bool modifierintensity(int,int);
    bool modifieretat(int,int);
    bool deletelight(int);
    bool addlight(int,QString);
    QSqlQueryModel * displaylights();

};

#endif // LIGHTS_H
