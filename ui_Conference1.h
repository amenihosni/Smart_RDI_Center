/********************************************************************************
** Form generated from reading UI file 'Conference1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFERENCE1_H
#define UI_CONFERENCE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Conference1
{
public:
    QAction *actionAjouter_agent;
    QAction *actionchat_bot;
    QAction *actionAjouter_chercheur;
    QAction *actionlister_Chercheur;
    QAction *actionAjouter_Article;
    QAction *actionlister_Article;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_9;
    QLabel *label_logo_2;
    QTableView *tab_conference;
    QGroupBox *groupBox_2;
    QPushButton *supprimer2;
    QLineEdit *line_supprimer;
    QLabel *label_date_discreption_2;
    QGroupBox *groupBox_3;
    QPushButton *l_annee;
    QPushButton *le_mois;
    QGroupBox *groupBox_6;
    QPushButton *pdf;
    QPushButton *excel;
    QGroupBox *groupBox_9;
    QPushButton *op;
    QPushButton *pushButton_3;
    QPushButton *arret;
    QWidget *ajouter;
    QLabel *label_ac;
    QDateEdit *la_date;
    QLabel *label_date_discreption;
    QLineEdit *la_description;
    QLabel *label_date_description;
    QLabel *label_logo;
    QPushButton *confirmer;
    QLabel *label_date_description_3;
    QLineEdit *le_nom;
    QWidget *modifier;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QLabel *label_date_description_2;
    QLineEdit *lineEdit_adresse;
    QLabel *label;
    QLabel *label_logo_3;
    QPushButton *confirmer_modifier;
    QLineEdit *lineEdit_nom;
    QLabel *label_3;
    QDateEdit *dateEdit_conference;
    QLineEdit *lineEdit_num;
    QPushButton *video2;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QLineEdit *line_recherche;
    QPushButton *recherche;
    QTableView *table_recherche;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLineEdit *stat_annee;
    QWidget *tab_2;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox_5;
    QDateEdit *date_cc;
    QLabel *label_5;
    QLineEdit *line_calandrier;
    QLineEdit *adresse_calandrier;
    QWidget *tab_4;
    QGroupBox *groupBox_7;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *playPauseButton;
    QPushButton *PauseButton;
    QPushButton *stopButton;
    QWidget *tab_5;
    QGroupBox *groupBox_8;
    QTableView *historique_tab;
    QPushButton *historique_button;
    QLabel *label_6;
    QPushButton *retour;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Conference1)
    {
        if (Conference1->objectName().isEmpty())
            Conference1->setObjectName(QStringLiteral("Conference1"));
        Conference1->resize(1152, 778);
        Conference1->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.478, y1:0.505682, x2:1, y2:1, stop:0 rgba(23, 89, 152, 255), stop:1 rgba(255, 255, 255, 255));"));
        actionAjouter_agent = new QAction(Conference1);
        actionAjouter_agent->setObjectName(QStringLiteral("actionAjouter_agent"));
        actionchat_bot = new QAction(Conference1);
        actionchat_bot->setObjectName(QStringLiteral("actionchat_bot"));
        actionAjouter_chercheur = new QAction(Conference1);
        actionAjouter_chercheur->setObjectName(QStringLiteral("actionAjouter_chercheur"));
        actionlister_Chercheur = new QAction(Conference1);
        actionlister_Chercheur->setObjectName(QStringLiteral("actionlister_Chercheur"));
        actionAjouter_Article = new QAction(Conference1);
        actionAjouter_Article->setObjectName(QStringLiteral("actionAjouter_Article"));
        actionlister_Article = new QAction(Conference1);
        actionlister_Article->setObjectName(QStringLiteral("actionlister_Article"));
        centralwidget = new QWidget(Conference1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 70, 991, 611));
        tabWidget->setStyleSheet(QLatin1String("\n"
"QTabWidget::pane { /* The tab widget frame */\n"
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
"QTabWidget::scroller { /* the width of the scroll buttons */\n"
"    width: 20px;\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(260, 40, 201, 21));
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(87, 135, 181);"));
        label_logo_2 = new QLabel(tab);
        label_logo_2->setObjectName(QStringLiteral("label_logo_2"));
        label_logo_2->setGeometry(QRect(20, 20, 81, 61));
        label_logo_2->setStyleSheet(QLatin1String("    border-radius: 10px;\n"
"background-color: rgb(199, 215, 230);"));
        label_logo_2->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_logo_2->setScaledContents(true);
        label_logo_2->setWordWrap(false);
        label_logo_2->setMargin(0);
        tab_conference = new QTableView(tab);
        tab_conference->setObjectName(QStringLiteral("tab_conference"));
        tab_conference->setGeometry(QRect(10, 90, 621, 351));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 460, 611, 111));
        supprimer2 = new QPushButton(groupBox_2);
        supprimer2->setObjectName(QStringLiteral("supprimer2"));
        supprimer2->setGeometry(QRect(330, 80, 81, 21));
        supprimer2->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        line_supprimer = new QLineEdit(groupBox_2);
        line_supprimer->setObjectName(QStringLiteral("line_supprimer"));
        line_supprimer->setGeometry(QRect(100, 40, 241, 22));
        line_supprimer->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_date_discreption_2 = new QLabel(groupBox_2);
        label_date_discreption_2->setObjectName(QStringLiteral("label_date_discreption_2"));
        label_date_discreption_2->setGeometry(QRect(10, 40, 71, 21));
        label_date_discreption_2->setStyleSheet(QStringLiteral("background-color: rgb(196, 213, 229);"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(660, 50, 291, 141));
        l_annee = new QPushButton(groupBox_3);
        l_annee->setObjectName(QStringLiteral("l_annee"));
        l_annee->setGeometry(QRect(10, 60, 91, 28));
        l_annee->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        le_mois = new QPushButton(groupBox_3);
        le_mois->setObjectName(QStringLiteral("le_mois"));
        le_mois->setGeometry(QRect(180, 60, 93, 28));
        le_mois->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(650, 220, 301, 161));
        pdf = new QPushButton(groupBox_6);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(20, 70, 81, 31));
        pdf->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        excel = new QPushButton(groupBox_6);
        excel->setObjectName(QStringLiteral("excel"));
        excel->setGeometry(QRect(200, 80, 81, 31));
        excel->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        groupBox_9 = new QGroupBox(tab);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(640, 410, 321, 171));
        op = new QPushButton(groupBox_9);
        op->setObjectName(QStringLiteral("op"));
        op->setGeometry(QRect(70, 40, 91, 31));
        op->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        pushButton_3 = new QPushButton(groupBox_9);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 40, 91, 31));
        pushButton_3->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        arret = new QPushButton(groupBox_9);
        arret->setObjectName(QStringLiteral("arret"));
        arret->setGeometry(QRect(140, 120, 93, 28));
        arret->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        tabWidget->addTab(tab, QString());
        ajouter = new QWidget();
        ajouter->setObjectName(QStringLiteral("ajouter"));
        label_ac = new QLabel(ajouter);
        label_ac->setObjectName(QStringLiteral("label_ac"));
        label_ac->setGeometry(QRect(320, 50, 171, 41));
        label_ac->setStyleSheet(QStringLiteral("background-color: rgb(75, 126, 175);"));
        la_date = new QDateEdit(ajouter);
        la_date->setObjectName(QStringLiteral("la_date"));
        la_date->setGeometry(QRect(180, 180, 241, 21));
        la_date->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"color:white;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_date_discreption = new QLabel(ajouter);
        label_date_discreption->setObjectName(QStringLiteral("label_date_discreption"));
        label_date_discreption->setGeometry(QRect(30, 180, 81, 21));
        label_date_discreption->setStyleSheet(QLatin1String("background-color: rgb(145, 176, 206);\n"
""));
        la_description = new QLineEdit(ajouter);
        la_description->setObjectName(QStringLiteral("la_description"));
        la_description->setGeometry(QRect(180, 350, 241, 51));
        la_description->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_date_description = new QLabel(ajouter);
        label_date_description->setObjectName(QStringLiteral("label_date_description"));
        label_date_description->setGeometry(QRect(10, 370, 91, 21));
        label_date_description->setStyleSheet(QStringLiteral("background-color: rgb(58, 114, 168);"));
        label_logo = new QLabel(ajouter);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setGeometry(QRect(30, 20, 91, 71));
        label_logo->setStyleSheet(QLatin1String("    border-radius: 10px;\n"
"background-color: rgb(159, 186, 212);"));
        label_logo->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_logo->setScaledContents(true);
        label_logo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_logo->setWordWrap(false);
        label_logo->setMargin(0);
        label_logo->setIndent(-1);
        confirmer = new QPushButton(ajouter);
        confirmer->setObjectName(QStringLiteral("confirmer"));
        confirmer->setGeometry(QRect(520, 430, 81, 21));
        confirmer->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_date_description_3 = new QLabel(ajouter);
        label_date_description_3->setObjectName(QStringLiteral("label_date_description_3"));
        label_date_description_3->setGeometry(QRect(20, 270, 91, 21));
        label_date_description_3->setStyleSheet(QStringLiteral("background-color: rgb(77, 127, 176);"));
        le_nom = new QLineEdit(ajouter);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(180, 270, 241, 21));
        le_nom->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        tabWidget->addTab(ajouter, QString());
        label_logo->raise();
        label_ac->raise();
        la_date->raise();
        label_date_discreption->raise();
        la_description->raise();
        label_date_description->raise();
        confirmer->raise();
        label_date_description_3->raise();
        le_nom->raise();
        modifier = new QWidget();
        modifier->setObjectName(QStringLiteral("modifier"));
        scrollArea = new QScrollArea(modifier);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 911, 511));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 909, 509));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 180, 111, 21));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(124, 161, 197);"));
        label_date_description_2 = new QLabel(scrollAreaWidgetContents);
        label_date_description_2->setObjectName(QStringLiteral("label_date_description_2"));
        label_date_description_2->setGeometry(QRect(50, 340, 91, 21));
        label_date_description_2->setStyleSheet(QStringLiteral("background-color: rgb(56, 112, 166);"));
        lineEdit_adresse = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_adresse->setObjectName(QStringLiteral("lineEdit_adresse"));
        lineEdit_adresse->setGeometry(QRect(190, 320, 241, 61));
        lineEdit_adresse->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 20, 201, 21));
        label->setStyleSheet(QStringLiteral("background-color: rgb(87, 135, 181);"));
        label_logo_3 = new QLabel(scrollAreaWidgetContents);
        label_logo_3->setObjectName(QStringLiteral("label_logo_3"));
        label_logo_3->setGeometry(QRect(30, 10, 91, 61));
        label_logo_3->setAcceptDrops(false);
        label_logo_3->setStyleSheet(QLatin1String("    border-radius: 10px;\n"
"background-color: rgb(198, 214, 230);"));
        label_logo_3->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_logo_3->setScaledContents(true);
        label_logo_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_logo_3->setWordWrap(false);
        label_logo_3->setMargin(0);
        confirmer_modifier = new QPushButton(scrollAreaWidgetContents);
        confirmer_modifier->setObjectName(QStringLiteral("confirmer_modifier"));
        confirmer_modifier->setGeometry(QRect(660, 330, 91, 31));
        confirmer_modifier->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        lineEdit_nom = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(190, 250, 241, 22));
        lineEdit_nom->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 250, 101, 20));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(96, 141, 184);"));
        dateEdit_conference = new QDateEdit(scrollAreaWidgetContents);
        dateEdit_conference->setObjectName(QStringLiteral("dateEdit_conference"));
        dateEdit_conference->setGeometry(QRect(190, 180, 241, 22));
        dateEdit_conference->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"color:white;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        lineEdit_num = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_num->setObjectName(QStringLiteral("lineEdit_num"));
        lineEdit_num->setGeometry(QRect(190, 120, 241, 22));
        lineEdit_num->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        video2 = new QPushButton(scrollAreaWidgetContents);
        video2->setObjectName(QStringLiteral("video2"));
        video2->setGeometry(QRect(650, 250, 111, 31));
        video2->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(modifier, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 841, 261));
        line_recherche = new QLineEdit(groupBox);
        line_recherche->setObjectName(QStringLiteral("line_recherche"));
        line_recherche->setGeometry(QRect(40, 60, 231, 22));
        line_recherche->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        recherche = new QPushButton(groupBox);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(240, 110, 81, 31));
        recherche->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        table_recherche = new QTableView(groupBox);
        table_recherche->setObjectName(QStringLiteral("table_recherche"));
        table_recherche->setGeometry(QRect(470, 40, 351, 192));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 310, 851, 181));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 70, 71, 31));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(128, 164, 199);"));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 100, 91, 21));
        pushButton_2->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        stat_annee = new QLineEdit(groupBox_4);
        stat_annee->setObjectName(QStringLiteral("stat_annee"));
        stat_annee->setGeometry(QRect(130, 70, 211, 22));
        stat_annee->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        stat_annee->setMaxLength(2030);
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        calendarWidget = new QCalendarWidget(tab_2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(400, 50, 461, 401));
        calendarWidget->setStyleSheet(QLatin1String("*{font-size:18px;\n"
"color:rgb(180,180,180);\n"
"background-color:white;\n"
"selection-background-color:rgb(64,64,64);\n"
"selection-color:rgb(0,255,0);}"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 50, 361, 401));
        date_cc = new QDateEdit(groupBox_5);
        date_cc->setObjectName(QStringLiteral("date_cc"));
        date_cc->setGeometry(QRect(80, 90, 221, 22));
        date_cc->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"color:white;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_5 = new QLabel(groupBox_5);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 56, 16));
        line_calandrier = new QLineEdit(groupBox_5);
        line_calandrier->setObjectName(QStringLiteral("line_calandrier"));
        line_calandrier->setGeometry(QRect(40, 170, 261, 61));
        line_calandrier->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        adresse_calandrier = new QLineEdit(groupBox_5);
        adresse_calandrier->setObjectName(QStringLiteral("adresse_calandrier"));
        adresse_calandrier->setGeometry(QRect(40, 290, 271, 61));
        adresse_calandrier->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 10, 891, 461));
        verticalLayoutWidget = new QWidget(groupBox_7);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 20, 831, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        playPauseButton = new QPushButton(groupBox_7);
        playPauseButton->setObjectName(QStringLiteral("playPauseButton"));
        playPauseButton->setGeometry(QRect(20, 370, 93, 28));
        playPauseButton->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        PauseButton = new QPushButton(groupBox_7);
        PauseButton->setObjectName(QStringLiteral("PauseButton"));
        PauseButton->setGeometry(QRect(140, 370, 93, 28));
        PauseButton->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        stopButton = new QPushButton(groupBox_7);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setGeometry(QRect(260, 370, 93, 28));
        stopButton->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_8 = new QGroupBox(tab_5);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 40, 881, 391));
        historique_tab = new QTableView(groupBox_8);
        historique_tab->setObjectName(QStringLiteral("historique_tab"));
        historique_tab->setGeometry(QRect(440, 20, 421, 301));
        historique_button = new QPushButton(groupBox_8);
        historique_button->setObjectName(QStringLiteral("historique_button"));
        historique_button->setGeometry(QRect(160, 160, 93, 28));
        historique_button->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        tabWidget->addTab(tab_5, QString());
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, -10, 1161, 771));
        label_6->setPixmap(QPixmap(QString::fromUtf8("cto.jpg")));
        label_6->setScaledContents(true);
        retour = new QPushButton(centralwidget);
        retour->setObjectName(QStringLiteral("retour"));
        retour->setGeometry(QRect(20, 700, 101, 21));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans MT"));
        font.setPointSize(10);
        retour->setFont(font);
        retour->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        QIcon icon;
        icon.addFile(QStringLiteral("back.png"), QSize(), QIcon::Normal, QIcon::Off);
        retour->setIcon(icon);
        retour->setIconSize(QSize(27, 22));
        Conference1->setCentralWidget(centralwidget);
        label_6->raise();
        tabWidget->raise();
        retour->raise();
        menubar = new QMenuBar(Conference1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1152, 26));
        Conference1->setMenuBar(menubar);
        statusbar = new QStatusBar(Conference1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Conference1->setStatusBar(statusbar);

        retranslateUi(Conference1);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Conference1);
    } // setupUi

    void retranslateUi(QMainWindow *Conference1)
    {
        Conference1->setWindowTitle(QApplication::translate("Conference1", "MainWindow", Q_NULLPTR));
        actionAjouter_agent->setText(QApplication::translate("Conference1", "Ajouter agent", Q_NULLPTR));
        actionchat_bot->setText(QApplication::translate("Conference1", "chat bot", Q_NULLPTR));
        actionAjouter_chercheur->setText(QApplication::translate("Conference1", "Ajouter chercheur", Q_NULLPTR));
        actionlister_Chercheur->setText(QApplication::translate("Conference1", "lister Chercheur", Q_NULLPTR));
        actionAjouter_Article->setText(QApplication::translate("Conference1", "Ajouter Article", Q_NULLPTR));
        actionlister_Article->setText(QApplication::translate("Conference1", "lister Article", Q_NULLPTR));
        label_9->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; color:#ffffff;\">Conference</span></p></body></html>", Q_NULLPTR));
        label_logo_2->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Conference1", "supprimer", Q_NULLPTR));
        supprimer2->setText(QApplication::translate("Conference1", "supprimer", Q_NULLPTR));
        label_date_discreption_2->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; color:#ffffff;\">ID:</span></p></body></html>", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Conference1", "Trier :", Q_NULLPTR));
        l_annee->setText(QApplication::translate("Conference1", "Par ann\303\251e", Q_NULLPTR));
        le_mois->setText(QApplication::translate("Conference1", "Par mois", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Conference1", "Imprimer", Q_NULLPTR));
        pdf->setText(QApplication::translate("Conference1", "PDF", Q_NULLPTR));
        excel->setText(QApplication::translate("Conference1", "execel", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("Conference1", "conference", Q_NULLPTR));
        op->setText(QApplication::translate("Conference1", "conference", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Conference1", "sorti", Q_NULLPTR));
        arret->setText(QApplication::translate("Conference1", "Arret ", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Conference1", "Affiche conference", Q_NULLPTR));
        label_ac->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; color:#ffffff;\">Ajouter conference</span></p></body></html>", Q_NULLPTR));
        label_date_discreption->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ffffff;\">DATE :</span></p></body></html>", Q_NULLPTR));
        label_date_description->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ffffff;\">Adress :</span></p></body></html>", Q_NULLPTR));
        label_logo->setText(QString());
        confirmer->setText(QApplication::translate("Conference1", "confirmer", Q_NULLPTR));
        label_date_description_3->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ffffff;\">Nom :</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(ajouter), QApplication::translate("Conference1", "Ajouter confference", Q_NULLPTR));
        label_2->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ffffff;\">Date :</span></p></body></html>", Q_NULLPTR));
        label_date_description_2->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ffffff;\">Adress :</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; color:#ffffff;\">Modifier conference</span></p></body></html>", Q_NULLPTR));
        label_logo_3->setText(QString());
        confirmer_modifier->setText(QApplication::translate("Conference1", "confirmer", Q_NULLPTR));
        label_3->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ffffff;\">NOM :</span></p></body></html>", Q_NULLPTR));
        video2->setText(QApplication::translate("Conference1", "ajouter_video", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(modifier), QApplication::translate("Conference1", "Modifier", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Conference1", "Recherche", Q_NULLPTR));
        recherche->setText(QApplication::translate("Conference1", "chercher", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Conference1", "statistique ", Q_NULLPTR));
        label_4->setText(QApplication::translate("Conference1", "<html><head/><body><p align=\"center\"><span style=\" font-size:9pt; color:#ffffff;\">Annee :</span></p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Conference1", "Statitique", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Conference1", "statistique et Recherche", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("Conference1", "Date ", Q_NULLPTR));
        label_5->setText(QApplication::translate("Conference1", "Date :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Conference1", "Calandrier", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Conference1", "video", Q_NULLPTR));
        playPauseButton->setText(QApplication::translate("Conference1", "play", Q_NULLPTR));
        PauseButton->setText(QApplication::translate("Conference1", "pose", Q_NULLPTR));
        stopButton->setText(QApplication::translate("Conference1", "stop", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Conference1", "video", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Conference1", "Histoique", Q_NULLPTR));
        historique_button->setText(QApplication::translate("Conference1", "historique", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Conference1", "historique_visionnage", Q_NULLPTR));
        label_6->setText(QString());
        retour->setText(QApplication::translate("Conference1", "Retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Conference1: public Ui_Conference1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFERENCE1_H
