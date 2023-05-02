#include "article1.h"
#include "ui_article1.h"
#include "article.h"
#include <QDate>
#include <QMessageBox>
#include <QComboBox>
#include <QPixmap>
#include<iostream>
#include <QPainter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QSqlRecord>
#include <QTextDocument>
#include <QPdfWriter>
#include <QDebug>
#include <QSqlRecord>
#include <QDesktopServices>
#include <QUrl>
//CHARTS
#include <QtCharts>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
//END CHARTS
#include <QPrinter>
#include <QPrintDialog>

#include "chercheur.h"
#include "Chercheur1.h"
#include "qrcodegen.hpp"
#include "menu.h"
#include "ui_menu.h"
article1::article1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::article1)
{Chercheur C;
    ui->setupUi(this);
    ui->affichage->setModel(Atmp.afficher());
    ui->chercheurArticle->setModel(C.afficherChercheurArticle());

}

article1::~article1()
{
    delete ui;
}


void article1::on_ajouter_clicked()
{
        QString TITRE=ui->TITRE->text();
        QString TEXTE=ui->TEXTE->text();
        QString CHERCHEUR=ui->CHERCHEUR->text();
        Article a(TITRE, TEXTE,CHERCHEUR);
        if((TITRE.length()<255)&&(TITRE.length()>10)&&(TEXTE.length()<255)&&(TEXTE.length()>10))
        {
        bool test=a.ajouter();

        if(test) //si ajout effectué
            {
                //Refresh
                ui->affichage->setModel(Atmp.afficher());
                ui->tabWidget->setCurrentIndex(2);
                QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Ajout effectué.\n" "Appuyez CANCEL pout quitter."), QMessageBox::Cancel );
            }
            else //ajout echoue
                QMessageBox::critical(nullptr, QObject::tr("ECHEC"), QObject::tr("Ajout non effectué 2.\n" "Appuyez CANCEL pout quitter."), QMessageBox::Cancel );
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ECHEC"), QObject::tr("Ajout non effectue 1.\n" "Appuyez CANCEL pout quitter."), QMessageBox::Cancel );


        }


}


