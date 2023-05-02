/********************************************************************************
** Form generated from reading UI file 'Chercheur1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHERCHEUR1_H
#define UI_CHERCHEUR1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chercheur1
{
public:
    QWidget *centralwidget;
    QTabWidget *modifierchercheur;
    QWidget *tab_3;
    QLineEdit *le_nom_chercheur;
    QLineEdit *le_prenom_chercheur;
    QLabel *label;
    QPushButton *pb_ajout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *domaine_select;
    QLabel *label_23;
    QLabel *label_7;
    QPushButton *retour;
    QWidget *tab;
    QLabel *label_2;
    QLabel *label_8;
    QPushButton *pushButton_22;
    QGroupBox *groupBox;
    QLineEdit *le_id_supp;
    QLabel *label_18;
    QPushButton *pb_supprimer;
    QTableView *tableView;
    QLineEdit *le_recherche;
    QPushButton *pb_chercher;
    QPushButton *tri;
    QPushButton *tri_2;
    QPushButton *refrech;
    QPushButton *imprimer;
    QLabel *label_19;
    QLineEdit *le_id_chercheur_mod;
    QLineEdit *le_nom_chercheur_mod;
    QLineEdit *le_prenom_chercheur_mod;
    QComboBox *domaine_select_2;
    QPushButton *pb_modify;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QLabel *label_3;
    QPushButton *pdf;
    QPushButton *stastique;
    QPushButton *pushButton_21;
    QPushButton *excel;
    QLabel *label_14;
    QLabel *barcodeLabel;
    QWidget *tab_5;
    QListView *listView;
    QComboBox *comboBox;
    QLabel *label_13;
    QComboBox *comboBox_3;
    QPushButton *pb_supprimer_historique;
    QLabel *label_21;
    QLabel *label_16;
    QLabel *label_22;
    QLabel *label_24;
    QDateEdit *dateEdit;
    QWidget *tab_10;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QPushButton *opcionesPushButton;
    QFrame *frame;
    QLabel *label_20;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chercheur1)
    {
        if (Chercheur1->objectName().isEmpty())
            Chercheur1->setObjectName(QStringLiteral("Chercheur1"));
        Chercheur1->resize(1282, 788);
        Chercheur1->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.478, y1:0.505682, x2:1, y2:1, stop:0 rgba(23, 89, 152, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralwidget = new QWidget(Chercheur1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        modifierchercheur = new QTabWidget(centralwidget);
        modifierchercheur->setObjectName(QStringLiteral("modifierchercheur"));
        modifierchercheur->setGeometry(QRect(-20, 50, 2051, 1381));
        modifierchercheur->setStyleSheet(QLatin1String("QTabWidget::pane { /* The tab widget frame */\n"
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
"}\n"
"QTabWidget::scroller { /* the width\n"
"width: 20px;\n"
"}"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        le_nom_chercheur = new QLineEdit(tab_3);
        le_nom_chercheur->setObjectName(QStringLiteral("le_nom_chercheur"));
        le_nom_chercheur->setGeometry(QRect(530, 160, 161, 31));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans MT"));
        font.setPointSize(9);
        le_nom_chercheur->setFont(font);
        le_nom_chercheur->setStyleSheet(QStringLiteral("background-color: rgb(127, 182, 202);"));
        le_prenom_chercheur = new QLineEdit(tab_3);
        le_prenom_chercheur->setObjectName(QStringLiteral("le_prenom_chercheur"));
        le_prenom_chercheur->setGeometry(QRect(530, 220, 161, 31));
        le_prenom_chercheur->setFont(font);
        le_prenom_chercheur->setStyleSheet(QLatin1String("background-color: rgb(127, 182, 202);\n"
""));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 171, 151));
        label->setMinimumSize(QSize(171, 151));
        label->setStyleSheet(QStringLiteral("background-color: rgb(4, 4, 4);"));
        label->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        pb_ajout = new QPushButton(tab_3);
        pb_ajout->setObjectName(QStringLiteral("pb_ajout"));
        pb_ajout->setGeometry(QRect(720, 280, 131, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Gill Sans MT"));
        font1.setPointSize(10);
        pb_ajout->setFont(font1);
        pb_ajout->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon;
        icon.addFile(QStringLiteral("confirm.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_ajout->setIcon(icon);
        pb_ajout->setIconSize(QSize(27, 22));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 160, 81, 31));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(108, 150, 190);"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(390, 230, 81, 31));
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(82, 131, 178);"));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(790, 160, 81, 31));
        label_6->setStyleSheet(QStringLiteral("background-color: rgb(25, 91, 153);"));
        domaine_select = new QComboBox(tab_3);
        domaine_select->setObjectName(QStringLiteral("domaine_select"));
        domaine_select->setGeometry(QRect(900, 160, 171, 31));
        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(1050, 800, 171, 151));
        label_23->setMinimumSize(QSize(171, 151));
        label_23->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(9, 31, 51);\n"
"background-color: rgb(7, 18, 27);"));
        label_23->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Desktop/pic/logo.png")));
        label_23->setScaledContents(true);
        label_23->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 0, 1401, 761));
        label_7->setMinimumSize(QSize(171, 151));
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(4, 4, 4);"));
        label_7->setPixmap(QPixmap(QString::fromUtf8("cto.jpg")));
        label_7->setScaledContents(true);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        retour = new QPushButton(tab_3);
        retour->setObjectName(QStringLiteral("retour"));
        retour->setGeometry(QRect(40, 590, 131, 41));
        retour->setFont(font1);
        retour->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("back.png"), QSize(), QIcon::Normal, QIcon::Off);
        retour->setIcon(icon1);
        retour->setIconSize(QSize(27, 22));
        modifierchercheur->addTab(tab_3, QString());
        label_7->raise();
        le_nom_chercheur->raise();
        le_prenom_chercheur->raise();
        label->raise();
        pb_ajout->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        domaine_select->raise();
        label_23->raise();
        retour->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 171, 151));
        label_2->setMinimumSize(QSize(171, 151));
        label_2->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(5, 25, 26);"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_2->setScaledContents(true);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(540, 0, 81, 81));
        label_8->setStyleSheet(QStringLiteral("alternate-background-color: rgb(114, 154, 192);"));
        label_8->setPixmap(QPixmap(QString::fromUtf8("black-male-user-symbol.png")));
        label_8->setScaledContents(true);
        pushButton_22 = new QPushButton(tab);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(30, 840, 131, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Gill Sans MT"));
        font2.setPointSize(12);
        pushButton_22->setFont(font2);
        pushButton_22->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        pushButton_22->setIcon(icon1);
        pushButton_22->setIconSize(QSize(27, 22));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(970, 250, 281, 141));
        le_id_supp = new QLineEdit(groupBox);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(90, 40, 171, 21));
        le_id_supp->setStyleSheet(QLatin1String("QLineEdit{\n"
"    background-color: white;\n"
"    box-shadow: 2px 0.5px 5px 1px inset black;\n"
"    border-radius: 5px;\n"
"    width: 70%;\n"
"    padding-right: 10px;\n"
"    padding-left: 10px;\n"
"    text-align: left;\n"
"    color: #000;\n"
"    font-size:inherit;\n"
"    font-family: Arial, Helvetica, sans-serif;  \n"
"    font-weight:normal;\n"
"    font-variant:normal;\n"
"}\n"
"QLineEdit::hover{  color: black ;\n"
"background-color:orange;}\n"
"QLineEdit::focus{  color: black ;\n"
"background-color:white;}"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 40, 47, 14));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_18->setFont(font3);
        label_18->setStyleSheet(QStringLiteral("color: rgb(95, 63, 0);"));
        pb_supprimer = new QPushButton(groupBox);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(120, 80, 101, 31));
        pb_supprimer->setFont(font);
        pb_supprimer->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:black;\n"
