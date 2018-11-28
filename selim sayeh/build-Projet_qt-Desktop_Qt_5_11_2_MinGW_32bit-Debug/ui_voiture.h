/********************************************************************************
** Form generated from reading UI file 'voiture.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOITURE_H
#define UI_VOITURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Voiture
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLineEdit *lineEdit_id;
    QPushButton *pb_ajouter;
    QWidget *tab_2;
    QTableView *tabvoit;
    QPushButton *pushButton;
    QWidget *tab_3;
    QLineEdit *lineEdit_id_2;
    QLabel *label_4;
    QPushButton *pb_supprimer;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QLineEdit *lineEditR;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Voiture)
    {
        if (Voiture->objectName().isEmpty())
            Voiture->setObjectName(QStringLiteral("Voiture"));
        Voiture->resize(500, 300);
        tabWidget = new QTabWidget(Voiture);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 30, 371, 241));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 61, 16));
        lineEdit_id = new QLineEdit(tab);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(130, 30, 113, 20));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(280, 170, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabvoit = new QTableView(tab_2);
        tabvoit->setObjectName(QStringLiteral("tabvoit"));
        tabvoit->setGeometry(QRect(10, 20, 341, 171));
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
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 311, 171));
        lineEditR = new QLineEdit(groupBox);
        lineEditR->setObjectName(QStringLiteral("lineEditR"));
        lineEditR->setGeometry(QRect(90, 40, 113, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 61, 16));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 120, 75, 23));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Voiture);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Voiture);
    } // setupUi

    void retranslateUi(QDialog *Voiture)
    {
        Voiture->setWindowTitle(QApplication::translate("Voiture", "Dialog", nullptr));
        label->setText(QApplication::translate("Voiture", "Identifiant", nullptr));
        pb_ajouter->setText(QApplication::translate("Voiture", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Voiture", "Ajouter", nullptr));
        pushButton->setText(QApplication::translate("Voiture", "Reload", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Voiture", "Afficher", nullptr));
        label_4->setText(QApplication::translate("Voiture", "Identifiant", nullptr));
        pb_supprimer->setText(QApplication::translate("Voiture", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Voiture", "Supprimer", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("Voiture", "Identifiant", nullptr));
        pushButton_2->setText(QApplication::translate("Voiture", "Rechercher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Voiture", "Rechercher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Voiture: public Ui_Voiture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOITURE_H
