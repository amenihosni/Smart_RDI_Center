#include "Conference1.h"
#include "ui_Conference1.h"
#include "conference.h"
#include<QPrinter>
#include <QAxObject>
#include <QFileDialog>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaRecorder>
#include <QCamera>
#include<QCameraViewfinder>
#include <QTcpServer>
#include <QAbstractAudioInput>
#include <QtCore/QObject>
#include <QtCore/QMetaObject>
#include "menu.h"
#include "ui_menu.h"
Conference1::Conference1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Conference1)
{
    ui->setupUi(this);
     //arduino
    int ret=a.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< a.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<a.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }

     QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
     c.set_nbr(0);
     c.ajout_nbr();
    ui->tab_conference->setModel(c.afficher());

    ui->lineEdit_num->hide();
    QRegExp regex("[^0-9]*"); // Expression régulière pour accepter tous les caractères sauf les chiffres
    QValidator *validator = new QRegExpValidator(regex, this);
    ui->le_nom->setValidator(validator);
    ui->stat_annee->setValidator(new QIntValidator(2023,2030,this));
  QDate dd=QDate::currentDate();
    int i=dd.year();

        for(int m=1;m<13;m++)
        {
            for( int j=1;j<32;j++)
            {
             c.afficher_date(i,m,j);
            QTextCharFormat format;
           format.setBackground(QBrush(Qt::yellow));
            format.setForeground(QBrush(Qt::black));
           ui->calendarWidget->setDateTextFormat(c.get_date(),format);
               }
           }







}

Conference1::~Conference1()
{
    delete ui;
}


