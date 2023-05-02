/********************************************************************************
** Form generated from reading UI file 'article1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLE1_H
#define UI_ARTICLE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_article1
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QPushButton *retourMenu_5;
    QPushButton *retourMenu_6;
    QLabel *label_2;
    QWidget *tab_2;
    QPushButton *ajouter;
    QLabel *label_6;
    QPushButton *retourMenu;
    QLineEdit *TITRE;
    QLineEdit *TEXTE;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *CHERCHEUR;
    QLabel *label_14;
    QPushButton *uploadbtn;
    QLabel *label_3;
    QPushButton *selectionnerChercheur;
    QWidget *tab;
    QLabel *label_15;
    QComboBox *bowTri;
    QScrollBar *verticalScrollBar;
    QTableView *affichage;
    QPushButton *retourMenu_2;
    QPushButton *triAlpha;
    QLabel *label_17;
    QPushButton *triAlphaDesc;
    QPushButton *triIdentifiant;
    QPushButton *telecharger;
    QLineEdit *RECHERCHER;
    QPushButton *boutonRech;
    QPushButton *statistiques;
    QLabel *label_4;
    QWidget *tab_4;
    QPushButton *modifbutton;
    QScrollBar *verticalScrollBar_3;
    QLineEdit *titremodif;
    QLineEdit *textemodif;
    QLineEdit *IDENTIFIANT;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *retourMenu_4;
    QPushButton *supprimer;
    QPushButton *qrcodepb;
    QLabel *qrcode;
    QLineEdit *chercheurmodif;
    QLabel *label_13;
    QWidget *tab_3;
    QLabel *label_16;
    QTableView *chercheurArticle;
    QLabel *label;
    QPushButton *retour;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *article1)
    {
        if (article1->objectName().isEmpty())
            article1->setObjectName(QStringLiteral("article1"));
        article1->resize(1179, 777);
        article1->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.478, y1:0.505682, x2:1, y2:1, stop:0 rgba(23, 89, 152, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralwidget = new QWidget(article1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(170, 80, 801, 621));
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
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        retourMenu_5 = new QPushButton(tab_5);
        retourMenu_5->setObjectName(QStringLiteral("retourMenu_5"));
        retourMenu_5->setGeometry(QRect(280, 220, 241, 51));
        QFont font;
        font.setPointSize(18);
        retourMenu_5->setFont(font);
        retourMenu_5->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        retourMenu_6 = new QPushButton(tab_5);
        retourMenu_6->setObjectName(QStringLiteral("retourMenu_6"));
        retourMenu_6->setGeometry(QRect(270, 300, 271, 51));
        retourMenu_6->setFont(font);
        retourMenu_6->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 20, 71, 71));
        label_2->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_2->setScaledContents(true);
        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        ajouter = new QPushButton(tab_2);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(580, 520, 75, 23));
        QFont font1;
        font1.setPointSize(12);
        ajouter->setFont(font1);
        ajouter->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 100, 541, 61));
        label_6->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        retourMenu = new QPushButton(tab_2);
        retourMenu->setObjectName(QStringLiteral("retourMenu"));
        retourMenu->setGeometry(QRect(100, 510, 131, 23));
        QFont font2;
        font2.setPointSize(10);
        retourMenu->setFont(font2);
        retourMenu->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        TITRE = new QLineEdit(tab_2);
        TITRE->setObjectName(QStringLiteral("TITRE"));
        TITRE->setGeometry(QRect(160, 180, 371, 41));
        TITRE->setFont(font1);
        TITRE->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        TEXTE = new QLineEdit(tab_2);
        TEXTE->setObjectName(QStringLiteral("TEXTE"));
        TEXTE->setGeometry(QRect(160, 250, 551, 181));
        TEXTE->setFont(font1);
        TEXTE->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 170, 71, 61));
        label_7->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 250, 81, 61));
        label_8->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        CHERCHEUR = new QLineEdit(tab_2);
        CHERCHEUR->setObjectName(QStringLiteral("CHERCHEUR"));
        CHERCHEUR->setGeometry(QRect(160, 460, 371, 41));
        CHERCHEUR->setFont(font1);
        CHERCHEUR->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 450, 141, 61));
        label_14->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        uploadbtn = new QPushButton(tab_2);
        uploadbtn->setObjectName(QStringLiteral("uploadbtn"));
        uploadbtn->setGeometry(QRect(470, 120, 151, 31));
        uploadbtn->setFont(font2);
        uploadbtn->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 20, 71, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_3->setScaledContents(true);
        selectionnerChercheur = new QPushButton(tab_2);
        selectionnerChercheur->setObjectName(QStringLiteral("selectionnerChercheur"));
        selectionnerChercheur->setGeometry(QRect(560, 470, 211, 23));
        selectionnerChercheur->setFont(font1);
        selectionnerChercheur->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(100, 40, 321, 71));
        label_15->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        bowTri = new QComboBox(tab);
        bowTri->setObjectName(QStringLiteral("bowTri"));
        bowTri->setGeometry(QRect(570, 70, 164, 31));
        bowTri->setFont(font2);
        bowTri->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"color:white;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color:white;\n"
" }"));
        verticalScrollBar = new QScrollBar(tab);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(770, 100, 16, 471));
        verticalScrollBar->setOrientation(Qt::Vertical);
        affichage = new QTableView(tab);
        affichage->setObjectName(QStringLiteral("affichage"));
        affichage->setGeometry(QRect(90, 150, 451, 331));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(affichage->sizePolicy().hasHeightForWidth());
        affichage->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(14);
        affichage->setFont(font3);
        retourMenu_2 = new QPushButton(tab);
        retourMenu_2->setObjectName(QStringLiteral("retourMenu_2"));
        retourMenu_2->setGeometry(QRect(80, 530, 131, 23));
        retourMenu_2->setFont(font2);
        retourMenu_2->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        triAlpha = new QPushButton(tab);
        triAlpha->setObjectName(QStringLiteral("triAlpha"));
        triAlpha->setGeometry(QRect(560, 60, 201, 41));
        triAlpha->setFont(font2);
        triAlpha->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_17 = new QLabel(tab);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(600, 30, 91, 21));
        QFont font4;
        font4.setPointSize(11);
        label_17->setFont(font4);
        label_17->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        triAlphaDesc = new QPushButton(tab);
        triAlphaDesc->setObjectName(QStringLiteral("triAlphaDesc"));
        triAlphaDesc->setGeometry(QRect(560, 110, 201, 41));
        triAlphaDesc->setFont(font2);
        triAlphaDesc->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        triIdentifiant = new QPushButton(tab);
        triIdentifiant->setObjectName(QStringLiteral("triIdentifiant"));
        triIdentifiant->setGeometry(QRect(560, 160, 201, 41));
        triIdentifiant->setFont(font2);
        triIdentifiant->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        telecharger = new QPushButton(tab);
        telecharger->setObjectName(QStringLiteral("telecharger"));
        telecharger->setGeometry(QRect(530, 520, 131, 23));
        telecharger->setFont(font2);
        telecharger->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        RECHERCHER = new QLineEdit(tab);
        RECHERCHER->setObjectName(QStringLiteral("RECHERCHER"));
        RECHERCHER->setGeometry(QRect(90, 100, 251, 41));
        RECHERCHER->setFont(font1);
        RECHERCHER->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        boutonRech = new QPushButton(tab);
        boutonRech->setObjectName(QStringLiteral("boutonRech"));
        boutonRech->setGeometry(QRect(350, 100, 151, 31));
        boutonRech->setFont(font2);
        boutonRech->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        statistiques = new QPushButton(tab);
        statistiques->setObjectName(QStringLiteral("statistiques"));
        statistiques->setGeometry(QRect(580, 380, 151, 31));
        statistiques->setFont(font2);
        statistiques->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 20, 71, 71));
        label_4->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        label_4->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        modifbutton = new QPushButton(tab_4);
        modifbutton->setObjectName(QStringLiteral("modifbutton"));
        modifbutton->setGeometry(QRect(530, 430, 191, 23));
        modifbutton->setFont(font2);
        modifbutton->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        verticalScrollBar_3 = new QScrollBar(tab_4);
        verticalScrollBar_3->setObjectName(QStringLiteral("verticalScrollBar_3"));
        verticalScrollBar_3->setGeometry(QRect(760, 50, 20, 431));
        verticalScrollBar_3->setOrientation(Qt::Vertical);
        titremodif = new QLineEdit(tab_4);
        titremodif->setObjectName(QStringLiteral("titremodif"));
        titremodif->setGeometry(QRect(190, 60, 371, 41));
        titremodif->setFont(font1);
        titremodif->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        textemodif = new QLineEdit(tab_4);
        textemodif->setObjectName(QStringLiteral("textemodif"));
        textemodif->setGeometry(QRect(190, 120, 371, 191));
        textemodif->setFont(font1);
        textemodif->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        IDENTIFIANT = new QLineEdit(tab_4);
        IDENTIFIANT->setObjectName(QStringLiteral("IDENTIFIANT"));
        IDENTIFIANT->setGeometry(QRect(190, 10, 371, 41));
        IDENTIFIANT->setFont(font1);
        IDENTIFIANT->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, 50, 61, 61));
        label_9->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 190, 101, 61));
        label_10->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        label_11 = new QLabel(tab_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 0, 141, 61));
        label_11->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        retourMenu_4 = new QPushButton(tab_4);
        retourMenu_4->setObjectName(QStringLiteral("retourMenu_4"));
        retourMenu_4->setGeometry(QRect(130, 430, 171, 31));
        retourMenu_4->setFont(font2);
        retourMenu_4->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        supprimer = new QPushButton(tab_4);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(380, 430, 121, 23));
        supprimer->setFont(font1);
        supprimer->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        qrcodepb = new QPushButton(tab_4);
        qrcodepb->setObjectName(QStringLiteral("qrcodepb"));
        qrcodepb->setGeometry(QRect(610, 90, 121, 23));
        qrcodepb->setFont(font1);
        qrcodepb->setStyleSheet(QLatin1String("*{color:white;\n"
"     border-radius: 10px;}\n"
"QPushButton:hover { \n"
"background-color: #81a6ce; }"));
        qrcode = new QLabel(tab_4);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setGeometry(QRect(600, 140, 150, 150));
        chercheurmodif = new QLineEdit(tab_4);
        chercheurmodif->setObjectName(QStringLiteral("chercheurmodif"));
        chercheurmodif->setGeometry(QRect(190, 340, 371, 41));
        chercheurmodif->setFont(font1);
        chercheurmodif->setStyleSheet(QLatin1String("*{  border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"    min-width: 10em;\n"
"  border-color: white;\n"
" }"));
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 330, 141, 61));
        label_13->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);"));
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(80, 60, 661, 71));
        label_16->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        chercheurArticle = new QTableView(tab_3);
        chercheurArticle->setObjectName(QStringLiteral("chercheurArticle"));
        chercheurArticle->setGeometry(QRect(170, 180, 451, 331));
        sizePolicy.setHeightForWidth(chercheurArticle->sizePolicy().hasHeightForWidth());
        chercheurArticle->setSizePolicy(sizePolicy);
        chercheurArticle->setFont(font3);
        tabWidget->addTab(tab_3, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-15, -5, 1191, 781));
        label->setPixmap(QPixmap(QString::fromUtf8("cto.jpg")));
        retour = new QPushButton(centralwidget);
        retour->setObjectName(QStringLiteral("retour"));
        retour->setGeometry(QRect(20, 660, 131, 41));
        QFont font5;
        font5.setFamily(QStringLiteral("Gill Sans MT"));
        font5.setPointSize(10);
        retour->setFont(font5);
        retour->setStyleSheet(QLatin1String("QPushButton:hover { background-color: #66c011; }\n"
"*{color:white;\n"
"     border-radius: 10px;}"));
        QIcon icon;
        icon.addFile(QStringLiteral("back.png"), QSize(), QIcon::Normal, QIcon::Off);
        retour->setIcon(icon);
        retour->setIconSize(QSize(27, 22));
        article1->setCentralWidget(centralwidget);
        label->raise();
        tabWidget->raise();
        retour->raise();
        statusbar = new QStatusBar(article1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        article1->setStatusBar(statusbar);

        retranslateUi(article1);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(article1);
    } // setupUi

    void retranslateUi(QMainWindow *article1)
    {
        article1->setWindowTitle(QApplication::translate("article1", "MainWindow", Q_NULLPTR));
        retourMenu_5->setText(QApplication::translate("article1", "Ajouter un article", Q_NULLPTR));
        retourMenu_6->setText(QApplication::translate("article1", "Afficher les articles", Q_NULLPTR));
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("article1", "Menu", Q_NULLPTR));
        ajouter->setText(QApplication::translate("article1", "Ajouter", Q_NULLPTR));
        label_6->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:26pt;\">Ajouter un article</span></p></body></html>", Q_NULLPTR));
        retourMenu->setText(QApplication::translate("article1", "< Retour \303\240 l'accueil", Q_NULLPTR));
        label_7->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:18pt;\">Titre</span></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:18pt;\">Corps</span></p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:18pt;\">Chercheur</span></p></body></html>", Q_NULLPTR));
        uploadbtn->setText(QApplication::translate("article1", "Upload", Q_NULLPTR));
        label_3->setText(QString());
        selectionnerChercheur->setText(QApplication::translate("article1", "Selectionner chercheur", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("article1", "Ajout", Q_NULLPTR));
        label_15->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:26pt; color:#ffffff;\">Articles</span></p></body></html>", Q_NULLPTR));
        bowTri->clear();
        bowTri->insertItems(0, QStringList()
         << QApplication::translate("article1", "Trier par..", Q_NULLPTR)
         << QApplication::translate("article1", "Titre", Q_NULLPTR)
         << QApplication::translate("article1", "Texte", Q_NULLPTR)
         << QApplication::translate("article1", "Identifiant", Q_NULLPTR)
        );
        retourMenu_2->setText(QApplication::translate("article1", "< Retour \303\240 l'accueil", Q_NULLPTR));
        triAlpha->setText(QApplication::translate("article1", "Ordre alphabetique", Q_NULLPTR));
        label_17->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:14pt; color:#ffffff;\">Trier par:</span></p></body></html>", Q_NULLPTR));
        triAlphaDesc->setText(QApplication::translate("article1", "Ordre alphabetique descendant", Q_NULLPTR));
        triIdentifiant->setText(QApplication::translate("article1", "Date d'ajout", Q_NULLPTR));
        telecharger->setText(QApplication::translate("article1", "Telecharger", Q_NULLPTR));
        boutonRech->setText(QApplication::translate("article1", "Rechercher", Q_NULLPTR));
        statistiques->setText(QApplication::translate("article1", "Statistiques", Q_NULLPTR));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("article1", "affichage", Q_NULLPTR));
        modifbutton->setText(QApplication::translate("article1", "Enregistrer les changements", Q_NULLPTR));
        label_9->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:18pt;\">Titre</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:18pt;\">Corps</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:18pt;\">Identifiant</span></p></body></html>", Q_NULLPTR));
        retourMenu_4->setText(QApplication::translate("article1", "< Retour \303\240 l'accueil", Q_NULLPTR));
        supprimer->setText(QApplication::translate("article1", "Supprimer", Q_NULLPTR));
        qrcodepb->setText(QApplication::translate("article1", "QR", Q_NULLPTR));
        qrcode->setText(QString());
        label_13->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:18pt;\">Chercheur</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("article1", "Modifier", Q_NULLPTR));
        label_16->setText(QApplication::translate("article1", "<html><head/><body><p><span style=\" font-size:26pt; color:#ffffff;\">Veuillez s\303\251lectionner un chercheur</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("article1", "Selection Chercheur", Q_NULLPTR));
        label->setText(QString());
        retour->setText(QApplication::translate("article1", "Retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class article1: public Ui_article1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLE1_H
