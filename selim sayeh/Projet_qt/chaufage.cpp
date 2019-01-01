#include "chaufage.h"
#include "ui_chaufage.h"
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>

Chaufage::Chaufage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chaufage)
{
    ui->setupUi(this);
}
//CONSTRUCTEURS


Chaufage::~Chaufage()
{
    delete ui;
}
Chaufage::Chaufage()
{
    this->idc=0;
    this->tempc=23;
}


//GETTERS

int Chaufage::get_temp()
{return tempc;}

int Chaufage::get_id()
{return idc;}


// AJOUT CHAUFAGE
bool Chaufage::ajouter_temp()
{
    QSqlQuery query;
 QString res= QString::number(idc);
    query.prepare("INSERT INTO CHAUFAGE (IDC,TEMPC) "
                        "VALUES (:idc, :tempc)");
    query.bindValue(":idc", res);
    query.bindValue(":tempc", tempc);
    return  query.exec();

}
void Chaufage::afficher(QTableView *tab)
   {
       QSqlQueryModel *model =new QSqlQueryModel();
       QSqlQuery *query = new QSqlQuery();

      query->prepare("SELECT * FROM CHAUFAGE");
       query->exec();
       model->setQuery(*query);
       tab->setSelectionBehavior(QAbstractItemView::SelectRows);
       tab->setModel(model);
   }
bool Chaufage::modifier(int IDC,int temp)
{
     QSqlQuery *ql=new QSqlQuery();
     ql->prepare("UPDATE Chaufage SET TEMPC=? WHERE IDC=? ");
     ql->addBindValue(temp);
     ql->addBindValue(IDC);
     return (ql->exec());

}




void Chaufage::on_dial_sliderReleased()
{
    tempc=ui->lcdNumber->value();


}
void Chaufage::on_pb_ajouter_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/done.mp3")) ;
    music->play();
    idc=ui->lineEdit_id->text().toInt();
    on_dial_sliderReleased();
    if(ajouter_temp() )
    {
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Chaufage"),
                          QObject::tr("Chaufage ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

    }

    afficher(ui->tabchaufage);

}


// MODIFIER LCD
void Chaufage::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}

void Chaufage::on_dial_2_valueChanged(int value)
{
    ui->lcdNumber_2->display(value);
}
//MODIFIER BD

void Chaufage::on_dial_2_sliderReleased()
{
    tempc=ui->lcdNumber->value();

}

// SUPRESSION
bool Chaufage::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CHAUFAGE where IDC= :idc ");
query.bindValue(":idc", res);
return    query.exec();
}

