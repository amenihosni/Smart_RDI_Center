/********************************************************************************
** Form generated from reading UI file 'Equipement1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPEMENT1_H
#define UI_EQUIPEMENT1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Equipement1
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *la_quantite;
    QLabel *label_5;
    QLineEdit *l_etet;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *le_prix;
    QLabel *label_10;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *le_nom;
    QPushButton *boutajouter;
    QLineEdit *le_domaine;
    QPushButton *pushButton_4;
    QPushButton *retour;
    QWidget *tab;
    QLabel *label_4;
    QPushButton *pushButton_20;
    QLabel *label_31;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_32;
    QLineEdit *le_nom_2;
    QLineEdit *le_nom_3;
    QLineEdit *le_nom_4;
    QLineEdit *le_nom_5;
    QLineEdit *le_nom_6;
    QPushButton *modif;
    QLineEdit *le_nom_7;
    QLabel *label_33;
    QPushButton *botled;
    QWidget *tab_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QTableView *tableView;
    QPushButton *boutsup;
    QLineEdit *supid;
    QPushButton *boutrech;
    QLineEdit *rech;
    QPushButton *triDes;
    QLabel *label_34;
    QPushButton *pdf;
    QLabel *label_35;
    QLabel *label_36;
    QPushButton *exel;
    QLabel *label_37;
    QPushButton *stat;
    QLabel *label_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Equipement1)
    {
        if (Equipement1->objectName().isEmpty())
            Equipement1->setObjectName(QStringLiteral("Equipement1"));
        Equipement1->resize(835, 603);
        QIcon icon;
        icon.addFile(QStringLiteral("logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Equipement1->setWindowIcon(icon);
        Equipement1->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.478, y1:0.505682, x2:1, y2:1, stop:0 rgba(23, 89, 152, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralwidget = new QWidget(Equipement1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 20, 821, 491));
        tabWidget->setStyleSheet(QLatin1String("QTabWidget::pane { /* The tab widget frame */\n"