void Conference1::on_confirmer_clicked()
{
    QDate date=ui->la_date->date();
    QString adresse=ui->la_description->text();
    QString nom=ui->le_nom->text();
    Conference c(date,adresse,nom);
    if(c.veriefier())
    {
    bool test=c.ajouter();
    if(test)
    {
        //Refreche
        ui->tab_conference->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Ajout effectué\n"
                                            "clické cancle to exit ."), QMessageBox::Cancel ) ;
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr(" Not ok"),
                                QObject::tr("Ajout non effectué\n"
                                            "clické cancle to exit ."), QMessageBox::Cancel ) ;


    }
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr(" not ok"),
                                        QObject::tr("probléme d'ajout aux nom ou adresse ."), QMessageBox::Cancel ) ;
    }

}
bool Conference1::verificationsys()
{
    // Sélectionner l'image secrète

       i.selectioneimage();
       QString nomImageSecrete = i.getnom();

       // Sélectionner toutes les images de la base de données
       QSqlQuery query("SELECT * FROM image");
       QListWidget listWidget;
       while (query.next()) {
           QByteArray imageData = query.value("image").toByteArray();
           QImage image = QImage::fromData(imageData);
           QPixmap pixmap = QPixmap::fromImage(image);
           pixmap = pixmap.scaled(QSize(5000, 5000), Qt::KeepAspectRatio, Qt::FastTransformation);
           QListWidgetItem *item = new QListWidgetItem(QIcon(pixmap),query.value(0).toString());
           item->setSizeHint(QSize(200,200));
           listWidget.addItem(item);
       }

       // Demander à l'utilisateur de choisir l'image qui correspond à l'image secrète
       listWidget.show();
       QMessageBox::information(nullptr, "Conference", QString("choisir l'image qui contient : %1").arg(i.getnom()), QMessageBox::Cancel);
       QEventLoop loop;
       QObject::connect(&listWidget, &QListWidget::itemClicked, &loop, &QEventLoop::quit);
       loop.exec();
       QString chosenImage = listWidget.currentItem()->text();

       // Vérifier si l'image choisie correspond à l'image secrète
       if (chosenImage == nomImageSecrete) {
           return true;
       }
       return false;
}
void Conference1::on_supprimer2_clicked()
{
   int id=ui->line_supprimer->text().toInt();


    c.setid(ui->line_supprimer->text().toInt());
    QSqlQuery query;
        query.prepare("SELECT * FROM CONFERENCES WHERE ID_CONFERENCE = :id");
        query.bindValue(":id",id);
        if (query.exec() && query.next()) {
       if(verificationsys()){
    bool test=c.supprimer(c.get_id());
    if(test)
    {
        //Refreche
        ui->tab_conference->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("suppression efectué\n"
                                            "clické cancle to exit ."), QMessageBox::Cancel ) ;
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr(" Not ok"),
                                QObject::tr("suppression non effectué\n"
                                            "clické cancle to exit ."), QMessageBox::Cancel ) ;
    }
       } else
       {  QMessageBox::critical(nullptr,QObject::tr(" Not ok"),
                                QObject::tr("vous avez  choisi une image incorrecte  \n"
                                            "clické cancle to exit ."), QMessageBox::Cancel ) ;
       }
        }
        else
        {
            QMessageBox::warning(nullptr,QObject::tr("Avertissement"),
                        QObject::tr("L'id  n'existe pas.\n"
                                    "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
}

void Conference1::on_tab_conference_activated(const QModelIndex &index)
{
  QString val=ui->tab_conference->model()->data(index).toString();
 QSqlQuery qry ;
  qry.prepare("select  ID_CONFERENCE,DATE_CONFERENCE, ADRESSE,NOM_CONF FROM CONFERENCES where ID_CONFERENCE='"+val+"'");
  if(qry.exec())
      while(qry.next())
      {   ui->lineEdit_num->setText(qry.value(0).toString());
          ui->dateEdit_conference->setDate(qry.value(1).toDate());
          ui->lineEdit_nom->setText(qry.value(3).toString());
           c.setid(qry.value(0).toInt());
          ui->lineEdit_adresse->setText(qry.value(2).toString());
         QByteArray bytes= c.lectureVideo(qry.value(0).toInt());
              if(!bytes.isEmpty()){
         QString tempFileName = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "/tempvideo.mp4";
         QFile tempFile(tempFileName);
         if (tempFile.open(QIODevice::WriteOnly)) {
             tempFile.write(bytes);
             tempFile.close();
         }

         QMediaPlayer* mediaPlayer = new QMediaPlayer(this);
         QVideoWidget* videoWidget = new QVideoWidget(this);
         mediaPlayer->setVideoOutput(videoWidget);

         QMediaContent mediaContent(QUrl::fromLocalFile(tempFileName));
         mediaPlayer->setMedia(mediaContent);

         ui->verticalLayout->addWidget(videoWidget);
         // Ajouter des boutons pour contrôler le son
           /* QPushButton* volumeUpButton = new QPushButton("+", this);
            QPushButton* volumeDownButton = new QPushButton("-", this);

            ui->verticalLayout->addWidget(volumeDownButton);
            ui->verticalLayout->addWidget(volumeUpButton);
*/
         QSlider* volumeSlider = new QSlider(Qt::Horizontal, this);
         volumeSlider->setMinimum(0);
         volumeSlider->setMaximum(100);
         ui->verticalLayout->addWidget(volumeSlider);
            // Connecter les signaux des boutons à des slots pour contrôler le son
            /*connect(volumeUpButton, &QPushButton::clicked, this, [=]() {
                mediaPlayer->setVolume(qMin(mediaPlayer->volume() + 10, 100));
            });
            connect(volumeDownButton, &QPushButton::clicked, this, [=]() {
                mediaPlayer->setVolume(qMax(mediaPlayer->volume() - 10, 0));
            });*/
         connect(volumeSlider, &QSlider::valueChanged, this, [=](int value) {
             mediaPlayer->setVolume(value);
         });
         // Connecter les signaux de clic des boutons à des slots qui contrôlent la vidéo
         connect(ui->playPauseButton, &QPushButton::clicked, mediaPlayer,&QMediaPlayer::play);
         connect(ui->PauseButton, &QPushButton::clicked, mediaPlayer,&QMediaPlayer::pause);
         connect(ui->stopButton, &QPushButton::clicked, mediaPlayer, &QMediaPlayer::stop);

         mediaPlayer->play();}
              }
  }



void Conference1::on_confirmer_modifier_clicked()
{   int id=ui->lineEdit_num->text().toInt();
    QDate date=ui->dateEdit_conference->date();
    QString nom=ui->lineEdit_nom->text();
    QString adresse=ui->lineEdit_adresse->text();
    Conference c(id,date,adresse,nom);
    if(c.veriefier())
    {
    bool test=c.modifier();

    if(test)
    {
        //Refreche
        ui->tab_conference->setModel(c.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Modification effectué\n"
                                            "clické cancle to exit ."), QMessageBox::Cancel ) ;
    }
    else
       { QMessageBox::critical(nullptr,QObject::tr(" Not ok"),
                                QObject::tr("Modification non effectué\n"
                                            "clické cancle to exit ."), QMessageBox::Cancel ) ;


    }
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr(" not ok"),
                                        QObject::tr("probléme d'ajout aux nom ou adresse ."), QMessageBox::Cancel ) ;
    }
   }




