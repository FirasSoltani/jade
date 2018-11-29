#ifndef USER_H
#define USER_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class User
{
public:
    User();
    int nb=0;
private :
    QString id;
    QString mdp;
    QString des;
    QModelIndex *index;
public :
    QString getid();
    QString getmdp(){return mdp;}
    QString getdes(){return des;}
    bool adduser(QString,QString,QString);
    bool modifierpass(QString,QString);
    bool modifierdes(QString,QString);
    bool deleteuser(QString);
    QSqlQueryModel * displayusers();
    QString verification(QString,QString);
    void setindex(QModelIndex *);
    void setid(QString);
    QSqlQueryModel * search(QString);
};

#endif // USER_H