"     border-radius: 10px;}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_supprimer->setIcon(icon2);
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(110, 150, 841, 491));
        tableView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_recherche = new QLineEdit(tab);
        le_recherche->setObjectName(QStringLiteral("le_recherche"));
        le_recherche->setGeometry(QRect(810, 60, 171, 31));
        le_recherche->setStyleSheet(QLatin1String("QLineEdit{\n"
"    background-color: white;\n"
"    box-shadow: 2px 0.5px 5px 1px inset black;\n"
"    border-radius: 5px;\n"
"    width: 70%;\n"
"    padding-right: 10px;\n"
"    padding-left: 10px;\n"
"    text-align: left;\n"
"    color: #000;\n"
"    font-size:inherit;\n"
"    font-family: Arial, Helvetica, sans-serif;  \n"
"    font-weight:normal;\n"
"    font-variant:normal;\n"
"}\n"
"QLineEdit::hover{  color: black ;\n"
"background-color:orange;}\n"
"QLineEdit::focus{  color: black ;\n"
"background-color:white;}"));
        pb_chercher = new QPushButton(tab);
        pb_chercher->setObjectName(QStringLiteral("pb_chercher"));
        pb_chercher->setGeometry(QRect(680, 60, 101, 31));
        pb_chercher->setFont(font);
        pb_chercher->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:black;\n"