"    border-top: 2px solid #C2C7CB;\n"
"   border-color:white;\n"
"border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    min-width: 8ex;\n"
"padding: 2px;\n"
"    top: -0.5em;\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:hover {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"}"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 380, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 180, 91, 21));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        la_quantite = new QLineEdit(tab_3);
        la_quantite->setObjectName(QStringLiteral("la_quantite"));
        la_quantite->setGeometry(QRect(150, 180, 164, 22));
        la_quantite->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"	color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 51, 51));
        label_5->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background-color: rgb(199, 215, 230);"));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../331599580_882462219640948_7286103199684798722_n.png")));
        label_5->setScaledContents(true);
        l_etet = new QLineEdit(tab_3);
        l_etet->setObjectName(QStringLiteral("l_etet"));
        l_etet->setGeometry(QRect(150, 230, 164, 22));
        l_etet->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"	color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 230, 91, 21));
        label_7->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 280, 91, 21));
        label_8->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        le_prix = new QLineEdit(tab_3);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(150, 280, 164, 22));
        le_prix->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"	color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(490, 70, 251, 261));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../carte.jpg")));
        label_29 = new QLabel(tab_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(30, 130, 91, 21));
        label_29->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        label_30 = new QLabel(tab_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(30, 90, 91, 21));
        label_30->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        le_nom = new QLineEdit(tab_3);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(150, 90, 164, 22));
        le_nom->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"	color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        boutajouter = new QPushButton(tab_3);
        boutajouter->setObjectName(QStringLiteral("boutajouter"));
        boutajouter->setGeometry(QRect(440, 350, 93, 28));
        boutajouter->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        le_domaine = new QLineEdit(tab_3);
        le_domaine->setObjectName(QStringLiteral("le_domaine"));
        le_domaine->setGeometry(QRect(150, 130, 164, 22));
        le_domaine->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"	color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(670, 380, 93, 28));
        pushButton_4->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        retour = new QPushButton(tab_3);
        retour->setObjectName(QStringLiteral("retour"));
        retour->setGeometry(QRect(0, 380, 121, 31));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans MT"));
        font.setPointSize(10);
        retour->setFont(font);
        retour->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("back.png"), QSize(), QIcon::Normal, QIcon::Off);
        retour->setIcon(icon1);
        retour->setIconSize(QSize(27, 22));
        tabWidget->addTab(tab_3, QString());
        label_10->raise();
        pushButton_2->raise();
        label_2->raise();
        la_quantite->raise();
        label_5->raise();
        l_etet->raise();
        label_7->raise();
        label_8->raise();
        le_prix->raise();
        label_29->raise();
        label_30->raise();
        le_nom->raise();
        boutajouter->raise();
        le_domaine->raise();
        pushButton_4->raise();
        retour->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 51, 51));
        label_4->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background-color: rgb(199, 215, 230);"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../331599580_882462219640948_7286103199684798722_n.png")));
        label_4->setScaledContents(true);
        pushButton_20 = new QPushButton(tab);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(20, 380, 93, 28));
        pushButton_20->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_31 = new QLabel(tab);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(420, 100, 91, 21));
        label_31->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 240, 91, 21));
        label_3->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(420, 170, 91, 21));
        label_9->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(420, 240, 91, 21));
        label_11->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        label_32 = new QLabel(tab);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(60, 170, 91, 21));
        label_32->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        le_nom_2 = new QLineEdit(tab);
        le_nom_2->setObjectName(QStringLiteral("le_nom_2"));
        le_nom_2->setGeometry(QRect(190, 170, 164, 22));
        le_nom_2->setStyleSheet(QLatin1String("*{ \n"
"color:white;\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        le_nom_3 = new QLineEdit(tab);
        le_nom_3->setObjectName(QStringLiteral("le_nom_3"));
        le_nom_3->setGeometry(QRect(550, 100, 164, 22));
        le_nom_3->setStyleSheet(QLatin1String("*{ \n"
"color:white;\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        le_nom_4 = new QLineEdit(tab);
        le_nom_4->setObjectName(QStringLiteral("le_nom_4"));
        le_nom_4->setGeometry(QRect(190, 240, 164, 22));
        le_nom_4->setStyleSheet(QLatin1String("*{ \n"
"color:white;\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        le_nom_5 = new QLineEdit(tab);
        le_nom_5->setObjectName(QStringLiteral("le_nom_5"));
        le_nom_5->setGeometry(QRect(550, 170, 164, 22));
        le_nom_5->setStyleSheet(QLatin1String("*{ \n"
"color:white;\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        le_nom_6 = new QLineEdit(tab);
        le_nom_6->setObjectName(QStringLiteral("le_nom_6"));
        le_nom_6->setGeometry(QRect(550, 240, 164, 22));
        le_nom_6->setStyleSheet(QLatin1String("*{ \n"
"color:white;\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        modif = new QPushButton(tab);
        modif->setObjectName(QStringLiteral("modif"));
        modif->setGeometry(QRect(629, 341, 93, 28));
        modif->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        le_nom_7 = new QLineEdit(tab);
        le_nom_7->setObjectName(QStringLiteral("le_nom_7"));
        le_nom_7->setGeometry(QRect(190, 100, 164, 22));
        le_nom_7->setStyleSheet(QLatin1String("*{ \n"
"color:white;\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_33 = new QLabel(tab);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(60, 100, 91, 21));
        label_33->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        botled = new QPushButton(tab);
        botled->setObjectName(QStringLiteral("botled"));
        botled->setGeometry(QRect(520, 340, 93, 28));
        botled->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 51, 51));
        label->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background-color: rgb(199, 215, 230);"));
        label->setPixmap(QPixmap(QString::fromUtf8("../331599580_882462219640948_7286103199684798722_n.png")));
        label->setScaledContents(true);
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(580, 400, 93, 21));
        pushButton_3->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 80, 521, 231));
        tableView->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        boutsup = new QPushButton(tab_2);
        boutsup->setObjectName(QStringLiteral("boutsup"));
        boutsup->setGeometry(QRect(670, 340, 93, 28));
        boutsup->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        supid = new QLineEdit(tab_2);
        supid->setObjectName(QStringLiteral("supid"));
        supid->setGeometry(QRect(500, 340, 164, 22));
        supid->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        boutrech = new QPushButton(tab_2);
        boutrech->setObjectName(QStringLiteral("boutrech"));
        boutrech->setGeometry(QRect(500, 20, 93, 28));
        boutrech->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        rech = new QLineEdit(tab_2);
        rech->setObjectName(QStringLiteral("rech"));
        rech->setGeometry(QRect(600, 20, 164, 31));
        rech->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"	color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        triDes = new QPushButton(tab_2);
        triDes->setObjectName(QStringLiteral("triDes"));
        triDes->setGeometry(QRect(20, 360, 93, 28));
        triDes->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_34 = new QLabel(tab_2);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(20, 390, 91, 20));
        label_34->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
"color: rgb(255, 255, 255);\n"
""));
        pdf = new QPushButton(tab_2);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(250, 360, 93, 28));
        pdf->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_35 = new QLabel(tab_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(140, 390, 91, 20));
        label_35->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
"color: rgb(255, 255, 255);\n"
""));
        label_36 = new QLabel(tab_2);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(250, 390, 91, 20));
        label_36->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
