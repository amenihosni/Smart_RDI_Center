#include "Equipement1.h"
#include "ui_Equipement1.h"
#include "equipements.h"
#include "smtp.h"
#include "arduino.h"

#include <QPrinter>

#include <QObject>
#include <QPushButton>

#include <QMessageBox>
#include<QDebug>
#include<QSqlRecord>
#include <QTextDocument>
#include<QTextFrame>
#include <QSqlQuery>
#include <QMessageBox>
#include<QTextTable>
#include<QtCharts>
#include<QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include<QAxObject>
#include <QPixmap>
#include "menu.h"
#include "ui_menu.h"
Equipement1::Equipement1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equipement1)
{
    equipements e ;
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
    QRegExp regex("[^0-9]*"); // Expression régulière pour accepter tous les caractères sauf les chiffres
       QValidator *validator = new QRegExpValidator(regex, this);
       ui->le_nom->setValidator(validator);
       ui->l_etet->setValidator(new QIntValidator(0,1,this));
       ui->le_prix->setValidator(new QIntValidator(0,999,this));
       ui->la_quantite->setValidator(new QIntValidator(0,999,this));
       int ret=A.connect_arduino(); // lancer la connexion à arduino
           switch(ret){
           case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
               break;
           case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
              break;
           case(-1):qDebug() << "arduino is not available";
           }

}

Equipement1::~Equipement1()
{
    delete ui;
}
void Equipement1::update_label()
{
    QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("AAAAAAAAAAAAAAAAA\n"
                                        "clické cancle to exit ."), QMessageBox::Cancel ) ;
data=A.read_from_arduino();
    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
    else if (data=="2")
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Modification effectué\n"
                                            "AAAAAAAAAAAAAAAAAAAAAAA."), QMessageBox::Cancel ) ;
        A.write_to_arduino("1");
        int idard=100;
        equipements e1(idard);

        bool test=e1.modifierArd(idard);
        if(test)
        {
            //Refreche
            ui->tableView->setModel(e.afficher());
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
}

