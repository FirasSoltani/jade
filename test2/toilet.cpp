#include "toilet.h"
#include "ui_toilet.h"
#include "components/qtmaterialdialog.h"
#include "QVBoxLayout"
#include "components/qtmaterialiconbutton.h"
#include "components/lib/qtmaterialtheme.h"
//#include <components/qtmaterialdialog.h>
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

toilet::toilet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::toilet)
{

    ui->setupUi(this);
    ui->verticalLayoutWidget->hide();
    QtMaterialDialog *diag=new QtMaterialDialog();
    QWidget *widg=new QWidget();
    widg->setStyleSheet("QWidget { background: white; }");
    QGridLayout *tablay=new QGridLayout();
    widg->setLayout(tablay);
    diag->layout()->addWidget(widg);
    diag->setParent(ui->verticalLayoutWidget);
    diag->layout()->setAlignment(Qt::AlignCenter);
    //diag->showDialog();


    QtMaterialToggle *tog=new QtMaterialToggle();
    tablay->addWidget(tog,0,0);
    tablay->setAlignment(tog,Qt::AlignTop);

    QtMaterialSlider *slide=new QtMaterialSlider();
    tablay->addWidget(slide,1,0);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
    QtMaterialSnackbar *snk=new QtMaterialSnackbar();
    ui->horizontalLayout->addWidget(snk);

    QtMaterialIconButton *btnclose=new QtMaterialIconButton(QtMaterialTheme::icon("navigation","close"));
    btnclose->setColor(Qt::black);
    tablay->addWidget(btnclose,0,3);

    connect(ui->pushButton,&QPushButton::pressed,this,[=]{ui->horizontalLayoutWidget->show();snk->addMessage("Heating unit assigned !");ui->verticalLayoutWidget->show();diag->showDialog();});


    connect(btnclose,&QtMaterialIconButton::pressed,this,[=]{diag->hideDialog();ui->verticalLayoutWidget->hide();ui->horizontalLayoutWidget->hide();});



    QtMaterialFloatingActionButton *actbtn=new QtMaterialFloatingActionButton(QtMaterialTheme::icon("image","edit"));
    ui->verticalLayout->addWidget(actbtn);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
    actbtn->setRole(Material::Default);
    actbtn->setParent(ui->verticalLayoutWidget_2);
    actbtn->setMini(true);


   // connect(tog,&QtMaterialToggle::pressed,this,[=]{});











}

toilet::~toilet()
{
    delete ui;
}