"     border-radius: 10px;}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("loupe.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_chercher->setIcon(icon3);
        tri = new QPushButton(tab);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(250, 650, 91, 31));
        tri->setFont(font2);
        tri->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("fleche-vers-le-haut.png"), QSize(), QIcon::Normal, QIcon::Off);
        tri->setIcon(icon4);
        tri->setIconSize(QSize(27, 22));
        tri_2 = new QPushButton(tab);
        tri_2->setObjectName(QStringLiteral("tri_2"));
        tri_2->setGeometry(QRect(360, 650, 91, 31));
        tri_2->setFont(font2);
        tri_2->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("down-arrow (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        tri_2->setIcon(icon5);
        tri_2->setIconSize(QSize(27, 22));
        refrech = new QPushButton(tab);
        refrech->setObjectName(QStringLiteral("refrech"));
        refrech->setGeometry(QRect(180, 20, 101, 31));
        refrech->setFont(font2);
        refrech->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("icons8-repeat-100.png"), QSize(), QIcon::Normal, QIcon::Off);
        refrech->setIcon(icon6);
        refrech->setIconSize(QSize(27, 22));
        imprimer = new QPushButton(tab);
        imprimer->setObjectName(QStringLiteral("imprimer"));
        imprimer->setGeometry(QRect(780, 650, 111, 31));
        imprimer->setFont(font2);
        imprimer->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        imprimer->setIcon(icon7);
        imprimer->setIconSize(QSize(27, 22));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, -20, 1421, 791));
        label_19->setMinimumSize(QSize(171, 151));
        label_19->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(7, 18, 27);"));
        label_19->setPixmap(QPixmap(QString::fromUtf8("e8d389d64bd9a52b1747d74d5fb08935.jpg")));
        label_19->setScaledContents(true);
        label_19->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        le_id_chercheur_mod = new QLineEdit(tab);
        le_id_chercheur_mod->setObjectName(QStringLiteral("le_id_chercheur_mod"));
        le_id_chercheur_mod->setGeometry(QRect(780, 270, 161, 31));
        le_id_chercheur_mod->setFont(font);
        le_id_chercheur_mod->setStyleSheet(QStringLiteral("background-color: rgb(127, 182, 202);"));
        le_nom_chercheur_mod = new QLineEdit(tab);
        le_nom_chercheur_mod->setObjectName(QStringLiteral("le_nom_chercheur_mod"));
        le_nom_chercheur_mod->setGeometry(QRect(780, 330, 161, 31));
        le_nom_chercheur_mod->setFont(font);
        le_nom_chercheur_mod->setStyleSheet(QStringLiteral("background-color: rgb(127, 182, 202);"));
        le_prenom_chercheur_mod = new QLineEdit(tab);
        le_prenom_chercheur_mod->setObjectName(QStringLiteral("le_prenom_chercheur_mod"));
        le_prenom_chercheur_mod->setGeometry(QRect(780, 390, 161, 31));
        le_prenom_chercheur_mod->setFont(font);
        le_prenom_chercheur_mod->setStyleSheet(QLatin1String("background-color: rgb(127, 182, 202);\n"
""));
        domaine_select_2 = new QComboBox(tab);
        domaine_select_2->setObjectName(QStringLiteral("domaine_select_2"));
        domaine_select_2->setGeometry(QRect(770, 450, 171, 31));
        pb_modify = new QPushButton(tab);
        pb_modify->setObjectName(QStringLiteral("pb_modify"));
        pb_modify->setGeometry(QRect(810, 510, 121, 41));
        pb_modify->setFont(font);
        pb_modify->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:black;\n"