"color: rgb(255, 255, 255);\n"
""));
        exel = new QPushButton(tab_2);
        exel->setObjectName(QStringLiteral("exel"));
        exel->setGeometry(QRect(350, 360, 93, 28));
        exel->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_37 = new QLabel(tab_2);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(350, 390, 91, 20));
        label_37->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
"color: rgb(255, 255, 255);\n"
""));
        stat = new QPushButton(tab_2);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(140, 360, 93, 28));
        stat->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(530, 70, 251, 261));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../carte.jpg")));
        tabWidget->addTab(tab_2, QString());
        Equipement1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Equipement1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 835, 26));
        Equipement1->setMenuBar(menubar);
        statusbar = new QStatusBar(Equipement1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Equipement1->setStatusBar(statusbar);

        retranslateUi(Equipement1);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Equipement1);
    } // setupUi

    void retranslateUi(QMainWindow *Equipement1)
    {
        Equipement1->setWindowTitle(QApplication::translate("Equipement1", "MainWindow", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Equipement1", "Retourner", Q_NULLPTR));
        label_2->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Quantit\303\251</span></p></body></html>", Q_NULLPTR));
        la_quantite->setText(QString());
        label_5->setText(QString());
        l_etet->setText(QString());
        label_7->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Etat</span></p><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Prix</span></p><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\"><br/></span></p></body></html>", Q_NULLPTR));
        le_prix->setText(QString());
        label_10->setText(QString());
        label_29->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Domaine<br/></span></p></body></html>", Q_NULLPTR));
        label_30->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Nom Eq</span></p></body></html>", Q_NULLPTR));
        le_nom->setText(QString());
        boutajouter->setText(QApplication::translate("Equipement1", "ajouter", Q_NULLPTR));
        le_domaine->setText(QString());
        pushButton_4->setText(QApplication::translate("Equipement1", "suivant", Q_NULLPTR));
        retour->setText(QApplication::translate("Equipement1", "Retour", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Equipement1", "Ajoutez equipement", Q_NULLPTR));
        label_4->setText(QString());
        pushButton_20->setText(QApplication::translate("Equipement1", "Retourner", Q_NULLPTR));
        label_31->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Nom Eq</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Quantit\303\251</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Etat</span></p><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Prix</span></p><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\"><br/></span></p></body></html>", Q_NULLPTR));
        label_32->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Domaine<br/></span></p></body></html>", Q_NULLPTR));
        modif->setText(QApplication::translate("Equipement1", "Modifier", Q_NULLPTR));
        label_33->setText(QApplication::translate("Equipement1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">ID</span></p></body></html>", Q_NULLPTR));
        botled->setText(QApplication::translate("Equipement1", "URGENT", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Equipement1", "Modifiez equipements", Q_NULLPTR));
        label->setText(QString());
        pushButton_3->setText(QApplication::translate("Equipement1", "Retourner", Q_NULLPTR));
        boutsup->setText(QApplication::translate("Equipement1", "Supprimer", Q_NULLPTR));
        boutrech->setText(QApplication::translate("Equipement1", "rechercher", Q_NULLPTR));
        triDes->setText(QApplication::translate("Equipement1", "tri Z-A", Q_NULLPTR));
        label_34->setText(QApplication::translate("Equipement1", "Trier % nom", Q_NULLPTR));
        pdf->setText(QApplication::translate("Equipement1", "download", Q_NULLPTR));
        label_35->setText(QApplication::translate("Equipement1", "% Etat eq", Q_NULLPTR));
        label_36->setText(QApplication::translate("Equipement1", "sous forme pdf", Q_NULLPTR));
        exel->setText(QApplication::translate("Equipement1", "download", Q_NULLPTR));
        label_37->setText(QApplication::translate("Equipement1", "sous forme exel", Q_NULLPTR));
        stat->setText(QApplication::translate("Equipement1", "stat", Q_NULLPTR));
        label_12->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Equipement1", "afficher equipements ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Equipement1: public Ui_Equipement1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPEMENT1_H