void Chaufage::on_pb_supprimer_clicked()
{
    idc=ui->lineEdit_id_2->text().toInt();
   if(supprimer(idc))
   {
   QMessageBox::information(nullptr, QObject::tr("Supprimer un Chaufage"),
            QObject::tr("Chaufage supprimé.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
}

   afficher(ui->tabchaufage);
}


void Chaufage::on_pb_supprimer_2_clicked()
{
    int temp , id;
    id=ui->lineEdit_id_3->text().toInt();
    temp=ui->lcdNumber_2->value();

    if(modifier(id,temp)==true)
        QMessageBox::information(nullptr, QObject::tr("Modifier un chaufage"),
                    QObject::tr(" Chaufage modifié .\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    afficher(ui->tabchaufage);

}
QSqlQueryModel* Chaufage::stats()
{

    QSqlQueryModel *model =new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();

   query->prepare("SELECT ((SELECT SUM(TEMPC) FROM CHAUFAGE )/(SELECT COUNT(*)FROM CHAUFAGE )) FROM CHAUFAGE");
    query->exec();
    model->setQuery(*query);

    return model;
}

void Chaufage::on_pushButton_2_clicked()
{

makeplot(ui->ariya);


}

QVector<double> Chaufage::stat_ticks()
{
    QVector<double> t;
    QSqlQuery *ql=new QSqlQuery();
    double a=0;
    ql->prepare("SELECT COUNT(IDC) from CHAUFAGE ");
    ql->exec();
    while(ql->next())
    {a=ql->value(0).toDouble();}
    for(double i=0;i<a;i++)
    {
        t<<i+1;
    }
    return t;
}
void Chaufage::tri_stat_nom(QVector<double>& t1)
{
    QSqlQuery *ql=new QSqlQuery();
    double val1=0,val2=0,val3=0;
    QString ch=Q_NULLPTR;


        ql->prepare("SELECT COUNT(*) from CHAUFAGE WHERE TEMPC<20 ");
        //ql->prepare("SELECT COUNT(*) from CHAUFAGE WHERE TEMPC>=20 && TEMPC<40 ");
        //ql->prepare("SELECT COUNT(*) from CHAUFAGE WHERE TEMPC>=40  ");

            ql->exec();
            // ql->next();
            val1 = ql->size();
            qDebug() << "Msg Data " << " = " << val1 ;
            t1<<val1;
            ql->next();
            val2 = ql->value(1).toDouble();
            qDebug() << "Msg Data " << " = " << val2 ;
            t1<<val2;
            ql->next();
            val3 = ql->value(2).toDouble();
            qDebug() << "Msg Data " << " = " << val3 ;
            t1<<val3;

}


 void Chaufage::makeplot(QCustomPlot *customPlot)
{
    // set dark background gradient:
    customPlot->clearPlottables();
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->setBackground(QBrush(gradient));
    // create empty bar chart objects:
    QCPBars *vingt = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    vingt->setAntialiased(false); // gives more crisp, pixel aligned bar borders

    vingt->setStackingGap(1);

    // set names and colors:

    vingt->setName("Nombres de chaufages");
    vingt->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    vingt->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:

    // prepare x axis with country labels:
    QVector<double> ticks;
    ticks << 1  << 2  << 3  ;
    QVector<QString> labels  ;
    labels << "[0°-20°]" << "[20°-40°]" << "[40°-63°]" ;
    QVector<double> data;
    //tri_stat_nom(data);
    data << 5 << 3 << 8 ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(45);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 15);
    customPlot->yAxis->setPadding(5);
    customPlot->yAxis->setLabel("Nombres de chauffages");
    customPlot->xAxis->setLabel("Temperature");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    vingt->setData(ticks, data);


    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    vingt->setVisible(true);

    /*if(ui->comboBox_Stat_f->currentIndex()==2) //soixante
    {
    vingt->setVisible(false);
    quarante->setVisible(false);}
    if(ui->comboBox_Stat_f->currentIndex()==3) //vingt
    {
     quarante->moveAbove(vingt);
     soixante->moveAbove(quarante);
     soixante->setVisible(false);
     quarante->setVisible(false);}
    if(ui->comboBox_Stat_f->currentIndex()==4) //quarante
    {
     soixante->moveAbove(quarante);
     vingt->moveAbove(soixante);
     soixante->setVisible(false);
     vingt->setVisible(false);}*/
    customPlot->replot();
}

 void Chaufage::rechercher()
 {
     idc=ui->lineEdit->text().toInt();
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery* query=new QSqlQuery();
     query->prepare("Select * from CHAUFAGE where IDC=:id ");
     query->bindValue(":id",idc);
     query->exec();
     model->setQuery(*query);
     ui->tabchaufage->setModel(model);
     qDebug()<<(model->rowCount());
     if (model->rowCount()==0)
         QMessageBox::information(nullptr, QObject::tr("Rechercher un Chaufage "),
                     QObject::tr(" Le chaufage n'existe pas .\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


       else
         QMessageBox::information(nullptr, QObject::tr("Rechercher un chaufage "),
                     QObject::tr(" Le chaufage existe .\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


 }


void Chaufage::on_pushButton_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/son/flash.mp3")) ;
    music->play();

   rechercher();

}

void Chaufage::on_tabWidget_currentChanged(int index)
{

    afficher(ui->tabchaufage);
}
