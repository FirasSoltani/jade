/********************************************************************************
** Form generated from reading UI file 'chaufage.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAUFAGE_H
#define UI_CHAUFAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chaufage
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_id;
    QPushButton *pb_ajouter;
    QDial *dial;
    QLCDNumber *lcdNumber;
    QWidget *tab_2;
    QTableView *tabchaufage;
    QPushButton *pushButton;
    QWidget *tab_3;
    QLineEdit *lineEdit_id_2;
    QLabel *label_4;
    QPushButton *pb_supprimer;
    QLabel *label_6;
    QWidget *tab_4;
    QLCDNumber *lcdNumber_2;
    QDial *dial_2;
    QLineEdit *lineEdit_id_3;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pb_supprimer_2;

    void setupUi(QDialog *Chaufage)
    {
        if (Chaufage->objectName().isEmpty())
            Chaufage->setObjectName(QStringLiteral("Chaufage"));
        Chaufage->resize(500, 300);
        tabWidget = new QTabWidget(Chaufage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 30, 371, 241));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 61, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 47, 13));
        lineEdit_id = new QLineEdit(tab);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(130, 30, 113, 20));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(290, 190, 75, 23));
        dial = new QDial(tab);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(100, 70, 91, 101));
        dial->setMaximum(63);
        dial->setPageStep(1);
        dial->setTracking(true);
        dial->setNotchTarget(0);
        lcdNumber = new QLCDNumber(tab);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(230, 100, 101, 51));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setDigitCount(2);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabchaufage = new QTableView(tab_2);
        tabchaufage->setObjectName(QStringLiteral("tabchaufage"));
        tabchaufage->setGeometry(QRect(10, 10, 341, 171));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 190, 75, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        lineEdit_id_2 = new QLineEdit(tab_3);
        lineEdit_id_2->setObjectName(QStringLiteral("lineEdit_id_2"));
        lineEdit_id_2->setGeometry(QRect(140, 30, 113, 20));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 30, 61, 16));
        pb_supprimer = new QPushButton(tab_3);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(240, 140, 75, 23));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 120, 47, 13));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        lcdNumber_2 = new QLCDNumber(tab_4);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(200, 70, 41, 81));
        lcdNumber_2->setFrameShape(QFrame::NoFrame);
        lcdNumber_2->setDigitCount(2);
        lcdNumber_2->setMode(QLCDNumber::Dec);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Filled);
        dial_2 = new QDial(tab_4);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setGeometry(QRect(120, 50, 61, 121));
        dial_2->setMaximum(63);
        dial_2->setPageStep(1);
        dial_2->setTracking(true);
        dial_2->setNotchTarget(0);
        lineEdit_id_3 = new QLineEdit(tab_4);
        lineEdit_id_3->setObjectName(QStringLiteral("lineEdit_id_3"));
        lineEdit_id_3->setGeometry(QRect(120, 20, 113, 20));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 20, 61, 16));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 90, 47, 13));
        pb_supprimer_2 = new QPushButton(tab_4);
        pb_supprimer_2->setObjectName(QStringLiteral("pb_supprimer_2"));
        pb_supprimer_2->setGeometry(QRect(250, 180, 75, 23));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Chaufage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Chaufage);
    } // setupUi

    void retranslateUi(QDialog *Chaufage)
    {
        Chaufage->setWindowTitle(QApplication::translate("Chaufage", "Dialog", nullptr));
        label->setText(QApplication::translate("Chaufage", "Identifiant", nullptr));
        label_2->setText(QApplication::translate("Chaufage", "Intensit\303\251", nullptr));
        pb_ajouter->setText(QApplication::translate("Chaufage", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Chaufage", "Ajouter", nullptr));
        pushButton->setText(QApplication::translate("Chaufage", "Reload", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Chaufage", "Afficher", nullptr));
        label_4->setText(QApplication::translate("Chaufage", "Identifiant", nullptr));
        pb_supprimer->setText(QApplication::translate("Chaufage", "Supprimer", nullptr));
        label_6->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Chaufage", "Supprimer", nullptr));
        label_3->setText(QApplication::translate("Chaufage", "Identifiant", nullptr));
        label_5->setText(QApplication::translate("Chaufage", "Intensit\303\251", nullptr));
        pb_supprimer_2->setText(QApplication::translate("Chaufage", "Modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Chaufage", "Modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chaufage: public Ui_Chaufage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAUFAGE_H
