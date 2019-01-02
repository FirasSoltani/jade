#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "components/qtmaterialdrawer.h"
#include <qlabel.h>
#include <QtTest/QSignalSpy>
#include <QStateMachine>
#include <QTimer>
#include <components/qtmaterialdrawer_internal.h>
#include "components/qtmaterialavatar.h"
#include "components/qtmaterialdialog.h"
#include <components/qtmaterialbadge.h>
#include <components/qtmaterialtabs.h>
#include "salon.h"
#include <QDebug>
#include "toilet.h"

#include "QScrollArea"

extern QState *s4;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    Salon * sal=new Salon();

    ui->setupUi(this);
    QtMaterialAvatar * avatar=new QtMaterialAvatar();
    avatar->setLetter(QChar('F'));
    QtMaterialAppBar * appbar=new QtMaterialAppBar();
    appbar->setBackgroundColor(Qt::black);
    ui->horizontalLayout->addWidget(appbar);
    QtMaterialIconButton *button = new QtMaterialIconButton(QtMaterialTheme::icon("navigation", "menu"));
    button->setIconSize(QSize(24, 24));
    button->setColor(Qt::white);
    //ui->widget_3->setLayout(ui->verticalLayout_3);
    appbar->appBarLayout()->addWidget(button);
    appbar->appBarLayout()->setAlignment(button, Qt::AlignLeft);
    QtMaterialDrawer * drawer=new QtMaterialDrawer();
    drawer->setDrawerWidth(210);

    //appbar->appBarLayout()->setAlignment(avatar,Qt::AlignRight);

    QtMaterialIconButton *notifications=new QtMaterialIconButton(QtMaterialTheme::icon("social","notifications"));
    notifications->setIconSize(QSize(21,21));
    notifications->setColor(Qt::white);
    //ui->verticalLayout_3->addWidget(notifications,0,Qt::AlignRight);
    //ui->verticalLayout_3->addWidget(avatar,0,Qt::AlignRight);

    //appbar->appBarLayout()->setAlignment(avatar,Qt::AlignRight);
    //appbar->appBarLayout()->setAlignment(notifications,Qt::AlignRight);


    appbar->appBarLayout()->setDirection(QBoxLayout::LeftToRight);
     QtMaterialBadge * badge=new QtMaterialBadge;

     badge->setParent(notifications);
     badge->setRelativePosition(18, 18);
     badge->setBackgroundColor(Qt::white);
     badge->setTextColor(Qt::red);
     badge->setText("9");
     badge->isEnabled();
     badge->setIcon(QIcon(QtMaterialTheme::icon("communication", "message")));



    QtMaterialDialog * avatarmenu=new QtMaterialDialog();

    //avatarmenu->setWindowLayout(ui->verticalLayout_4);
    //avatarmenu->layout()->addWidget(avatarmenu);
    //avatarmenu->setParent(ui->verticalLayoutWidget);

    //connect(button,SIGNAL(pressed()),avatarmenu,SLOT(showDialog()));

    ui->widget->hide();

    //QVector<QString> labels = {"Living Room"};
      //QVBoxLayout *layout = new QVBoxLayout;
    //QVector<QString>::iterator it;
    QtMaterialFlatButton * living = new QtMaterialFlatButton();
    QtMaterialFlatButton * kitchen = new QtMaterialFlatButton();
    QtMaterialFlatButton * sleeping = new QtMaterialFlatButton();
    QtMaterialFlatButton * garage = new QtMaterialFlatButton();
    QtMaterialFlatButton * toilet1 = new QtMaterialFlatButton();
    living->setText("Living Room");
    living->setMinimumHeight(20);
    living->setFont(QFont("Roboto", 10, QFont::Medium));
    living->setIcon(QtMaterialTheme::icon("action", "home"));
    living->setIconPlacement(Material::LeftIcon);

    kitchen->setText("Kitchen");
    kitchen->setMinimumHeight(20);
    kitchen->setFont(QFont("Roboto", 10, QFont::Medium));
    kitchen->setIcon(QtMaterialTheme::icon("places", "kitchen"));
    kitchen->setIconPlacement(Material::LeftIcon);

    sleeping->setText("Sleeping Room");
    sleeping->setMinimumHeight(20);
    sleeping->setFont(QFont("Roboto", 10, QFont::Medium));
    sleeping->setIcon(QtMaterialTheme::icon("maps", "local_hotel"));
    sleeping->setIconPlacement(Material::LeftIcon);

    garage->setText("Garage");
    garage->setMinimumHeight(20);
    garage->setFont(QFont("Roboto", 10, QFont::Medium));
    garage->setIcon(QtMaterialTheme::icon("maps", "directions_car"));
    garage->setIconPlacement(Material::LeftIcon);

    toilet1->setText("Bathroom");
    toilet1->setMinimumHeight(20);
    toilet1->setFont(QFont("Roboto", 10, QFont::Medium));
    toilet1->setIcon(QtMaterialTheme::icon("places", "hot_tub"));
    toilet1->setIconPlacement(Material::LeftIcon);


    toilet *toil=new toilet();

    ui->verticalLayout_3->addWidget(toil);
    ui->verticalLayoutWidget_3->hide();
    connect(living,&QtMaterialFlatButton::pressed,this,[=]{ui->verticalLayoutWidget_3->hide();ui->verticalLayoutWidget_2->show();sal->show();});

    connect(toilet1,&QtMaterialFlatButton::pressed,this,[=]{ui->verticalLayoutWidget_2->hide();ui->verticalLayoutWidget_3->show();toil->show();});