void Conference1::on_recherche_clicked()
{
  Conference C1;
      C1.setid(ui->line_recherche->text().toInt());
      C1.setnom(ui->line_recherche->text());
      C1.setadresse(ui->line_recherche->text());
      QSqlQueryModel *model = C1.recherche(C1.get_id(), C1.get_nom());
      if(model != nullptr && model->rowCount() >= 1)
      {
          // Affichage des données dans un message box
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                  QObject::tr("Elements trouvés: %1")
                                  .arg(model->rowCount()),
                                  QMessageBox::Cancel ) ;

          // Affichage des données dans le table view
          ui->table_recherche->setModel(model);
      }
      else
      {
          QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                  QObject::tr("ECHEC!!\n"
                                              "click cancel to exit ."), QMessageBox::Cancel ) ;

      }
}

void Conference1::on_l_annee_clicked()
{
    ui->tab_conference->setModel(c.tri());

}

void Conference1::on_le_mois_clicked()
{
     ui->tab_conference->setModel(c.tri_mois());
}

void Conference1::on_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_conference->model()->rowCount();
    const int columnCount = ui->tab_conference->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        << "<style>\n"
        "h1 { color: gray; }\n"
        "</style>\n"
        "</head>\n"
        "<body style=\"background-image: url(fun_vii_02.jpg); background-size: cover;\">\n"
        "<div style=\"display:flex; justify-content:space-between; align-items:center;\">\n"
        "<div><img src=\"C:/Users/benmr/Desktop/m4/logop.png\" width=\"100\" height=\"100\" /></div>\n"
        "<div style=\"text-align:right;\">\n"
           "<center> <h1 style=\"color:lightblue;margin-bottom:0px;\">Liste des conferences</h1></center>\n"
        "</div>\n"
        "</div>\n"
        "<div style=\"background-color: #f2f2f2; padding: 20px;\">\n"
        "<table border=1 cellspacing=0 cellpadding=2 style=\"background-color: #ffffff; margin: auto;\">\n";

    // headers
    out << "<thead><tr> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        QString header = ui->tab_conference->model()->headerData(column, Qt::Horizontal).toString();
        out << QString("<th>%1</th>").arg(header);
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            QString data = ui->tab_conference->model()->data(ui->tab_conference->model()->index(row, column)).toString().simplified();
            out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</div>\n"
        "</body>\n"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".pdf");
    }

    QPrinter printer (QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);

    QMessageBox::information(this, "PDF généré", QString("Le fichier PDF a été généré avec succès dans %1.").arg(fileName));
}

void Conference1::on_pushButton_2_clicked()
{
    int annee=ui->stat_annee->text().toInt();
    int i=0;
    // Récupérer les données pour chaque mois
       QBarSeries *series = new QBarSeries();
       for (int mois = 1; mois <= 12; mois++) {
          int  nombre_conferences=c.vstatic(mois,annee);
           // Ajout du nombre de conférences à la série de données
          if(nombre_conferences==0)
          {  i++;

          }else
           {QBarSet *barSet = new QBarSet(QDate::longMonthName(mois));
           *barSet << nombre_conferences;
           series->append(barSet);}
       }
       if(i==12)
       { QMessageBox::critical(nullptr, QObject::tr("pas de conference "),
                               QObject::tr("pour l'année :%1").arg(annee), QMessageBox::Cancel); } else {
       // Création de l'axe X pour le graphe
       QBarCategoryAxis *axisX = new QBarCategoryAxis();

       // Création de l'axe Y pour le graphe
       QValueAxis *axisY = new QValueAxis();
       axisY->setLabelFormat("%d");
       axisY->setRange(0, 10);

       // Création du graphique
       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Nombre de conférences par mois");
       chart->setAnimationOptions(QChart::SeriesAnimations);
       chart->createDefaultAxes();
       chart->setAxisX(axisX, series);
       chart->setAxisY(axisY, series);

       // Création de la vue pour afficher le graphique
       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

      // Création de la vue pour afficher le graphique

      chartView->setRenderHint(QPainter::Antialiasing);
      // Affichage de la vue
      chartView->resize(950,720);
      chartView->show();}

}


