/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;
    QPushButton *pushButton_chercheur;
    QPushButton *pushButton_equipement;
    QPushButton *pushButton_agent;
    QPushButton *pushButton_article;
    QPushButton *pushButton_coference;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(1042, 746);
        menu->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.478, y1:0.505682, x2:1, y2:1, stop:0 rgba(23, 89, 152, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralwidget = new QWidget(menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-30, -30, 1081, 751));
        label->setPixmap(QPixmap(QString::fromUtf8("cto.jpg")));
        label->setScaledContents(true);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(750, -10, 301, 711));
        frame->setStyleSheet(QStringLiteral(" border-radius: 20px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 20, 151, 111));
        pushButton_chercheur = new QPushButton(frame);
        pushButton_chercheur->setObjectName(QStringLiteral("pushButton_chercheur"));
        pushButton_chercheur->setGeometry(QRect(70, 300, 151, 41));
        pushButton_chercheur->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        pushButton_equipement = new QPushButton(frame);
        pushButton_equipement->setObjectName(QStringLiteral("pushButton_equipement"));
        pushButton_equipement->setGeometry(QRect(70, 400, 151, 41));
        pushButton_equipement->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        pushButton_agent = new QPushButton(frame);
        pushButton_agent->setObjectName(QStringLiteral("pushButton_agent"));
        pushButton_agent->setGeometry(QRect(70, 200, 161, 41));
        pushButton_agent->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        pushButton_article = new QPushButton(frame);
        pushButton_article->setObjectName(QStringLiteral("pushButton_article"));
        pushButton_article->setGeometry(QRect(70, 510, 151, 41));
        pushButton_article->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        pushButton_coference = new QPushButton(frame);
        pushButton_coference->setObjectName(QStringLiteral("pushButton_coference"));
        pushButton_coference->setGeometry(QRect(70, 620, 151, 41));
        pushButton_coference->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(menu);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1042, 26));
        menu->setMenuBar(menubar);
        statusbar = new QStatusBar(menu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        menu->setStatusBar(statusbar);

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QMainWindow *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("menu", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#ffffff;\">RDI </span></p><p align=\"center\"><span style=\" font-size:16pt; color:#ffffff;\">CENTRE</span></p></body></html>", Q_NULLPTR));
        pushButton_chercheur->setText(QApplication::translate("menu", "Gestion_chercheur", Q_NULLPTR));
        pushButton_equipement->setText(QApplication::translate("menu", "Gestion_equipement", Q_NULLPTR));
        pushButton_agent->setText(QApplication::translate("menu", "Gestion_agent", Q_NULLPTR));
        pushButton_article->setText(QApplication::translate("menu", "Gestion_article", Q_NULLPTR));
        pushButton_coference->setText(QApplication::translate("menu", "Gestion_conference", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
