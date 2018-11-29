#include "notification.h"
#include "ui_notification.h"

#include <QSystemTrayIcon>

notification::notification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notification)
{
    ui->setupUi(this);
    notifyIcon = new QSystemTrayIcon(this);
    notifyIcon->setIcon(QIcon("C:/Users/loume/Desktop/qt/icone.png"));

}

notification::~notification()
{
    delete ui;
}

void notification::on_pushButton_3_clicked()
{
    notifyIcon->show();
    QString titre = ui->lineEdit->text();
    QString texteMessage = ui->textEdit->toPlainText();
    qint8 duree = ui->spinBox->value();

    switch (ui->comboBox->currentIndex())
    {
    case 0 :
    notifyIcon -> showMessage(titre,texteMessage,QSystemTrayIcon::Information,duree);
    break;

    case 1 :
    notifyIcon -> showMessage(titre,texteMessage,QSystemTrayIcon::Warning,duree);
    break;

    case 2 :
    notifyIcon -> showMessage(titre,texteMessage,QSystemTrayIcon::Critical,duree);
    break;
    }
}