void Equipement1::on_boutajouter_clicked()
{
    int QUANTITE=ui->la_quantite->text().toInt();
    int ETAT=ui->l_etet->text().toInt();
    float  PRIX=ui->le_prix->text().toInt();
    QString  NOM_EQ=ui->le_nom->text();
    QString  DOMAINE_EQUIPEMENTS=ui->le_domaine->text();
    equipements e(NOM_EQ,DOMAINE_EQUIPEMENTS,QUANTITE,PRIX,ETAT);

    // Ouvrir une boîte de dialogue de fichier pour sélectionner l'image
    QString imageFilePath = QFileDialog::getOpenFileName(this, "Sélectionner une image", "", "Fichiers d'image (*.bmp *.jpg *.jpeg *.png)");

    // Lire les données de l'image
    QFile imageFile(imageFilePath);
    imageFile.open(QIODevice::ReadOnly);
    QByteArray imageData = imageFile.readAll();
    imageFile.close();

    bool test=e.ajouter(imageData);


    // Insérer les données de l'image dans la base de données
    if(e.veriefier()){

        if(test)
        {
            //Refreche
           ui->tableView->setModel(e.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("Ajout effectué\n"
                                                "click cancle to exit ."), QMessageBox::Cancel ) ;
        }
        else
           { QMessageBox::critical(nullptr,QObject::tr(" Not ok"),
                                    QObject::tr("Ajout non effectué\n"
                                                "click cancle to exit ."), QMessageBox::Cancel ) ;
            }
    }
    else (QMessageBox::critical(nullptr,QObject::tr(" not ok"),
                                QObject::tr("vous devez respecter les regles d ajout ."), QMessageBox::Cancel ) );

    if(ui->l_etet->text()=='1')
    {
    Smtp* smtp = new Smtp("khamassioumaima6@gmail.com","vqazvfkfhacqjcmb", "smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("khamassioumaima6@gmail.com", "oumaima.khamassi@esprit.tn","Equipement en panne","ATTENTION !!! \nVous avez ajouté un équipement en panne");
       }


    QString nom=ui->le_nom->text();
    QSqlQuery query("SELECT image FROM EQUIPEMENT WHERE nom='"+nom+"'"); // Remplacer table_images par le nom de la table contenant l'image et 1 par l'ID de l'image à afficher
        if(query.next())
        {
            QByteArray imageData = query.value(0).toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            pixmap = pixmap.scaled(QSize(260, 260), Qt::KeepAspectRatio);

        // Afficher l'image dans une étiquette
        ui->label_10->setPixmap(pixmap);
        ui->label_10->show();
    }


    }


void Equipement1::on_boutsup_clicked()
{
    equipements e;
    int id=ui->supid->text().toInt();
    QSqlQuery query;
        query.prepare("SELECT * FROM EQUIPEMENT WHERE ID = :id");
        query.bindValue(":id", id);
        if (query.exec() && query.next()) {
        bool test=e.supprimer(ui->supid->text().toInt());
        if(test)
        {
            //Refreche
            ui->tableView->setModel(e.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("suppression avec succes\n"
                                                "clické cancle to exit ."), QMessageBox::Cancel ) ;
        }
        else
           {
            QMessageBox::critical(nullptr,QObject::tr(" Not ok"),
                                    QObject::tr("echec de suppression\n"
                                                "clické cancle to exit ."), QMessageBox::Cancel ) ;
        }}
        else {
                QMessageBox::warning(nullptr,QObject::tr("Avertissement"),
                    QObject::tr("L'ID de l'equipement n'existe pas.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);}
}

void Equipement1::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
     QSqlQuery qry ;
      qry.prepare("select  ID,DOMAINE,QUANTITE,ETAT,PRIX,NOM,IMAGE FROM EQUIPEMENT where ID='"+val+"'");
      if(qry.exec())
          while(qry.next())
          {   ui->le_nom_7->setText(qry.value(0).toString());
              ui->le_nom_2->setText(qry.value(2).toString());
              ui->le_nom_3->setText(qry.value(1).toString());
              ui->le_nom_4->setText(qry.value(5).toString());
              ui->le_nom_5->setText(qry.value(3).toString());
              ui->le_nom_6->setText(qry.value(4).toString());

                      QByteArray imageData = qry.value(6).toByteArray();
                      QPixmap pixmap;
                      pixmap.loadFromData(imageData);
                      pixmap = pixmap.scaled(QSize(260, 260), Qt::KeepAspectRatio);

                  // Afficher l'image dans une étiquette
                  ui->label_12->setPixmap(pixmap);
                  ui->label_12->show();
      }




}


void Equipement1::on_modif_clicked()
{
    int id=ui->le_nom_7->text().toInt();
        int PRIX= ui->le_nom_6->text().toInt();
        int ETAT=ui->le_nom_5->text().toInt();
        int QUANTITE=ui->le_nom_4->text().toInt();
        QString NOM_EQ=ui->le_nom_3->text();
        QString DOMAINE_EQUIPEMENTS=ui->le_nom_2->text();
        equipements e1(id,NOM_EQ,DOMAINE_EQUIPEMENTS,QUANTITE,PRIX,ETAT);

        bool test=e1.modifier();
        if(test)
        {
            //Refreche
            ui->tableView->setModel(e.afficher());
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


void Equipement1::on_boutrech_clicked()
{
    equipements e2;
    e2.seteid(ui->rech->text().toInt());
    e2.setnomeq(ui->rech->text());
    e2.setdomaineq(ui->rech->text());
    e2.setquantite(ui->rech->text().toInt());
    e2.setprix(ui->rech->text().toInt());
    e2.setetat(ui->rech->text().toInt());
    QSqlQueryModel *model = e2.recherche(e2.getid(), e2.getnomeq(), e2.getdomaineq(), e2.getetat());
    if(model != nullptr && model->rowCount() >= 1)
    {

        // Affichage des données dans un message box
        QString id = model->record(0).value("ID").toString();
        QString DOMAINE_EQUIPEMENTS = model->record(0).value("DOMAINE").toString();
        QString QUANTITE = model->record(0).value("QUANTITE").toString();
        QString ETAT = model->record(0).value("ETAT").toString();
        QString PRIX = model->record(0).value("PRIX,").toString();
        QString NOM_EQ = model->record(0).value("NOM,").toString();

        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Element trouvé:\n"
                                            "ID: %1\nNom: %2\nDOMAINE: %3\nDomaine: %4")
                                .arg(id).arg(NOM_EQ).arg(QUANTITE).arg(DOMAINE_EQUIPEMENTS).arg(ETAT).arg(PRIX),
                                QMessageBox::Cancel ) ;

        // Affichage des données dans le table view
        ui->tableView->setModel(model);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                QObject::tr("ECHEC!!\n"
                                            "click cancel to exit ."), QMessageBox::Cancel ) ;

    }
}




void Equipement1::on_triDes_clicked()
{
    equipements e;
    ui->tableView->setModel(e.TrierDesc());
}









void Equipement1::on_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out << "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << QString("<title>%1</title>\n").arg("strTitle")
        << "<style>\n"
        "h1 { color: #4169E1; text-decoration: underline;text-align: center; }\n"
        "table { border-collapse: collapse; width: 100%; }\n"
        "th, td { text-align: left; padding: 8px; }\n"
        "th { background-color: #4169E1; color: white; }\n"
        "tr:nth-child(even) { background-color: #f2f2f2; }\n"
        "</style>\n"
        "</head>\n"
        "<body>\n"
        "<div style=\"display:flex; justify-content:space-between; align-items:center;\">\n"
        "<div><img src=\"C:/Users/Oumayma/OneDrive/Bureau/equipementintr/logo.png\" width=\"100\" height=\"100\" /></div>\n"
        "<div style=\"text-align:right;\">\n"
        "<h1>Liste des Equipements</h1>\n"
        "</div>\n"
        "</div>\n"
        "<div>\n"
        "<table>\n";

    // headers
    out << "<thead><tr> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
    {
        QString header = ui->tableView->model()->headerData(column, Qt::Horizontal).toString();
        out << QString("<th>%1</th>").arg(header);
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
            out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
        }
        out << "</tr>\n";
    }
    out << "</table>\n"
        "</div>\n"
        "</body>\n"
        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget*)0, "Sauvegarder en PDF", QString(), "*.pdf");
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
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);

    QMessageBox::information(this, "PDF généré", QString("Le fichier PDF a été généré avec succès dans %1.").arg(fileName));
}




