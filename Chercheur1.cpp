#include "Chercheur1.h"
#include "ui_Chercheur1.h"
#include "chercheur.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QChartView>
#include<QtCharts>
#include <QBarSet>
#include <QtPrintSupport/QPrinter>
#include <QAxObject>
#include <QFileDialog>
#include <QSqlError>
#include <QtWidgets>
#include <QLabel>
//#include<QQuickWidget>
#include <QNetworkAccessManager>
#include <QVBoxLayout>
#include <ActiveQt/QAxWidget>
#include <QDialog>
#include <QMetaObject>
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QPrinter>
#include <QPdfWriter>
#include <QTextEdit>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QDesktopServices>
#include <QUrl>
#include <QCameraViewfinder>
#include <QSqlTableModel>
#include <QImage>
#include "menu.h"
#include "ui_menu.h"
#include <QByteArray>

Chercheur1::Chercheur1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Chercheur1)

{ui->setupUi(this);

 ui->tableView->setModel(C.afficher());
ui->le_id_chercheur_mod->hide();



//affichage historique
QSqlQueryModel * model = afficherHistorique("");
 //afficherHistorique();
    ui->listView->setModel(model);

    if (model->lastError().isValid()) {
        qDebug() << "Error executing query: " << model->lastError().text();
    } else {
        qDebug() << "Query executed successfully.";
    }

//camera
    mCamera = new QCamera(this);
    CameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);

    mLayout = new QVBoxLayout;
    mOpcionesMenu = new QMenu("Allumer", this);
    mEncenderAction = new QAction("Ouvrir", this);
    mApagarAction = new QAction("Eteindre", this);
    mCapturarAction = new QAction("Capturer", this);

    mOpcionesMenu->addActions({mEncenderAction, mApagarAction, mCapturarAction});
    ui->opcionesPushButton->setMenu(mOpcionesMenu);

    mCamera->setViewfinder(CameraViewfinder);

    mLayout->addWidget(CameraViewfinder);
    mLayout->setMargin(0);

    ui->scrollArea->setLayout(mLayout);

    connect(mEncenderAction, &QAction::triggered, [&]() {
        mCamera->start();
    });

    connect(mApagarAction, &QAction::triggered, [&]() {
        mCamera->stop();
    });

    connect(mCapturarAction, &QAction::triggered, [&]() {
        auto filename = QFileDialog::getSaveFileName(this, "Capturer", "/", "Imagen (*.jpg;*.jpeg)");
        if (filename.isEmpty()) {
            return;
        }
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();

        // Enregistrement de l'image dans la base de données
        QByteArray byteArray;
        QString imagePath = filename;
        QSqlQuery query;

        QVariant imageVariant(byteArray);

        QByteArray imageData; // your image data
        int chercheurId; // your chercheur ID
        query.prepare("UPDATE chercheurs SET image = :image WHERE ID_CHERCHEUR = :id");
        query.bindValue(":id", chercheurId);
        query.bindValue(":image", QVariant::fromValue<QByteArray>(imageData));
        query.exec();




    });


    //code à barre
    // Create a list of conferences
        QList<Conference> conferences;
        Conference myConference;
        myConference.name = "conférence IA";
        myConference.date = QDate(2023, 6, 15);
        myConference.location = "Tunis, ariena";
        conferences.append(myConference);

        // Generate the barcode image
        QImage barcodeImage = generateBarcode(conferences);

        // Display the barcode image in a label
        QPixmap barcodePixmap = QPixmap::fromImage(barcodeImage);
        ui->barcodeLabel->setPixmap(barcodePixmap);


}

Chercheur1::~Chercheur1()
{
    delete ui;

}



