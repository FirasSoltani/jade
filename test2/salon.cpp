#include "salon.h"
#include "ui_salon.h"
#include "components/qtmaterialiconbutton.h"
#include "components/lib/qtmaterialtheme.h"
#include <components/qtmaterialdialog.h>
#include <components/qtmaterialtoggle.h>
#include <QVBoxLayout>
#include <QtSql/qsqlquery.h>
#include <components/qtmaterialslider.h>
#include "lights.h"
#include <QTableView>
#include <QDebug>
#include <components/qtmaterialsnackbar.h>
#include <components/qtmaterialfab.h>
#include <components/qtmaterialdrawer.h>
#include <QHeaderView>
#include <components/qtmaterialscrollbar.h>
#include <components/qtmaterialraisedbutton.h>
#include <QTimer>
#include "windows.h"
Salon::Salon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Salon)
{

    ui->setupUi(this);
    QtMaterialIconButton * lights= new QtMaterialIconButton(QtMaterialTheme::icon("navigation", "menu"));
    //ui->verticalLayout->addWidget(lights);
    ui->verticalLayoutWidget_2->hide();
    QtMaterialIconButton * close= new QtMaterialIconButton(QtMaterialTheme::icon("navigation", "close"));




   QtMaterialToggle *tog=new QtMaterialToggle();
   tog->setOrientation(Qt::Horizontal);
   tog->setActiveColor(Qt::black);
   tog->setTrackColor(Qt::white);

   QtMaterialSlider * slide =new QtMaterialSlider();

    ui->verticalLayoutWidget_5->hide();
   QWidget *canvas = new QWidget;
   canvas->setStyleSheet("QWidget { background: white; }");
   QtMaterialDialog *diag=new QtMaterialDialog();
   diag->layout()->addWidget(canvas);
   diag->layout()->setAlignment(Qt::AlignCenter);
   QVBoxLayout * layout = new QVBoxLayout;
   QGridLayout * lay= new QGridLayout();
   canvas->setLayout(lay);
   QLabel *lbl1=new QLabel();
   QLabel *lbl2=new QLabel();
   lbl1->setText("ON/OFF");
   lbl2->setText("Intensity");
   lbl1->setFont(QFont("Roboto", 10, QFont::Medium));
   lbl2->setFont(QFont("Roboto", 10, QFont::Medium));

   QLabel *lbl3=new QLabel();

   lbl3->setFont(QFont("Roboto", 10, QFont::Medium));
   //lbl3->setText();
   lay->addWidget(lbl1,1,1);
   lay->addWidget(lbl2,2,1);
    ui->verticalLayoutWidget_4->hide();
   QtMaterialIconButton *add=new QtMaterialIconButton(QtMaterialTheme::icon("content","add"));

    lay->addWidget(add,0,0);

   lay->addWidget(tog,1,2);
   lay->addWidget(close,0,lay->columnCount());
   lay->addWidget(slide,2,2);
   QtMaterialIconButton *del =new QtMaterialIconButton(QtMaterialTheme::icon("action","delete"));
   lay->addWidget(del,1,lay->columnCount()-1);
   ui->verticalLayout_2->addWidget(diag);

   connect(del,SIGNAL(pressed()),this,SLOT(delet()));
   connect(close,SIGNAL(pressed()),diag,SLOT(hideDialog()));
   connect(close,SIGNAL(pressed()),ui->verticalLayoutWidget_2,SLOT(hide()));
   connect(ui->pushButton_2,SIGNAL(pressed()),diag,SLOT(showDialog()));
   connect(ui->pushButton,SIGNAL(pressed()),diag,SLOT(showDialog()));
   connect(ui->pushButton_3,SIGNAL(pressed()),diag,SLOT(showDialog()));
   //QtMaterialDialog *w=new QtMaterialDialog(diag);
    this->afficher();

    QtMaterialFloatingActionButton *fab=new QtMaterialFloatingActionButton(QtMaterialTheme::icon("image", "edit"));
    QWidget * widg=new QWidget();
    ui->verticalLayout_4->addWidget(widg);
    fab->setParent(widg);
    ui->verticalLayout_4->setAlignment(fab,Qt::AlignCenter);

   // QtMaterialDrawer *drw = new QtMaterialDrawer();
    QVBoxLayout *tablay=new QVBoxLayout();
    class lights light;
    view->setModel(light.displaylights());
    tablay->addWidget(view);
    QWidget *canv = new QWidget;
    canvas->setStyleSheet("QWidget { background: white; }");
    QtMaterialDialog *diagtab=new QtMaterialDialog();
    diagtab->layout()->addWidget(canv);
    //diagtab->layout()->setAlignment(canv,Qt::AlignCenter);
    canv->setLayout(tablay);
    diagtab->setParent(ui->verticalLayoutWidget_4);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    QtMaterialIconButton * closediag= new QtMaterialIconButton(QtMaterialTheme::icon("navigation", "close"));
    //canv->layout()->addWidget(closediag);
    QWidget * widgi=new QWidget();
    QHBoxLayout *lay2=new QHBoxLayout();
    widgi->setLayout(lay2);
    diagtab->layout()->addWidget(widgi);
    lay2->addWidget(closediag);

    ui->verticalLayout_5->setAlignment(closediag,Qt::AlignRight);


    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QtMaterialScrollBar * bar=new QtMaterialScrollBar();
    view->addScrollBarWidget(bar,Qt::AlignRight);
    QtMaterialRaisedButton *delt=new QtMaterialRaisedButton();
    delt->setText("Delete");
    delt->setFont(QFont("Roboto",10,QFont::Medium));
    delt->setRole(Material::Default);
    delt->setIcon(QtMaterialTheme::icon("action","delete"));
    delt->setDisabled(false);
    lay2->addWidget(delt);
    diagtab->layout()->setAlignment(delt,Qt::AlignBottom);

    //diag->layout()->addWidget(widgi);
    diag->layout()->setAlignment(widgi,Qt::AlignBottom);
    //tablay->addWidget(delt,Qt::AlignTop);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    lay2->setStretch(maximumWidth(),maximumWidth());
    bool x=true;
    connect(closediag,SIGNAL(pressed()),diag,SLOT(hideDialog()));
    connect(closediag,SIGNAL(pressed()),ui->verticalLayoutWidget_4,SLOT(hide()));
    view->reset();
    //slide->setDisabled(true);tog->setDisabled(true);del->setDisabled(true);

   //connect(view->selectionModel(),SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),delt,SLOT(setEnabled()));
  //connect(view->selectionModel(),QItemSelectionModel::currentChanged(const QModelIndex &,const QModelIndex &), delt->setEnabled(true));

    /*tablay->addWidget(view);
    drw->setLayout(tablay);
    drw->setParent(this);*/
    connect(fab,SIGNAL(pressed()),diagtab,SLOT(showDialog()));
    connect(fab,SIGNAL(pressed()),ui->verticalLayoutWidget_4,SLOT(show()));
    //connect(fab,SIGNAL(pressed()),view,SLOT());
    QObject::connect(delt,SIGNAL(pressed()),this,SLOT(delet()));
    //connect(add,SIGNAL(pressed()),this,SLOT(add()));
    //QObject::connect(fab,&QtMaterialFloatingActionButton::pressed(),view->setModel(afficher()));
    view->setSortingEnabled(true);
    view->sortByColumn(view->model()->columnCount(),Qt::DescendingOrder);


    //bool l1=false,l2=false,l3=false;
    tog->toggled(0);

    int *i=new int();

    QtMaterialDialog *diagwind=new QtMaterialDialog();
    QWidget *winwcanv=new QWidget();
    QGridLayout *grdw=new QGridLayout();
    winwcanv->setStyleSheet("QWidget { background: white; }");
    winwcanv->setLayout(grdw);
    diagwind->layout()->addWidget(winwcanv);
    diagwind->layout()->setAlignment(Qt::AlignCenter);
    diagwind->setParent(ui->verticalLayoutWidget);
    QtMaterialIconButton *closew=new QtMaterialIconButton(QtMaterialTheme::icon("navigation","close"));
    grdw->addWidget(closew,0,3);
    QtMaterialIconButton *deletw=new QtMaterialIconButton(QtMaterialTheme::icon("action","delete"));
    QtMaterialIconButton *addw=new QtMaterialIconButton(QtMaterialTheme::icon("content","add"));
    grdw->addWidget(addw,1,3);
    QObject::connect(closew,&QtMaterialIconButton::pressed,diagwind,[=]{diagwind->hideDialog();ui->verticalLayoutWidget->hide();});
    QObject::connect(ui->pushButton_4,&QPushButton::pressed,diagwind,[=]{ui->verticalLayoutWidget->show();diagwind->showDialog();});
    QtMaterialSlider *wslide=new QtMaterialSlider();
    QtMaterialSlider *sslide=new QtMaterialSlider();

    QObject::connect(addw,&QtMaterialIconButton::pressed,this,[=]{addwindw(1,"1");});
    QObject::connect(deletw,&QtMaterialIconButton::pressed,this,[=]{deletwindw(1);});
    QTableView *windwv=new QTableView();
    windows * windws;
    windwv->setModel(windws->displaywindows());
    diagtab->layout()->addWidget(windwv);
    connect(fab,&QtMaterialFloatingActionButton::pressed,this,[=]{windwv->setModel(windws->displaywindows());});
    windwv->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(delt,&QtMaterialRaisedButton::pressed,this,[=]{windws->deletewindow(windwv->model()->index(windwv->currentIndex().row(),0).data().toInt());windwv->setModel(windws->displaywindows());});




    grdw->addWidget(wslide,1,0);
    grdw->addWidget(sslide,3,0);
    grdw->addWidget(deletw,2,3);
    QLabel *windw=new QLabel();
    QLabel *shade=new QLabel();
    windw->setText("Window level !");
    shade->setText("Shade level !");
    grdw->addWidget(windw,0,0);
    grdw->addWidget(shade,2,0);
    windw->setFont(QFont("Roboto",10,QFont::Medium));
    shade->setFont(QFont("Roboto",10,QFont::Medium));
    //QObject::connect(diagwind,&QtMaterialDialog::is)

    ui->verticalLayoutWidget->hide();

    snk->setParent(ui->verticalLayoutWidget_5);
    QObject::connect(fab, &QtMaterialFloatingActionButton::clicked, view,  [=]() {view->setModel(this->afficher());});
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,[=](){view->setModel(this->afficher());view->model()->sort(0,Qt::SortOrder::DescendingOrder);*i=0;crtlight=view->model()->index(*i,0).data().toInt();qDebug()<<crtlight;
    if(this->checkassigned(crtlight,*i,0,*i)){slide->setDisabled(true);tog->setDisabled(true);tog->toggled(0);del->setDisabled(true);}else{tog->setEnabled(true);tog->toggled(0);slide->setEnabled(true);del->setEnabled(true);}if(view->model()->index(*i,1).data().toInt()==1)tog->toggled(true);else tog->toggled(false);slide->setValue(view->model()->index(*i,2).data().toInt());slide->update();});
    QObject::connect(slide,&QtMaterialSlider::valueChanged,this,[=]{qDebug()<<slide->value();modifierint(slide->value(),*i);});

    QObject::connect(slide,&QtMaterialSlider::sliderReleased,tog,[=]{if(slide->value()>1){tog->setEnabled(1);modifieretat(*i,1);}else{tog->setDisabled(1);modifieretat(*i,0);}});
    QObject::connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){view->setModel(this->afficher());view->model()->sort(0,Qt::SortOrder::DescendingOrder);*i=1;crtlight=view->model()->index(*i,0).data().toInt();qDebug()<<crtlight;
    if(this->checkassigned(crtlight,*i,0,*i)){slide->setDisabled(true);tog->setDisabled(true);tog->toggled(0);del->setDisabled(true);}else{tog->setEnabled(true);tog->toggled(0);slide->setEnabled(true);del->setEnabled(true);}if(view->model()->index(*i,1).data().toInt()==1)tog->toggled(true);else tog->toggled(false);slide->setValue(view->model()->index(*i,2).data().toInt());slide->update();});
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,this,[=](){view->setModel(this->afficher());view->model()->sort(0,Qt::SortOrder::DescendingOrder);*i=2;crtlight=view->model()->index(*i,0).data().toInt();qDebug()<<crtlight;
    if(this->checkassigned(crtlight,*i,0,*i)){slide->setDisabled(true);tog->setDisabled(true);tog->toggled(0);del->setDisabled(true);}else{tog->setEnabled(true);tog->toggled(0);slide->setEnabled(true);del->setEnabled(true);}if(view->model()->index(*i,1).data().toInt()==1)tog->toggled(true);else tog->toggled(false);slide->setValue(view->model()->index(*i,2).data().toInt());slide->update();});
    QObject::connect(add,&QtMaterialIconButton::clicked,this,[=](){if(checkassigned(crtlight,*i,2,*i)){this->add(*i);tog->setEnabled(true);slide->setEnabled(true);del->setEnabled(true);};});
    qDebug()<<view->model()->index(1,2).data().toInt();
    connect(tog,&QtMaterialToggle::pressed,this,[=]{if(tog->isChecked()) modifieretat(*i,1); else modifieretat(*i,0);});
    //connect(tog,&QtMaterialToggle::,[=]{if(tog->isChecked())modifieretat(*i,1);});

    qDebug()<< tog->isChecked();
    //ui->verticalLayoutWidget_3->show();

}