//QWidget * widget2=new QWidget();
//ui->widget_2->setLayout(ui->verticalLayout_2);

drawer->setDrawerLayout(ui->verticalLayout);



        drawer->drawerLayout()->addWidget(living);
        drawer->drawerLayout()->addWidget(kitchen);
        drawer->drawerLayout()->addWidget(sleeping);
        drawer->drawerLayout()->addWidget(garage);
        drawer->drawerLayout()->addWidget(toilet1);


    drawer->setParent(ui->verticalLayoutWidget);
    drawer->setClickOutsideToClose(true);
    drawer->setOverlayMode(true);
    ui->widget->setLayout(ui->verticalLayout);
    //setupForm();
    //int i=0;
    //QSignalSpy spy(button,SIGNAL(pressed()));

    QStateMachine *machine=new QStateMachine;
    QState *s1=new QState();
    QState *s2=new QState();
    //QState *s3=new QState();
    s1->addTransition(button, SIGNAL(pressed()), s2);
    s2->addTransition(button, SIGNAL(pressed()), s1);
    //s3->addTransition(button,SIGNAL(pressed()),s1);
     machine->addState(s1);
     machine->addState(s2);
     //machine.addState(s3);
     machine->setInitialState(s1);
     machine->start();
    ui->verticalLayout_2->addWidget(sal);
    sal->hide();
    connect(s2, SIGNAL(entered()), drawer, SLOT(openDrawer()));
    connect(s2, SIGNAL(entered()), ui->widget, SLOT(show()));
    //connect(living,SIGNAL(pressed()),sal,SLOT(show()));
    connect(s4, SIGNAL(entered()), ui->widget , SLOT(hide()));
    //connect(s2, SIGNAL(entered()), ui->widget_2, SLOT(hide()));
    //connect(s4, SIGNAL(entered()), ui->widget_2,SLOT(show()));

    connect(s2, SIGNAL(exited()), drawer, SLOT(closeDrawer()));
    //connect(s4, SIGNAL(exited()), ui->widget , SLOT(show()));
    //connect(s2, SIGNAL(exited()), ui->widget_2, SLOT(show()));
    //connect(s4, SIGNAL(exited()), ui->widget_2,SLOT(hide()));

    QtMaterialTabs * tabs=new QtMaterialTabs();







     //ui->verticalLayout->addWidget(tabs);
    tabs->addTab("Media");
    tabs->addTab("Playback");
    tabs->addTab("Audio");
    tabs->addTab("Video");
    tabs->addTab("Tools");

    //ui->widget_2->layout()->addWidget(avatarmenu);
    //ui->widget_2->layout()->setAlignment(avatarmenu,Qt::AlignCenter);
    //avatarmenu->setLayout(ui->verticalLayout_2);
    //ui->widget_2->layout()->setContentsMargins(20, 20, 20, 20);

    //avatarmenu->setParent(ui->widget_2);
    //avatarmenu->showDialog();

    /*connect(living, SIGNAL(pressed()), drawer ,SLOT(closeDrawer()));
    connect(living, SIGNAL(pressed()), ui->widget , SLOT(hide()));
    connect(living, SIGNAL(pressed()), ui->widget_2, SLOT(show()));
*/

        qDebug()<<ui->horizontalLayout->geometry().height();
}

MainWindow::~MainWindow()
{
    delete ui;
}
