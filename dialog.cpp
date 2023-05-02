#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlQuery>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
bool  Dialog::chercher_visteur(QString numstring)
{
    QSqlQuery query;

    query.prepare("SELECT ID_CHERCHEUR,NOM_CHECHEUR,PRENOM_CHERCHEUR FROM CHERCHEURS WHERE ID_CARTE=:SERIAL_NUMBER");
    query.bindValue(":SERIAL_NUMBER", numstring);
    if (query.exec()) {
        // Check if the query returned any records
        if (query.next() && query.isValid()) {
            // la donnée existe dans la table
            id=query.value("ID_CHERCHEUR").toString();
            nom = query.value("NOM_CHECHEUR").toString();
            prenom = query.value("PRENOM_CHERCHEUR").toString();

            return true;
        } else {
            // The query did not return any records
            qWarning() << "Aucun résultat trouvé pour la requête.";
            return false;
        }
    }
    else {
        qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return false;
    }
}
void Dialog::afficher()
 {  ui->nom_arduino->setText(nom);
    ui->prenom_arduino->setText(prenom);
    ui->nombre_arduino->setText(QString::number(c.sorty_nbr()));
}

void Dialog::on_sortie_clicked()
{
    a.write_to_arduino("1");
}
