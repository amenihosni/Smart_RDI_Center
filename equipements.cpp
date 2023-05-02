#include "equipements.h"
#include <QSqlQuery>
#include <QObject>
#include<QDebug>
#include<QSqlQueryModel>
#include<QSqlRecord>
#include<QSqlError>
#include <QMessageBox>

equipements::equipements()
{
    QUANTITE=0; ETAT=0; PRIX=0;
    NOM_EQ="";DOMAINE_EQUIPEMENTS="";
}
equipements::equipements(int ID,QString NOM_EQ,QString DOMAINE_EQUIPEMENTS,int QUANTITE,int PRIX,int ETAT)
{
    this->ID=ID;
    this->NOM_EQ=NOM_EQ;
    this->DOMAINE_EQUIPEMENTS=DOMAINE_EQUIPEMENTS;
    this->QUANTITE= QUANTITE;
    this->PRIX=PRIX;
    this->ETAT=ETAT;
}
equipements::equipements(int ID)
{
    this->ID=ID;
}

equipements::equipements(QString NOM_EQ,QString DOMAINE_EQUIPEMENTS,int QUANTITE ,int PRIX,int ETAT)
{
    this->NOM_EQ=NOM_EQ;
    this->DOMAINE_EQUIPEMENTS=DOMAINE_EQUIPEMENTS;
    this->QUANTITE=QUANTITE;
    this->PRIX=PRIX;
    this->ETAT=ETAT;
}
int equipements::getid(){return ID;}
int equipements::getquantite(){return QUANTITE;}
int equipements::getetat(){return ETAT;}
QString equipements::getnomeq(){return  NOM_EQ;}
QString equipements::getdomaineq(){return DOMAINE_EQUIPEMENTS;}
int equipements::getprix(){return PRIX;}
void equipements::setquantite (int QUANTITE){this->QUANTITE=QUANTITE;}
void equipements::setetat (int ETAT ){this->ETAT=ETAT;}
void equipements::setnomeq(QString NOM_EQ){this->NOM_EQ=NOM_EQ;}
void equipements::setdomaineq(QString DOMAINE_EQUIPEMENTS){this->DOMAINE_EQUIPEMENTS=DOMAINE_EQUIPEMENTS;}
void equipements::setprix(int PRIX){this->PRIX=PRIX; }
void equipements::seteid(int ID){this->ID=ID;}

bool equipements::ajouter( QByteArray IMAGE)
{


    QSqlQuery query;
    QSqlRecord rec = query.record();
    query.prepare("INSERT INTO equipement (nom, domaine, etat, prix, id_agent, quantite,image) "
               //"VALUES (:NOM_EQ, :DOMAINE_EQUIPEMENTS,:ETAT, :PRIX,1,:quantite)");
    "VALUES (:NOM_EQ, :DOMAINE_EQUIPEMENTS, :ETAT, :PRIX,1,:QUANTITE,:IMAGE)");

    query.bindValue(":DOMAINE_EQUIPEMENTS" , DOMAINE_EQUIPEMENTS);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":ETAT", ETAT );
    query.bindValue(":PRIX", PRIX );
    query.bindValue(":NOM_EQ", NOM_EQ );
    query.bindValue(":IMAGE", IMAGE );

    qDebug() << "Number of columns: " << rec.count();
   return  query.exec();

}

QSqlQueryModel* equipements::afficher()
{
    //recupere les donnee d une base de donne en entilisant la reqette sql et les afficher dans une view
    QSqlQueryModel *model=new QSqlQueryModel();

        model->setQuery("SELECT  ID,NOM,DOMAINE,ETAT,PRIX,QUANTITE FROM EQUIPEMENT");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr(" NOM_EQ "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("DOMAINE_EQUIPEMENTS"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr(" ETAT "));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr(" PRIX "));
        model->setHeaderData(5, Qt::Horizontal,QObject::tr("QUANTITE"));


    return model;

}
bool equipements::supprimer(int id)
{
    QSqlQuery query;
 query.prepare("Delete from EQUIPEMENT where ID=:id");
     query.bindValue(":id", id);

   return  query.exec();
}



bool equipements::modifier()
{
    //recupere les donnes et les manipule

    QSqlQuery query;
    query.prepare( "UPDATE EQUIPEMENT  SET NOM=:NOM,DOMAINE=:DOMAINE,ETAT=:ETAT,PRIX=:PRIX ,QUANTITE=:QUANTITE WHERE  ID=:ID ");
    query.bindValue(":ID", ID);
    query.bindValue(":NOM", NOM_EQ);
    query.bindValue(":DOMAINE",DOMAINE_EQUIPEMENTS);
    query.bindValue(":ETAT", ETAT);
    query.bindValue(":PRIX", PRIX );
    query.bindValue(":QUANTITE", QUANTITE );
    if (!query.execBatch())
        qDebug() << query.lastError();
   return  query.exec();
}
bool equipements::modifierArd(int ID)
{
    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENT SET ETAT=1 WHERE ID=:ID");
    query.bindValue(":ID", ID);
    if (!query.execBatch())
        qDebug() << query.lastError();
    return query.exec();
}

bool equipements::veriefier()
{
      if(NOM_EQ=="")
        return false ;
    else if(DOMAINE_EQUIPEMENTS=="")
        return false ;
    else if(ETAT<0 || ETAT>1)
        return  false;
      else if(PRIX<0)
          return false;
      else if(QUANTITE<0)
          return false;
    else return true;

}

QSqlQueryModel *equipements ::recherche(int ID,QString NOM_EQ,QString DOMAINE_EQUIPEMENTS,int ETAT)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    query.prepare("SELECT ID,DOMAINE,QUANTITE,ETAT,PRIX,NOM from EQUIPEMENT where ID LIKE :ID or ETAT LIKE :ETAT");
    query.bindValue(":ID", ID);
    //query.bindValue(":NOM", NOM_EQ);
    //query.bindValue(":DOMAINE",DOMAINE_EQUIPEMENTS);
    query.bindValue(":ETAT", ETAT);

    if (query.exec()) {
                model->setQuery(query);
            } else {
                qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
                delete model;
                model = nullptr;
            }

    return model;
}

QSqlQueryModel* equipements ::TrierDesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT ID,DOMAINE,QUANTITE,ETAT,PRIX,NOM FROM EQUIPEMENT ORDER BY NOM DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DOMAINE_EQUIPEMENTS"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr(" ETAT "));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr(" PRIX "));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr(" NOM_EQ "));

        return model;
}




void  equipements::insertionimage(QByteArray base64Data,int ID)
 {

     QSqlQuery query;
        query.prepare("UPDATE EQUIPEMENT SET IMAGE=:bytes WHERE ID=:ID ");
       query.bindValue(":ID", ID);
        query.bindValue(":bytes", base64Data);

        if (!query.exec()) {
            qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();

        }
        else
        {  qWarning() << "ajout ";
        }
 }

QByteArray equipements::afficherimage()
{
    QByteArray imageData;
    // Récupérer les données de l'image à partir de la base de données
    QSqlQuery query("SELECT image_data FROM images WHERE id = " + QString::number(ID));
    if (query.next()) {
        imageData = query.value("image_data").toByteArray();
    }
    return imageData;
}
QString equipements::rech(int id)
{
    QSqlQuery query;
    query.prepare("SELECT nom FROM equipement WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            return query.value(0).toString(); // Return the matricule for the given id
        } else {
            return QString(); // Return an empty QString if the id does not exist in the database
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
        return QString(); // Return an empty QString in case of an error
    }
}
