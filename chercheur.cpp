#include "chercheur.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QDateTime>
#include <QFile>
Chercheur::Chercheur(QString nom,QString prenom,QString domaine)
{
this->nom_chercheur=nom;
this->prenom_chercheur=prenom;
this->domaine=domaine;
}
Chercheur::Chercheur(int id,QString nom,QString prenom,QString domaine)
{
this->id_chercheur=id;
this->nom_chercheur=nom;
this->prenom_chercheur=prenom;
this->domaine=domaine;
}



bool Chercheur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO chercheurs (ID_CHERCHEUR, NOM_CHECHEUR, PRENOM_CHERCHEUR, DOMAINE) "
                  "VALUES (NULL, :nom_chercheur, :prenom_chercheur, :domaine)");
    query.bindValue(":nom_chercheur", nom_chercheur);
    query.bindValue(":prenom_chercheur", prenom_chercheur);
    query.bindValue(":domaine", domaine);
    bool result = query.exec();

    if(result)
    {
       // Obtenir l'ID du dernier enregistrement inséré
       query.exec("SELECT MAX(ID_CHERCHEUR) FROM chercheurs");
       if(query.first()) {
           int ID = query.value(0).toInt();
           ajouterHistorique("Ajout", "chercheur", ID);
       }
    }

    return result;
}






QSqlQueryModel * Chercheur::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM chercheurs");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CHERCHEUR"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_CHECHEUR"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_CHERCHEUR"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("DOMAINE"));
   return model;
}

bool Chercheur::supprimer(int ID_CHERCHEUR)
{
    QSqlQuery query;
    query.prepare("SELECT ID_CHERCHEUR FROM chercheurs WHERE ID_CHERCHEUR = :ID_CHERCHEUR");
    query.bindValue(":ID_CHERCHEUR", ID_CHERCHEUR);
    if (!query.exec() || !query.next()) {
        return false;
    }
    int ID = query.value(0).toInt();

    query.prepare("DELETE FROM chercheurs WHERE ID_CHERCHEUR = :ID_CHERCHEUR");
    query.bindValue(":ID_CHERCHEUR", ID_CHERCHEUR);

    if (query.exec()) {
        // Ajouter l'historique de la suppression
        QString action = "Suppression";
        QString type = "Chercheur";
        ajouterHistorique(action, type, ID);
        return true;
    } else {
        return false;
    }
}




bool Chercheur::modifier(int ID_CHERCHEUR ,QString NOM_CHECHEUR ,QString PRENOM_CHERCHEUR,QString DOMAINE)
{

QSqlQuery query;
query.prepare("UPDATE chercheurs SET NOM_CHECHEUR=:NOM_CHECHEUR,PRENOM_CHERCHEUR=:PRENOM_CHERCHEUR,DOMAINE=:DOMAINE WHERE ID_CHERCHEUR=:ID_CHERCHEUR;");

    query.bindValue(":ID_CHERCHEUR",ID_CHERCHEUR);
    query.bindValue(":NOM_CHECHEUR",NOM_CHECHEUR);
    query.bindValue(":PRENOM_CHERCHEUR",PRENOM_CHERCHEUR);
    query.bindValue(":DOMAINE",DOMAINE);
return    query.exec();
}

QSqlQueryModel* Chercheur::recherche(int ID_CHERCHEUR, QString NOM_CHECHEUR, QString PRENOM_CHERCHEUR, QString DOMAINE)
{
    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();

    query.prepare("SELECT * FROM chercheurs WHERE ID_CHERCHEUR=:ID_CHERCHEUR OR NOM_CHECHEUR=:NOM_CHECHEUR OR PRENOM_CHERCHEUR=:PRENOM_CHERCHEUR OR DOMAINE=:DOMAINE");
    query.bindValue(":ID_CHERCHEUR", ID_CHERCHEUR);
    query.bindValue(":NOM_CHECHEUR", NOM_CHECHEUR);
    query.bindValue(":PRENOM_CHERCHEUR", PRENOM_CHERCHEUR);
    query.bindValue(":DOMAINE", DOMAINE);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        delete model;
        model = nullptr;
    }
//verification si la requette echoue ou non
    return model;
}
int Chercheur::nbChercheursDansDomaine(QString domaine)
{
    int nbChercheurs = 0;
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM chercheurs WHERE domaine = ?");
    query.bindValue(0, domaine);
    if (query.exec() && query.next()) {
        nbChercheurs = query.value(0).toInt();
    } else {
        // Gérer l'erreur
    }
    return nbChercheurs;
}
QSqlQueryModel * Chercheur::tri()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    query.prepare("SELECT ID_CHERCHEUR, NOM_CHECHEUR, PRENOM_CHERCHEUR, DOMAINE FROM chercheurs ORDER BY ID_CHERCHEUR ASC");
    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        delete model;
        model = nullptr;
    }
    return model;
}

QSqlQueryModel * Chercheur::tridesc()
{
    QSqlQuery query;
        QSqlQueryModel *model = new QSqlQueryModel();
        query.prepare("SELECT ID_CHERCHEUR, NOM_CHECHEUR, PRENOM_CHERCHEUR, DOMAINE FROM chercheurs ORDER BY NOM_CHECHEUR DESC");
        if (query.exec()) {
            model->setQuery(query);
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
            delete model;
            model = nullptr;
        }
        return model;
}













































void Chercheur::ajouterHistorique(QString action, QString type, int id)
{
    QSqlQuery query1;
    query1.prepare("select * from CHERCHEUR_HISTORIQUE where TRUNC(HISTORIQUE_DATES) = TRUNC(SYSDATE)");
    query1.exec();

    QString date=QDateTime::currentDateTime().toString("dddd, dd MMMM yyyy");
    QString date1=QDateTime::currentDateTime().toString("dd/MM/yy");
    QString time=QDateTime::currentDateTime().toString("hh:mm");
    QString activite = "\n    " + date1 + "   -   " + time + " \t    " + action + " " + type + " d'identifiant:  " + QString::number(id) + " \n"; // correction ici pour convertir id en QString

    QSqlQuery query;
    query.prepare("INSERT INTO CHERCHEUR_HISTORIQUE (activite, HISTORIQUE_DATES) VALUES (:activite, SYSDATE)");
    query.bindValue(":activite", activite);
    query.exec();

    activite = "\n\t\t\t\t" + date + "\n";
    if (!query1.next()) // if first activity of the day
    {
        query.prepare("INSERT INTO CHERCHEUR_HISTORIQUE (activite, HISTORIQUE_DATES) VALUES (:activite, SYSDATE)");
        query.bindValue(":activite", activite);
        query.exec();
    }
    else
    {
        query.prepare("delete from CHERCHEUR_HISTORIQUE where TRUNC(HISTORIQUE_DATES) = TRUNC(SYSDATE) and activite = :activite ");
        query.bindValue(":activite", activite);
        query.exec();

        query.prepare("INSERT INTO CHERCHEUR_HISTORIQUE (activite, HISTORIQUE_DATES) VALUES (:activite, SYSDATE)");
        query.bindValue(":activite", activite);
        query.exec();
    }
}




bool Chercheur::suppHistorique(QDate historiqueDate)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CHERCHEUR_HISTORIQUE WHERE HISTORIQUE_DATES = :historiqueDate");
    query.bindValue(":historiqueDate", historiqueDate);

    return query.exec();
}

QSqlQueryModel * Chercheur::afficherChercheurArticle()
{

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("SELECT ID_CHERCHEUR,NOM_CHECHEUR FROM chercheurs");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CHERCHEUR"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_CHECHEUR"));
return model;
}