void Conference1::on_excel_clicked()
{// Ouvrir une boîte de dialogue pour choisir le nom et l'emplacement du fichier Excel
    QString filePath = QFileDialog::getSaveFileName(this, tr("Exporter les données"), QDir::homePath(), tr("Fichiers Excel (*.xlsx)"));

    // Si l'utilisateur annule la boîte de dialogue, quitter la fonction
    if (filePath.isEmpty()) {
        return;
    }

    // Créer un objet Excel
    QAxObject* excel = new QAxObject("Excel.Application", this);

    // Afficher l'application Excel
    excel->setProperty("Visible", true);

    // Créer un nouveau classeur Excel
    QAxObject* workbooks = excel->querySubObject("Workbooks");
    workbooks->dynamicCall("Add");

    // Obtenir une référence à la feuille de calcul active
    QAxObject* workbook = excel->querySubObject("ActiveWorkbook");
    QAxObject* sheets = workbook->querySubObject("Sheets");
    QAxObject* sheet = sheets->querySubObject("Item(int)", 1);

    // Obtenir une référence au modèle de données du TableView
    QAbstractItemModel* model = ui->tab_conference->model();

    // Écrire les en-têtes de colonnes dans la feuille de calcul
    for (int col = 0; col < model->columnCount(); ++col) {
        QVariant headerData = model->headerData(col, Qt::Horizontal, Qt::DisplayRole);
        QString header = headerData.toString();
        QAxObject* cell = sheet->querySubObject("Cells(int,int)", 1, col + 1);
        cell->setProperty("Value", header);

        // Appliquer un style aux en-têtes de colonnes
        QAxObject* font = cell->querySubObject("Font");
        font->setProperty("Bold", true);
        font->setProperty("Color", QColor(Qt::white));
        font->setProperty("Size", 12);
        QAxObject* interior = cell->querySubObject("Interior");
        interior->setProperty("Color", QColor(Qt::blue));
        interior->setProperty("Pattern", 1);
        QAxObject* borders = cell->querySubObject("Borders");
        borders->setProperty("LineStyle", 1);
        borders->setProperty("Weight", 2);
        borders->setProperty("Color", QColor(Qt::white));
    }

    // Écrire les données de chaque cellule dans la feuille de calcul
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col, QModelIndex());
            QVariant cellData = model->data(index, Qt::DisplayRole);
            QString cellText = cellData.toString();
            QAxObject* cell = sheet->querySubObject("Cells(int,int)", row + 2, col + 1);
            cell->setProperty("Value", cellText);

            // Appliquer un style aux cellules de données
            QAxObject* font = cell->querySubObject("Font");
            font->setProperty("Bold", false);
            font->setProperty("Color", QColor(Qt::black));
            font->setProperty("Size", 11);
            QAxObject* interior = cell->querySubObject("Interior");
            interior->setProperty("Color", QColor(Qt::white));
            QAxObject* borders = cell->querySubObject("Borders");
            borders->setProperty("LineStyle", 1);
            borders->setProperty("Weight", 2);
            borders->setProperty("Color", QColor(Qt::blue));
        }
    }

    // Ajuster la largeur des colonnes pour qu'elles correspondent aux données
    QAxObject* columns = sheet->querySubObject("Columns");
    columns->dynamicCall("AutoFit");

    // Enregistrer le classeur Excel
    workbook->dynamicCall("SaveAs(const QString&)", filePath);

    // Fermer le classeur Excel
    workbook->dynamicCall("Close()");

    // Fermer l'application Excel
    excel->dynamicCall("Quit()");

    // Détruire l'objet Excel
    delete excel;
}


void Conference1::on_calendarWidget_clicked(const QDate &date)
{
    c.afficher_nom(date);
   ui->date_cc->setDate(date);
   ui->line_calandrier->setText(c.get_nom());
    ui->adresse_calandrier->setText(c.get_adresse());
}



void Conference1::on_video2_clicked()
{
  int id=ui->lineEdit_num->text().toInt();
  // Ouvrir une boîte de dialogue de fichier pour sélectionner la vidéo
  QString videoFilePath = QFileDialog::getOpenFileName(this, "Sélectionner une vidéo", "", "Fichiers vidéo (*.avi)");

  // Lire les données de la vidéo
  QFile videoFile(videoFilePath);
  videoFile.open(QIODevice::ReadOnly);
  QByteArray videoData = videoFile.readAll();
  videoFile.close();
    c.insertionvideo(videoData,id);
}






void Conference1::on_PauseButton_clicked()
{
    QString dateTIME= QDateTime::currentDateTime().toString();
    c.historique(dateTIME);
}

void Conference1::on_historique_button_clicked()
{
    ui->historique_tab->setModel(c.afficherhistorique());
}
void Conference1::on_pushButton_3_clicked()
{
      a.write_to_arduino("1");
}



/*void Conference1::on_redemarer_clicked()
{
    a.write_to_arduino("3");
}*/
void Conference1::update_label()
{
  a.write_to_arduino(c.type_conference().toUtf8());
     QString data=a.read_from_arduino();
    if(data=="1")
 {
    if(d.chercher_visteur("e3e69c92"))
    {
        a.write_to_arduino(d.get_nom().toUtf8());
        n=c.sorty_nbr();
        n++;
        c.set_nbr(n);
        c.ajout_nbr();


 }

}
    else
    {

        qDebug() << "erreur0";
    }
}

void Conference1::on_arret_clicked()
{
    a.write_to_arduino("2");
}

void Conference1::on_op_clicked()
{
       d.afficher();
       d.exec();
}



void Conference1::on_retour_clicked()
{


    this->hide();
    menu *f = new menu();
    f->show();

}