void Chercheur1::on_pb_ajout_clicked()
{
    QString nom_chercheur = ui->le_nom_chercheur->text();
    QString prenom_chercheur = ui->le_prenom_chercheur->text();
    QString domaine = ui->domaine_select->currentText();

    bool valid_nom = true;
    bool valid_prenom = true;

    // Validation du champ nom_chercheur
    if (nom_chercheur.isEmpty() || nom_chercheur.length() < 3 || nom_chercheur.contains(QRegExp("[0-9]")) || nom_chercheur.contains(QRegExp("[^A-Za-z0-9 ]"))) {
        ui->le_nom_chercheur->setText("Nom invalide");
        valid_nom = false;
    } else {
        ui->le_nom_chercheur->setText("");
    }

    // Validation du champ prenom_chercheur
    if (prenom_chercheur.isEmpty() || prenom_chercheur.length() < 3 || prenom_chercheur.contains(QRegExp("[0-9]")) || prenom_chercheur.contains(QRegExp("[^A-Za-z0-9 ]"))) {
        ui->le_prenom_chercheur->setText("Prénom invalide");
        valid_prenom = false;
    } else {
        ui->le_prenom_chercheur->setText("");
    }

    // Ajout seulement si les champs nom et prénom ne sont pas vides
    if (nom_chercheur.isEmpty() || prenom_chercheur.isEmpty()) {
        QMessageBox::warning(nullptr, QObject::tr("Attention"),
                              QObject::tr("Les champs nom et prénom doivent être remplis.\n"
                                          "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }

    else if (valid_nom && valid_prenom) {
        QSqlQuery query;
        query.prepare("SELECT NOM_CHECHEUR, PRENOM_CHERCHEUR, DOMAINE FROM chercheurs WHERE NOM_CHECHEUR=:nom AND PRENOM_CHERCHEUR=:prenom AND DOMAINE=:domaine");
        query.bindValue(":nom", nom_chercheur);
        query.bindValue(":prenom", prenom_chercheur);
        query.bindValue(":domaine", domaine);
            Chercheur C(nom_chercheur, prenom_chercheur, domaine);
            bool test = C.ajouter();
            if (test) {
                // Rafraîchissement de la vue
                ui->tableView->setModel(C.afficher());

                QMessageBox::information(nullptr, QObject::tr("ok"),
                                         QObject::tr("Ajout effectué\n"
                                                     "click cancel to exit ."), QMessageBox::Cancel);
            } else {
                QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                                       QObject::tr("Ajout non effectué\n"
                                                   "click cancel to exit ."), QMessageBox::Cancel);
            }
        }
     ui->listView->setModel(afficherHistorique(""));
    }




void Chercheur1::on_pb_supprimer_clicked()
{
    Chercheur C1;
    C1.setid(ui->le_id_supp->text().toInt());
    int ID_CHERCHEUR = C1.getid();

    QSqlQuery query;
    query.prepare("SELECT * FROM chercheurs WHERE ID_CHERCHEUR = :ID_CHERCHEUR");
    query.bindValue(":ID_CHERCHEUR", ID_CHERCHEUR);
    if (query.exec() && query.next()) {
        bool test = C1.supprimer(ID_CHERCHEUR);
        if(test) {
            // Rafraîchir la vue
            ui->tableView->setModel(C.afficher());
            QMessageBox::information(nullptr,QObject::tr("Ok"),
                QObject::tr("Suppression effectuée.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr,QObject::tr("Erreur"),
                QObject::tr("Échec de la suppression.\n"
                            "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    } else {
        QMessageBox::warning(nullptr,QObject::tr("Avertissement"),
            QObject::tr("L'ID du chercheur n'existe pas.\n"
                        "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
 ui->listView->setModel(afficherHistorique(""));
}





void Chercheur1::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
   QSqlQuery qry ;
    qry.prepare("select  ID_CHERCHEUR ,NOM_CHECHEUR, PRENOM_CHERCHEUR,DOMAINE FROM  chercheurs where ID_CHERCHEUR='"+val+"'");
    if(qry.exec())
        while(qry.next())

        {  ui->le_id_chercheur_mod->setText(qry.value(0).toString());
            ui->le_nom_chercheur_mod->setText(qry.value(1).toString());
            ui->le_prenom_chercheur_mod->setText(qry.value(2).toString());
            ui->domaine_select_2->setCurrentText(qry.value(3).toString());

    }
    ui->tableView->setModel(C.afficher());
}

void Chercheur1::on_pb_modify_clicked()
{
    {


        int id_chercheur= ui->le_id_chercheur_mod->text().toInt();
        QString nom_chercheur=ui->le_nom_chercheur_mod->text();
        QString prenom_chercheur=ui->le_prenom_chercheur_mod->text();
        QString domaine = ui->domaine_select_2->currentText();
     Chercheur C (id_chercheur,nom_chercheur,prenom_chercheur,domaine);
        bool test=C.modifier(C.getid(),C.getnom(),C.getprenom(),C.getdomaine());
        if(test)
        {

           ui->tableView->setModel(C.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("Modification effectué\n"
                                                "click cancel to exit ."), QMessageBox::Cancel ) ;
        }
        else
           { QMessageBox::critical(nullptr,QObject::tr(" Not ok"),
                                    QObject::tr("Modification non effectué\n"
                                                "click cancel to exit ."), QMessageBox::Cancel ) ;


        }
    }
    ui->tableView->setModel(C.afficher());

}






void Chercheur1::on_pb_chercher_clicked()
{
    Chercheur C1;
    C1.setid(ui->le_recherche->text().toInt());
    C1.setnom(ui->le_recherche->text());
    C1.setprenom(ui->le_recherche->text());
    C1.setdomaine(ui->le_recherche->text());
    QSqlQueryModel *model = C1.recherche(C1.getid(), C1.getnom(), C1.getprenom(), C1.getdomaine());
    if(model != nullptr && model->rowCount() >= 1)
        //On vérifie si l'objet model contient des résultats de recherche et s'il y en a au moins un.
    {
        // Affichage des données dans un message box
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Elements trouvés: %1")
                                .arg(model->rowCount()),
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



void Chercheur1::on_stastique_clicked()
{
    Chercheur *m_chercheurs = new Chercheur();

    // Créer un nouveau graphique en charte
    QChart *chart = new QChart();
    chart->setTitle("Statistiques");

    // Récupérer les données pour chaque domaine
    QStringList domaines = {"IA", "Reseau", "Securite", "SE", "Quantique", "Graphique"};
    QPieSeries *series = new QPieSeries();
    int totalChercheurs = 0; // Variable pour stocker le nombre total de chercheurs
    for (const QString &domaine : domaines) {
        int nbChercheurs = m_chercheurs->nbChercheursDansDomaine(domaine);
        totalChercheurs += nbChercheurs;
    }
    for (const QString &domaine : domaines) {
        int nbChercheurs = m_chercheurs->nbChercheursDansDomaine(domaine);
        if (nbChercheurs > 0) {
            double pourcentage = (nbChercheurs * 100.0) / totalChercheurs;
            series->append(domaine + " (" + QString::number(pourcentage, 'f', 2) + "%)", nbChercheurs);
        }
    }

    // Ajouter la série au graphique
    chart->addSeries(series);

    // Définir les angles de début et de fin de la charte
    series->setPieStartAngle(90);
    series->setPieEndAngle(-270);

    // Ajouter une animation
    QChart::AnimationOptions options(QChart::AllAnimations);
    chart->setAnimationOptions(options);

    // Définir la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // Créer la vue pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(950, 720);
    chartView->show();
}





void Chercheur1::on_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

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
        "<div><img src=\"logo.png\" width=\"100\" height=\"100\" /></div>\n"
        "<div style=\"text-align:right;\">\n"
           "<center> <h1 style=\"color:lightblue;margin-bottom:0px;\">Liste des Chercheurs</h1></center>\n"
        "</div>\n"
        "</div>\n"
        "<div style=\"background-color: #f2f2f2; padding: 20px;\">\n"
        "<table border=1 cellspacing=0 cellpadding=2 style=\"background-color: #ffffff; margin: auto;\">\n";

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









void Chercheur1::on_tri_clicked()
{
    ui->tableView->setModel(C.tri());

}

void Chercheur1::on_tri_2_clicked()
{
    ui->tableView->setModel(C.tridesc());
}



void Chercheur1::on_refrech_clicked()
{
    ui->tableView->setModel(C.afficher());
}



void Chercheur1::on_imprimer_clicked()
{
    // Récupère le widget parent de ce bouton (dans cet exemple, j'utilise un QTabWidget)
    QWidget* currentWidget = ui->modifierchercheur->currentWidget();

    // Crée un objet QPrinter pour l'impression
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    // Récupère les dimensions de la page d'impression
    int dpi = printer.resolution();
    QSize pageSize = printer.pageRect().size() / dpi * 72;

    // Crée un objet QPainter pour dessiner sur la page
    QPainter painter;
    if (!painter.begin(&printer)) {
        return;
    }

    // Dessine le widget sur la page
    currentWidget->render(&painter, QPoint(), QRegion(), QWidget::DrawChildren);

    // Dessine la deuxième page
    painter.translate(0, pageSize.height());
    currentWidget->render(&painter, QPoint(), QRegion(), QWidget::DrawChildren);

    // Termine l'impression
    painter.end();
}




void Chercheur1::on_excel_clicked()
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

//HISTORIQUE



void Chercheur1::on_comboBox_activated(int index)
{
    QString historyType;
    switch (index)
    {
    case 1:  historyType = "ajout"; break;
    case 2:  historyType = "suppression"; break;
    default: historyType = ""; break;
    }
    QSqlQuery query;
    query.prepare("SELECT activite FROM CHERCHEUR_HISTORIQUE WHERE activite LIKE :historyType ORDER BY HISTORIQUE_DATES DESC");
    query.bindValue(":historyType", "%" + historyType + "%");
    if (query.exec()) {
        QStandardItemModel *model = new QStandardItemModel();
        while (query.next()) {
            QString activite = query.value(0).toString();
            QStandardItem *item = new QStandardItem(activite);
            model->appendRow(item);
        }
        ui->listView->setModel(model);
    } else {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }
}

void Chercheur1::on_comboBox_3_activated(const QString &arg1)
{
    QDateTime now = QDateTime::currentDateTime();
    QDateTime startDate;
    QString query;

    if (arg1 == "Dernières 24 heures") {
        startDate = now.addDays(-1);
        query = "SELECT activite FROM CHERCHEUR_HISTORIQUE WHERE HISTORIQUE_DATES >= '" + startDate.toString("yyyy-MM-dd hh:mm:ss") + "' ORDER BY HISTORIQUE_DATES DESC";
    } else if (arg1 == "Derniers 7 jours") {
        startDate = now.addDays(-7);
        query = "SELECT activite FROM CHERCHEUR_HISTORIQUE WHERE HISTORIQUE_DATES >= '" + startDate.toString("yyyy-MM-dd hh:mm:ss") + "' ORDER BY HISTORIQUE_DATES DESC";
    } else {
        query = "SELECT activite FROM CHERCHEUR_HISTORIQUE ORDER BY HISTORIQUE_DATES DESC";
    }

    QSqlQueryModel *model = afficherHistorique(query);
    ui->listView->setModel(model);
}

QSqlQueryModel* Chercheur1::afficherHistorique(QString query)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(query);
    return model;
}




void Chercheur1::on_pb_supprimer_historique_clicked()
{Chercheur chercheur;
    // Get the selected date from the date edit widget
    QDate selectedDate = ui->dateEdit->date();
    if (!selectedDate.isValid()) {
        QMessageBox::warning(this, "Erreur", "La date est invalide.");
        return;
    }

    // Delete the rows with the selected date
    if (chercheur.suppHistorique(selectedDate)) {
        // Show success message
        QMessageBox::information(this, "Suppression réussie", "Les données ont été supprimées avec succès.");

        // Refresh the list view
        QSqlQueryModel* updatedModel = afficherHistorique("");
        ui->listView->setModel(updatedModel);
    } else {
        // Show error message
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de la suppression des données.");
    }
}

QImage Chercheur1::generateBarcode(const QList<Conference>& conferences)
{
    // Concatenate the conference information into a single string
    QString conferenceInfo;
    foreach (const Conference& conference, conferences) {
        conferenceInfo += conference.name + " (" + conference.date.toString("yyyy-MM-dd") + ", " + conference.location + ")\n";
    }

    // Calculate the barcode size
    QFont font("Arial", 12);
    QFontMetrics fm(font);
    QRect boundingRect = fm.boundingRect(conferenceInfo);
    int width = boundingRect.width() + 20;
    int height = boundingRect.height() + 20;

    // Create the QImage and QPainter
    QImage image(width, height, QImage::Format_RGB32);
    QPainter painter(&image);

    // Draw the barcode background
    painter.fillRect(image.rect(), Qt::white);

    // Draw the barcode text
    painter.setFont(font);
    painter.drawText(QRect(10, 10, width - 20, height - 20), Qt::AlignLeft | Qt::AlignTop, conferenceInfo);

    // Draw the barcode lines
    painter.setPen(Qt::black);
    painter.drawLine(QPoint(0, 0), QPoint(width, 0));
    painter.drawLine(QPoint(0, 0), QPoint(0, height));
    painter.drawLine(QPoint(width - 1, 0), QPoint(width - 1, height));
    painter.drawLine(QPoint(0, height - 1), QPoint(width, height - 1));

    // Return the generated barcode
    return image;
}

void Chercheur1::on_retour_clicked()
{
    this->hide();
       menu *f = new menu();
       f->show();
}

