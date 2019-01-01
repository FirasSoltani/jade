#ifndef SALON_H
#define SALON_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>
#include <components/qtmaterialsnackbar.h>
#include <QSortFilterProxyModel>

namespace Ui {
class Salon;
}

class Salon : public QWidget
{
    Q_OBJECT

public:
    explicit Salon(QWidget *parent = nullptr);
    ~Salon();
    QTableView * view=new QTableView();
    int crtlight;
    bool checkassigned(int,int,int,int);
    QtMaterialSnackbar *snk=new QtMaterialSnackbar();

    void add(int);
private slots:
    void on_pushButton_clicked();
    void modifierint(int,int);
    void addwindw(int,QString);
    void deletwindw(int);

     void modifieretat(int,int);
     void faire();
     void delet();


     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

private:
    Ui::Salon *ui;
   QSortFilterProxyModel * afficher();
};

#endif // SALON_H