void Salon::modifierint(int value,int pos)
{

    lights light;
    light.modifierintensity(value,pos);


}

bool Salon::checkassigned(int indx,int i,int state,int pos)
{
lights light;

ui->verticalLayoutWidget_5->show();
//ui->verticalLayoutWidget_2->layout()->setAlignment(snk,Qt::AlignBottom);
//ui->verticalLayout_2->setAlignment(snk,Qt::AlignBottom);
if(!light.findlight(pos))
{
    if(state==0)
    {snk->addInstantMessage(QString("There is no light assigned!"));}
    else
        if(state==2)
    {snk->addInstantMessage(QString("Assigning light !"));}
    //view->hide();
            view->setModel(light.displaylights());
    crtlight=view->model()->index(i,0).data().toInt();
    QEventLoop loop;
    QTimer::singleShot(1500, &loop, SLOT(quit()));
    loop.exec();
    ui->verticalLayoutWidget_5->hide();

    return (true);

}
else
{
    qDebug() << "FOUND";
    snk->addInstantMessage(QString("The light bulb exists"));
    QEventLoop loop;
    QTimer::singleShot(1500, &loop, SLOT(quit()));
    loop.exec();
    ui->verticalLayoutWidget_5->hide();
    return(false);
}

}

Salon::~Salon()
{
    delete ui;
}

void Salon::on_pushButton_clicked()
{
        ui->verticalLayoutWidget_2->show();


}



void Salon::modifieretat(int indx,int etat)
{
   lights light;
   light.modifier(indx,etat);

}

QSortFilterProxyModel * Salon::afficher()
{
lights light;

return(light.displaylights());

}

void Salon::faire()
{


}

void Salon::delet()
{
lights light;
qDebug() << view->currentIndex().data().toString();
light.deletelight(view->currentIndex().data().toInt());
view->setModel(light.displaylights());

}

void Salon::on_pushButton_2_clicked()
{
    ui->verticalLayoutWidget_2->show();

}

void Salon::on_pushButton_3_clicked()
{
    ui->verticalLayoutWidget_2->show();

}

void Salon::add(int i)
{

    lights light;
    light.addlight(0,"1",i);

}

void Salon::addwindw(int id,QString ch)
{
    windows window;
    window.addwindows(id,ch);



}

void Salon::deletwindw(int id)
{

    windows window;
    window.deletewindow(id);

}
