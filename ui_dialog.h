/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *nom_arduino;
    QPushButton *sortie;
    QLabel *label_3;
    QLineEdit *prenom_arduino;
    QLineEdit *nombre_arduino;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1038, 721);
        Dialog->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.478, y1:0.505682, x2:1, y2:1, stop:0 rgba(23, 89, 152, 255), stop:1 rgba(255, 255, 255, 255));"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 60, 931, 551));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 191, 91));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 210, 201, 71));
        nom_arduino = new QLineEdit(groupBox);
        nom_arduino->setObjectName(QStringLiteral("nom_arduino"));
        nom_arduino->setGeometry(QRect(290, 101, 251, 31));
        nom_arduino->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        nom_arduino->setReadOnly(true);
        sortie = new QPushButton(groupBox);
        sortie->setObjectName(QStringLiteral("sortie"));
        sortie->setGeometry(QRect(710, 250, 121, 31));
        sortie->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 320, 221, 71));
        prenom_arduino = new QLineEdit(groupBox);
        prenom_arduino->setObjectName(QStringLiteral("prenom_arduino"));
        prenom_arduino->setGeometry(QRect(290, 231, 251, 31));
        prenom_arduino->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        prenom_arduino->setReadOnly(true);
        nombre_arduino = new QLineEdit(groupBox);
        nombre_arduino->setObjectName(QStringLiteral("nombre_arduino"));
        nombre_arduino->setGeometry(QRect(280, 341, 261, 31));
        nombre_arduino->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        nombre_arduino->setReadOnly(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "conference", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Nom de chercheur :</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Prenom de chercheur :</span></p></body></html>", Q_NULLPTR));
        sortie->setText(QApplication::translate("Dialog", "sortie", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">nombre de visteur :</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
