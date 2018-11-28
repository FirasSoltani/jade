/********************************************************************************
** Form generated from reading UI file 'temperature.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPERATURE_H
#define UI_TEMPERATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Temperature
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label1;
    QLabel *label_2;

    void setupUi(QDialog *Temperature)
    {
        if (Temperature->objectName().isEmpty())
            Temperature->setObjectName(QStringLiteral("Temperature"));
        Temperature->resize(500, 300);
        groupBox = new QGroupBox(Temperature);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 10, 411, 271));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 240, 131, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 240, 131, 23));
        label1 = new QLabel(groupBox);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(230, 0, 181, 231));
        label1->setPixmap(QPixmap(QString::fromUtf8("images/ventilateur.png")));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 30, 121, 181));
        label_2->setPixmap(QPixmap(QString::fromUtf8("images/chaufage.png")));

        retranslateUi(Temperature);

        QMetaObject::connectSlotsByName(Temperature);
    } // setupUi

    void retranslateUi(QDialog *Temperature)
    {
        Temperature->setWindowTitle(QApplication::translate("Temperature", "Dialog", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Temperature", "Gerer les chauffages", nullptr));
        pushButton_2->setText(QApplication::translate("Temperature", "Gerer les ventilateurs", nullptr));
        label1->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Temperature: public Ui_Temperature {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPERATURE_H