"     border-radius: 10px;}"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("modify.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_modify->setIcon(icon8);
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(770, 230, 171, 41));
        modifierchercheur->addTab(tab, QString());
        label_19->raise();
        label_2->raise();
        label_8->raise();
        pushButton_22->raise();
        groupBox->raise();
        tableView->raise();
        le_recherche->raise();
        pb_chercher->raise();
        tri->raise();
        tri_2->raise();
        refrech->raise();
        imprimer->raise();
        le_id_chercheur_mod->raise();
        le_nom_chercheur_mod->raise();
        le_prenom_chercheur_mod->raise();
        domaine_select_2->raise();
        pb_modify->raise();
        textEdit->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-10, 0, 171, 151));
        label_3->setMinimumSize(QSize(171, 151));
        label_3->setStyleSheet(QLatin1String("background-color:rgb(180, 202, 222);\n"
"background-color: rgb(124, 157, 173);\n"
"background-color: rgb(37, 48, 88);\n"
"background-color: rgb(37, 36, 57);"));
        label_3->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_3->setScaledContents(true);
        pdf = new QPushButton(tab_2);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(700, 200, 241, 61));
        QFont font4;
        font4.setFamily(QStringLiteral("Gill Sans MT"));
        font4.setPointSize(13);
        pdf->setFont(font4);
        pdf->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon9;
        icon9.addFile(QStringLiteral("pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon9);
        pdf->setIconSize(QSize(32, 29));
        stastique = new QPushButton(tab_2);
        stastique->setObjectName(QStringLiteral("stastique"));
        stastique->setGeometry(QRect(960, 360, 251, 61));
        stastique->setFont(font4);
        stastique->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("data.png"), QSize(), QIcon::Normal, QIcon::Off);
        stastique->setIcon(icon10);
        stastique->setIconSize(QSize(35, 33));
        pushButton_21 = new QPushButton(tab_2);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(10, 820, 131, 41));
        pushButton_21->setFont(font2);
        pushButton_21->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        pushButton_21->setIcon(icon1);
        pushButton_21->setIconSize(QSize(27, 22));
        excel = new QPushButton(tab_2);
        excel->setObjectName(QStringLiteral("excel"));
        excel->setGeometry(QRect(460, 360, 251, 61));
        excel->setFont(font4);
        excel->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("excel (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        excel->setIcon(icon11);
        excel->setIconSize(QSize(35, 33));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(-10, -90, 1461, 881));
        label_14->setMinimumSize(QSize(171, 151));
        label_14->setStyleSheet(QStringLiteral("background-color:rgb(180, 202, 222);"));
        label_14->setPixmap(QPixmap(QString::fromUtf8("securite-compresse.jpg")));
        label_14->setScaledContents(true);
        barcodeLabel = new QLabel(tab_2);
        barcodeLabel->setObjectName(QStringLiteral("barcodeLabel"));
        barcodeLabel->setGeometry(QRect(890, 620, 401, 61));
        modifierchercheur->addTab(tab_2, QString());
        label_14->raise();
        label_3->raise();
        pdf->raise();
        stastique->raise();
        pushButton_21->raise();
        excel->raise();
        barcodeLabel->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        listView = new QListView(tab_5);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(140, 90, 1001, 531));
        comboBox = new QComboBox(tab_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(940, 170, 16, 16));
        label_13 = new QLabel(tab_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(190, 20, 101, 16));
        QFont font5;
        font5.setFamily(QStringLiteral("Arial Black"));
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(10);
        label_13->setFont(font5);
        label_13->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        comboBox_3 = new QComboBox(tab_5);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(270, 50, 141, 22));
        comboBox_3->setStyleSheet(QStringLiteral(""));
        pb_supprimer_historique = new QPushButton(tab_5);
        pb_supprimer_historique->setObjectName(QStringLiteral("pb_supprimer_historique"));
        pb_supprimer_historique->setGeometry(QRect(960, 640, 101, 31));
        pb_supprimer_historique->setFont(font);
        pb_supprimer_historique->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:black;\n"