void article1::on_boutonRech_clicked()
{
    Article a1;
    a1.setid_article(ui->RECHERCHER->text().toInt());
          QSqlQueryModel *model = a1.rechercher(a1.getid_article());
    if(model != nullptr && model->rowCount() >= 1)
          {
        // Affichage des données dans un message box
                  QMessageBox::information(nullptr,QObject::tr("ok"),
                                          QObject::tr("Elements trouvés: %1")
                                          .arg(model->rowCount()),
                                          QMessageBox::Cancel ) ;
              // Affichage des données dans le table view
              ui->affichage->setModel(model);
    }
    else
          {
              QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                      QObject::tr("Pas d'article avec cet identifiant.\n"
                                                  "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel ) ;

          }
}


void article1::on_supprimer_clicked()
{
    int id=ui->IDENTIFIANT->text().toInt();
    QSqlQuery query;
        query.prepare("SELECT * FROM ARTICLES WHERE ID_ARTICLE = :id");
        query.bindValue(":id", id);
    if (query.exec() && query.next()) {
    bool test=Atmp.supprimer(id);
    if(test) //si supp effectuee
                {
                    //Refresh
                    ui->affichage->setModel(Atmp.afficher());
                    QMessageBox::information(nullptr, QObject::tr("Succès"), QObject::tr("Suppression effectuée.\n" "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel );
                }
                else //supp echoue
                    QMessageBox::critical(nullptr, QObject::tr("ECHEC"), QObject::tr("Suppression non effectuée.\n" "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel );
    }
    else {
            QMessageBox::warning(nullptr,QObject::tr("Avertissement"),
                QObject::tr("Pas d'article avec cet identifiant.\n"
                            "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel);}

}

void article1::on_triAlpha_clicked()
{
    ui->affichage->setModel(Atmp.afficherAlpha());
}

void article1::on_triAlphaDesc_clicked()
{
    ui->affichage->setModel(Atmp.afficherAlphaDesc());
}

void article1::on_triIdentifiant_clicked()
{
    ui->affichage->setModel(Atmp.afficherTriIden());
}

void article1::on_modifbutton_clicked()
{
    QString TITRE=ui->titremodif->text();
    QString TEXTE=ui->textemodif->text();
    QString CHERCHEUR=ui->chercheurmodif->text();
    int id=ui->IDENTIFIANT->text().toInt();
    Article a(TITRE, TEXTE,CHERCHEUR);
    if((TITRE.length()<255)&&(TITRE.length()>10)&&(TEXTE.length()<255)&&(TEXTE.length()>10))
    {
        bool test=a.modifier(id);

        if(test)
        {
            //Refresh
            ui->affichage->setModel(a.afficher());
            ui->tabWidget->setCurrentIndex(2);
            QMessageBox::information(nullptr,QObject::tr("Succès"),
                                    QObject::tr("Modification effectuée\n"
                                                "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel ) ;
        }
        else
           { QMessageBox::critical(nullptr,QObject::tr(" Not OK"),
                                    QObject::tr("Modification non effectuée\n"
                                                "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel ) ;


        }}
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ECHEC"), QObject::tr("Modification non effectuée.\n" "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel );


        }

}

void article1::on_affichage_activated(const QModelIndex &index)
{
    QString val=ui->affichage->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select ID_ARTICLE, TITRE, TEXTE, NOM_CHERCHEUR from ARTICLES where ID_ARTICLE='"+val+"'");
       if (qry.exec()){
           while(qry.next()){
               ui->IDENTIFIANT->setText(qry.value(0).toString());
               ui->titremodif->setText(qry.value(1).toString());
               ui->textemodif->setText(qry.value(2).toString());
               ui->chercheurmodif->setText(qry.value(3).toString());
           }

       }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Failed"),
                       QObject::tr("Veuillez selectionner par la case 'Identifiant article'.\n"
                                   "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel);
       }
    ui->tabWidget->setCurrentIndex(3);
}

void article1::on_retourMenu_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void article1::on_retourMenu_2_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void article1::on_retourMenu_4_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void article1::on_retourMenu_5_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void article1::on_retourMenu_6_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}


void article1::on_telecharger_clicked()
{
    QString strStream;
              QTextStream out(&strStream);

              const int rowCount = ui->affichage->model()->rowCount();
              const int columnCount = ui->affichage->model()->columnCount();

              out << "<html>\n"
                  "<head>\n"
                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                  "<title>Liste Des articles</title>\n"
                  "</head>\n"
                  "<body bgcolor=#8290c2 link=#5000A0>\n"
                  "<center><H1>Liste Des articles</H1></center>\n"
                  "<table border=1 cellspacing=0 cellpadding=2>\n";

              // headers
              out << "<thead><tr bgcolor=#f0f0f0><th>Numero</th>";
              for (int column = 0; column < columnCount; column++)
              {
                  if (!ui->affichage->isColumnHidden(column))
                  {
                      QString header = ui->affichage->model()->headerData(column, Qt::Horizontal).toString();
                      out << QString("<th>%1</th>").arg(header);
                  }
              }
              out << "</tr></thead>\n";

              // data table
              for (int row = 0; row < rowCount; row++)
              {
                  out << "<tr><td bkcolor=0>" << row + 1 << "</td>";
                  for (int column = 0; column < columnCount; column++)
                  {
                      if (!ui->affichage->isColumnHidden(column))
                      {
                          QString data = ui->affichage->model()->data(ui->affichage->model()->index(row, column)).toString().simplified();
                          out << QString("<td bkcolor=0>%1</td>").arg(data.isEmpty() ? "&nbsp;" : data);
                      }
                  }
                  out << "</tr>\n";
              }
              out << "</table>\n"
                  "</body>\n"
                  "</html>\n";

              QString fileName = QFileDialog::getSaveFileName(this, tr("Sauvegarder en PDF"), QString(), tr("PDF files (*.pdf)"));
              if (!fileName.isEmpty())
              {
                  if (QFileInfo(fileName).suffix().isEmpty())
                  {
                      fileName.append(".pdf");
                  }

                  QPrinter printer(QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                  printer.setPaperSize(QPrinter::A4);
                  printer.setOutputFileName(fileName);

                  QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size());
                  doc.print(&printer);
              }
}

void article1::on_qrcodepb_clicked()
{
    using namespace qrcodegen;
        // Get the text from the "TEXTE" box
        QString text = ui->textemodif->text();
        qDebug() << "Data to encode: " << text;
        // Generate the QR code
        QrCode qr = QrCode::encodeText(text.toUtf8().data(), QrCode::Ecc::MEDIUM);

        // Convert the QR code to an image
        qint32 sz = qr.getSize();
        QImage im(sz, sz, QImage::Format_RGB32);
        QRgb black = qRgb(0, 0, 0);
        QRgb white = qRgb(255, 255, 255);
        for (int y = 0; y < sz; y++) {
            for (int x = 0; x < sz; x++) {
                im.setPixel(x, y, qr.getModule(x, y) ? black : white);
            }
        }

        // Display the QR code image in the "qrcode" label
        ui->qrcode->setPixmap(QPixmap::fromImage(im.scaled(150, 150, Qt::KeepAspectRatio, Qt::FastTransformation), Qt::MonoOnly));
}

void article1::on_statistiques_clicked()
{
    Article *m_articles = new Article();
        // Créer un nouveau graphique à barres
        QChart *chart = new QChart();
        chart->setTitle("Statistiques");

        // Récupérer les données pour chaque chercheur
        QStringList chercheurs = m_articles->getDistinctChercheurs();
        QBarSeries *series = new QBarSeries();
        for (const QString &chercheur : chercheurs) {
            int nbArticles = m_articles->nbArticlesParChercheur(chercheur);
            QBarSet *set = new QBarSet(chercheur);
            *set << nbArticles;

            series->append(set);
        }
        // Ajouter la série au graphique
        chart->addSeries(series);

        // Définir les axes
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        QValueAxis *axisY = new QValueAxis();
        chart->setAxisY(axisY, series);
        axisX->setLabelsAngle(270);
        chart->legend()->setVisible(true);


        // Créer la vue pour afficher le graphique
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(400, 300);
        chartView->show();
}

void article1::on_uploadbtn_clicked()
{
    qDebug() << "Button clicked 1";
    QString filePath = QFileDialog::getOpenFileName(parentWidget(), "Open File", QDir::homePath());
    qDebug() << "Button clicked 2";

        // If the user cancelled, return
        if (filePath.isEmpty())
            return;

        // Read the file content and set it to the QLineEdit
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString text = in.readAll();
            ui->TEXTE->setText(text);
            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open file.");
        }
}

void article1::on_retour_clicked()
{
    this->hide();
       menu *f = new menu();
       f->show();
}

void article1::on_chercheurArticle_activated(const QModelIndex &index)
{
    QString val=ui->chercheurArticle->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select NOM_CHECHEUR from CHERCHEURS where ID_CHERCHEUR='"+val+"'");
           if (qry.exec()){
               while(qry.next()){
                   ui->CHERCHEUR->setText(qry.value(0).toString());
               }

           }
           else
           {
               QMessageBox::critical(nullptr, QObject::tr("Failed"),
                           QObject::tr("Veuillez selectionner par la case 'Identifiant article'.\n"
                                       "Appuyez sur Cancel pour quitter."), QMessageBox::Cancel);
           }
        ui->tabWidget->setCurrentIndex(1);
}

void article1::on_selectionnerChercheur_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}