void Equipement1::on_exel_clicked()
{

    // Ouvrir une boîte de dialogue pour choisir le nom et l'emplacement du fichier Excel
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
        QAbstractItemModel* model = ui->tableView->model();

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




void Equipement1::on_stat_clicked()
{
    // Création d'une requête SQL pour compter le nombre d'états 0 et 1 dans la colonne correspondante
    QSqlQuery query("SELECT COUNT(*) FROM EQUIPEMENT WHERE etat=0");
    int count0 = 0;
    if (query.next()) {
        count0 = query.value(0).toInt();
    }

    query.prepare("SELECT COUNT(*) FROM EQUIPEMENT WHERE etat=1");
    int count1 = 0;
    if (query.exec() && query.next()) {
        count1 = query.value(0).toInt();
    }
    // Création du graphique en cercle
    QPieSeries *series = new QPieSeries();
    QPieSlice *slice0 = series->append("Etat 0 (" + QString::number(count0) + ")", count0);
    QPieSlice *slice1 = series->append("Etat 1 (" + QString::number(count1) + ")", count1);

    // Configuration des options du graphique en cercle
    slice0->setExploded(true);
    slice0->setLabelVisible(true);
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::darkCyan);
    slice1->setLabelVisible(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des états");
    chart->legend()->hide();

    // Affichage du graphique en cercle
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(400, 300);
    chartView->show();
}








void Equipement1::on_pushButton_20_clicked()
{

        ui->tabWidget->setCurrentIndex(0);
}


void Equipement1::on_botled_clicked()
{

    equipements e;
    data=A.read_from_arduino();
    bool ok;
    QString nom=e.rech(ui->le_nom_7->text().toInt(&ok));
    A.write_to_arduino("1");
    int idard=100;
    equipements e1(idard);

    bool test=e1.modifierArd(idard);
    if(test)
    {
        A.write_to_arduino1(nom);
        //Refreche
        ui->tableView->setModel(e.afficher());
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

void Equipement1::on_retour_clicked()
{
    this->hide();
       menu *f = new menu();
       f->show();
}