"     border-radius: 10px;}"));
        pb_supprimer_historique->setIcon(icon2);
        label_21 = new QLabel(tab_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(-150, -20, 1651, 811));
        label_21->setMinimumSize(QSize(171, 151));
        label_21->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(7, 18, 27);"));
        label_21->setPixmap(QPixmap(QString::fromUtf8("e8d389d64bd9a52b1747d74d5fb08935.jpg")));
        label_21->setScaledContents(true);
        label_21->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_16 = new QLabel(tab_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1000, 1110, 171, 151));
        label_16->setMinimumSize(QSize(171, 151));
        label_16->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(5, 25, 26);"));
        label_16->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_16->setScaledContents(true);
        label_22 = new QLabel(tab_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(1600, 1110, 171, 151));
        label_22->setMinimumSize(QSize(171, 151));
        label_22->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(5, 25, 26);"));
        label_22->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_22->setScaledContents(true);
        label_24 = new QLabel(tab_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(1390, 1110, 171, 151));
        label_24->setMinimumSize(QSize(171, 151));
        label_24->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(9, 31, 51);\n"
"background-color: rgb(7, 18, 27);"));
        label_24->setPixmap(QPixmap(QString::fromUtf8("../../OneDrive/Desktop/pic/logo.png")));
        label_24->setScaledContents(true);
        label_24->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        dateEdit = new QDateEdit(tab_5);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(1090, 640, 131, 31));
        dateEdit->setStyleSheet(QLatin1String("QDateEdit{\n"
"    background-color: white;\n"
"    box-shadow: 2px 0.5px 5px 1px inset black;\n"
"    border-radius: 5px;\n"
"    width: 70%;\n"
"    padding-right: 10px;\n"
"    padding-left: 10px;\n"
"    text-align: left;\n"
"    color: #000;\n"
"    font-size:inherit;\n"
"    font-family: Arial, Helvetica, sans-serif;  \n"
"    font-weight:normal;\n"
"    font-variant:normal;\n"
"}\n"
"QLineEdit::hover{  color: black ;\n"
"background-color:orange;}\n"
"QLineEdit::focus{  color: black ;\n"
"background-color:white;}"));
        modifierchercheur->addTab(tab_5, QString());
        label_21->raise();
        comboBox->raise();
        listView->raise();
        label_13->raise();
        comboBox_3->raise();
        pb_supprimer_historique->raise();
        label_16->raise();
        label_24->raise();
        label_22->raise();
        dateEdit->raise();
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        scrollArea = new QScrollArea(tab_10);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(310, 90, 741, 511));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 739, 509));
        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 0, 781, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-17, 20, 20, 491));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(770, 10, 20, 491));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(scrollAreaWidgetContents);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 500, 781, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        scrollArea->setWidget(scrollAreaWidgetContents);
        opcionesPushButton = new QPushButton(tab_10);
        opcionesPushButton->setObjectName(QStringLiteral("opcionesPushButton"));
        opcionesPushButton->setGeometry(QRect(450, 30, 441, 41));
        opcionesPushButton->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon12;
        icon12.addFile(QStringLiteral("camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        opcionesPushButton->setIcon(icon12);
        modifierchercheur->addTab(tab_10, QString());
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, -1, 1881, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(540, 120, 2141, 1331));
        label_20->setMinimumSize(QSize(171, 151));
        label_20->setStyleSheet(QLatin1String("background-color: rgb(180, 202, 222);\n"
"background-color: rgb(7, 18, 27);"));
        label_20->setPixmap(QPixmap(QString::fromUtf8("e8d389d64bd9a52b1747d74d5fb08935.jpg")));
        label_20->setScaledContents(true);
        label_20->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        Chercheur1->setCentralWidget(centralwidget);
        label_20->raise();
        frame->raise();
        modifierchercheur->raise();
        statusbar = new QStatusBar(Chercheur1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Chercheur1->setStatusBar(statusbar);

        retranslateUi(Chercheur1);

        modifierchercheur->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Chercheur1);
    } // setupUi

    void retranslateUi(QMainWindow *Chercheur1)
    {
        Chercheur1->setWindowTitle(QApplication::translate("Chercheur1", "MainWindow", Q_NULLPTR));
        le_nom_chercheur->setText(QString());
        le_prenom_chercheur->setText(QString());
        label->setText(QString());
        pb_ajout->setText(QApplication::translate("Chercheur1", "Confirmer", Q_NULLPTR));
        label_4->setText(QApplication::translate("Chercheur1", "Nom :", Q_NULLPTR));
        label_5->setText(QApplication::translate("Chercheur1", "Prenom :", Q_NULLPTR));
        label_6->setText(QApplication::translate("Chercheur1", "Domaine :", Q_NULLPTR));
        domaine_select->clear();
        domaine_select->insertItems(0, QStringList()
         << QApplication::translate("Chercheur1", "IA", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Reseau", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Securite", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "SE", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Quantique", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Graphique", Q_NULLPTR)
         << QString()
        );
        label_23->setText(QString());
        label_7->setText(QString());
        retour->setText(QApplication::translate("Chercheur1", "Retour", Q_NULLPTR));
        modifierchercheur->setTabText(modifierchercheur->indexOf(tab_3), QApplication::translate("Chercheur1", "ajouter_chercheur", Q_NULLPTR));
        label_2->setText(QString());
        label_8->setText(QString());
        pushButton_22->setText(QApplication::translate("Chercheur1", "Retour", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_18->setText(QApplication::translate("Chercheur1", "id", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("Chercheur1", "supprimer", Q_NULLPTR));
        pb_chercher->setText(QApplication::translate("Chercheur1", "Chercher", Q_NULLPTR));
        tri->setText(QApplication::translate("Chercheur1", "Trier ", Q_NULLPTR));
        tri_2->setText(QApplication::translate("Chercheur1", "Trier ", Q_NULLPTR));
        refrech->setText(QApplication::translate("Chercheur1", "Refrech", Q_NULLPTR));
        imprimer->setText(QApplication::translate("Chercheur1", "imprimer", Q_NULLPTR));
        label_19->setText(QString());
        le_id_chercheur_mod->setText(QString());
        le_nom_chercheur_mod->setText(QString());
        le_prenom_chercheur_mod->setText(QString());
        domaine_select_2->clear();
        domaine_select_2->insertItems(0, QStringList()
         << QApplication::translate("Chercheur1", "IA", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Reseau", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Securite", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "SE", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Quantique", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Graphique", Q_NULLPTR)
         << QString()
        );
        pb_modify->setText(QApplication::translate("Chercheur1", "modifier", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("Chercheur1", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt;\">Modification:</span></p></body></html>", Q_NULLPTR));
        modifierchercheur->setTabText(modifierchercheur->indexOf(tab), QApplication::translate("Chercheur1", "afficher_chercheur", Q_NULLPTR));
        label_3->setText(QString());
        pdf->setText(QApplication::translate("Chercheur1", "pdf", Q_NULLPTR));
        stastique->setText(QApplication::translate("Chercheur1", "statistique", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("Chercheur1", "Retour", Q_NULLPTR));
        excel->setText(QApplication::translate("Chercheur1", "Excel", Q_NULLPTR));
        label_14->setText(QString());
        barcodeLabel->setText(QString());
        modifierchercheur->setTabText(modifierchercheur->indexOf(tab_2), QApplication::translate("Chercheur1", "fonctionalit\303\251", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Chercheur1", "Tout", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Historique d'ajout", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Historique de suppression", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("Chercheur1", "Periode :", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Chercheur1", "Derni\303\250res 24 heures", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "7 derniers jours", Q_NULLPTR)
         << QApplication::translate("Chercheur1", "Toutes les donn\303\251es", Q_NULLPTR)
        );
        pb_supprimer_historique->setText(QApplication::translate("Chercheur1", "supprimer", Q_NULLPTR));
        label_21->setText(QString());
        label_16->setText(QString());
        label_22->setText(QString());
        label_24->setText(QString());
        modifierchercheur->setTabText(modifierchercheur->indexOf(tab_5), QApplication::translate("Chercheur1", "Historique", Q_NULLPTR));
        opcionesPushButton->setText(QApplication::translate("Chercheur1", "Options", Q_NULLPTR));
        modifierchercheur->setTabText(modifierchercheur->indexOf(tab_10), QApplication::translate("Chercheur1", "Camera", Q_NULLPTR));
        label_20->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Chercheur1: public Ui_Chercheur1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHERCHEUR1_H
