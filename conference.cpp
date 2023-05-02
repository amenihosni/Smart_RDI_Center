#include "conference.h"
#include <QSqlQuery>
Conference::Conference()
{  id=0;
  date=QDate::fromString("0000000", "dMMyyyy");
  adresse="";
  nom="";
  nbr=0;
}
Conference::Conference(int i ,QDate d, QString s,QString n)
{
    id=i;
    date=d;
    adresse=s;
    nom=n;
    nbr=0;

}
Conference::Conference(QDate d,QString s,QString n )
{
    date=d;
    adresse=s;
    nom=n;
}
QDate  Conference::get_date()
{
    return date ;
}
QString  Conference::get_adresse()
{
    return adresse;
}
void Conference::setdate(QDate d)
{
    date=d;
}
void Conference::setadresse(QString s)
{
    adresse=s;
}
bool Conference::ajouter()
{


    QSqlQuery query;
    query.prepare("INSERT INTO CONFERENCES (ID_CONFERENCE, DATE_CONFERENCE, ADRESSE,NOM_CONF,PK_AGENT) "
                  "VALUES (NULL, :date, :adresse,:nom, NULL)");

    query.bindValue(":date", date);
    query.bindValue(":adresse", adresse);
    query.bindValue(":nom", nom );
   return  query.exec();

}
QSqlQueryModel* Conference::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

        model->setQuery("SELECT  ID_CONFERENCE,DATE_CONFERENCE, ADRESSE,NOM_CONF FROM CONFERENCES");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("ADRESSE"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr(" NOM "));
    return model;

}
bool Conference::supprimer(int id)
{QSqlQuery query;
 query.prepare("Delete from CONFERENCES where ID_CONFERENCE=:id");
     query.bindValue(":id", id);

   return  query.exec();}
bool Conference::veriefier()

{     QDate dd=QDate::currentDate();
    if(date<dd)
        return false;
    else
      if(nom.isEmpty())
        return false ;
    else if(nom.size()<3)
        return  false;
      else if(adresse.isEmpty())
          return false;
      else if(adresse.size()<3)
          return false;
    else return true;

}

bool Conference::modifier()
{
    QSqlQuery query;
    query.prepare( "UPDATE CONFERENCES  SET DATE_CONFERENCE=:date,ADRESSE=:adresse,NOM_CONF=:nom WHERE  ID_CONFERENCE=:id or NOM_CONF=:nom");
    query.bindValue(":id", id);
    query.bindValue(":date", date);
    query.bindValue(":adresse", adresse);
    query.bindValue(":nom", nom );
   return  query.exec();
}
QSqlQueryModel *Conference::recherche(int id ,QString nom)
{
    QSqlQuery query;
        QSqlQueryModel* model = new QSqlQueryModel();

        query.prepare("SELECT ID_CONFERENCE,DATE_CONFERENCE, ADRESSE,NOM_CONF FROM CONFERENCES  WHERE ID_CONFERENCE=:id OR NOM_CONF=:nom ");
        query.bindValue(":id", id);
        query.bindValue(":nom", nom);



        if (query.exec()) {
            model->setQuery(query);
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
            delete model;
            model = nullptr;
        }

        return model;
}
   QSqlQueryModel * Conference::tri()
   {   QSqlQuery query;
       QSqlQueryModel *model=new QSqlQueryModel();
       query.prepare("SELECT ID_CONFERENCE,DATE_CONFERENCE, ADRESSE,NOM_CONF FROM CONFERENCES  ORDER BY EXTRACT(YEAR FROM DATE_CONFERENCE ) ASC ");
       if (query.exec()) {
           model->setQuery(query);
       } else {
           qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
           delete model;
           model = nullptr;
       }
       return model;


   }
   QSqlQueryModel *  Conference::tri_mois()
{   QSqlQuery query;
    QSqlQueryModel *model=new QSqlQueryModel();
    query.prepare("SELECT ID_CONFERENCE,DATE_CONFERENCE, ADRESSE,NOM_CONF FROM CONFERENCES  ORDER BY EXTRACT(MONTH FROM DATE_CONFERENCE ) DESC ");
    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
        delete model;
        model = nullptr;
    }
    return model;

}
   int Conference::vstatic(int mois, int annee)
   {

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS nombre_conferences FROM conferences WHERE EXTRACT(YEAR FROM DATE_CONFERENCE) =? AND EXTRACT(MONTH FROM DATE_CONFERENCE) = ?");
      query.addBindValue(annee);
    query.addBindValue(mois);

    // Exécution de la requête SQL
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête SQL";

    }

    // Récupération du nombre de conférences pour ce mois
    int nombre_conferences = 0;
    if (query.next()) {
        return nombre_conferences = query.value("nombre_conferences").toInt();
    }
    return 0;
  }
 void   Conference::afficher_date(int annee,int mois,int jour)
 {
     QSqlQuery query;
     query.prepare("SELECT DATE_CONFERENCE, NOM_CONF FROM conferences WHERE EXTRACT(YEAR FROM DATE_CONFERENCE) = ? AND EXTRACT(MONTH FROM DATE_CONFERENCE) = ? AND EXTRACT(DAY FROM DATE_CONFERENCE) = ?");
     query.addBindValue(annee);
     query.addBindValue(mois);
     query.addBindValue(jour);
         if (!query.exec()) {
             qDebug() << "Erreur lors de l'exécution de la requête SQL";
         }

         // Vérifier si la requête a renvoyé des résultats
         if (query.next()) {
             // Extraire la date en tant que QDate
              date = query.value(0).toDate();

         } /*else {
             // Aucun résultat trouvé
             qDebug() << "Aucun résultat trouvé pour l'année" << annee;

         }*/
 }

 void  Conference::afficher_nom(QDate date )
 {
     QSqlQuery query;
      query.prepare("SELECT NOM_CONF, ADRESSE FROM conferences WHERE  DATE_CONFERENCE =?  ");
         query.addBindValue(date);
         if (!query.exec()) {
             qDebug() << "Erreur lors de l'exécution de la requête SQL";
         }

         // Vérifier si la requête a renvoyé des résultats
         if (query.next()) {
             // Extraire la date en tant que QDate
              nom=query.value(0).toString();
              adresse=query.value(1).toString();

         } /*else {
             // Aucun résultat trouvé
             qDebug() << "Aucun résultat trouvé pour l'année" << date;

         }*/
 }
 void  Conference::insertionvideo(QByteArray base64Data,int id)
 {

     QSqlQuery query;
        query.prepare("UPDATE CONFERENCES SET VIDIO=:bytes WHERE ID_CONFERENCE=:id ");
       query.bindValue(":id", id);
        query.bindValue(":bytes", base64Data);

        if (!query.exec()) {
            qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();

        }
        else
        {  qWarning() << "ajout ";
        }
 }
 QByteArray   Conference::lectureVideo(int id )
 {
       QSqlQuery query;
       QByteArray bytes;
         query.prepare("SELECT VIDIO FROM CONFERENCES WHERE ID_CONFERENCE=:id");
         query.bindValue(":id", id);
         if (query.exec() && query.next()) {
           bytes = query.value(0).toByteArray();
             return  bytes;
         }
         else    qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
         return bytes;
 }
bool  Conference::notification()
{
    QSqlQuery query;
     QDate dd=QDate::currentDate();
   query.prepare("SELECT DATE_CONFERENCE FROM CONFERENCES ");
   if (!query.exec()) {
       qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();

   } else
              {
       while(query.next())
       {
         date=query.value(0).toDate();
         if(date==dd)
             return true ;
        }}
   return false;
}
 void Conference::historique(QString datetime)
 {
      QSqlQuery query;
     query.prepare("UPDATE CONFERENCES SET HISTORIQUE=:datetime WHERE ID_CONFERENCE=:id ");
     query.bindValue(":id", id);
      query.bindValue(":datetime", datetime);
      if (!query.exec()) {
          qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();

      } else
      {  qWarning() << "ajout ";
      }

 }
 QSqlQueryModel* Conference::afficherhistorique()
 {
     QSqlQueryModel *model=new QSqlQueryModel();

         model->setQuery("SELECT NOM_CONF, HISTORIQUE FROM CONFERENCES where HISTORIQUE IS NOT NULL ");
         model->setHeaderData(0, Qt::Horizontal,QObject::tr(" NOM "));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("DATE et Temp"));
     return model;

 }
 void  Conference::ajout_nbr()
 {

     QSqlQuery query;

    query.prepare("UPDATE CONFERENCES SET NOMBRE=:nbr WHERE DATE_CONFERENCE= TRUNC(SYSDATE)");

     query.bindValue(":nbr",nbr);

     if (!query.exec()) {
         qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();

     }
 }
 int   Conference::sorty_nbr()
 {
     int n=0;
     QSqlQuery query;
    query.prepare("SELECT NOMBRE FROM CONFERENCES");


     if (!query.exec()) {
         qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();

     } else
                {
         while(query.next())
         {
           n=query.value(0).toInt();

          }}
     return n;
 }
QString Conference::type_conference()
{
    QString n;
    QSqlQuery query;

 query.prepare("SELECT NOM_CONF FROM CONFERENCES WHERE DATE_CONFERENCE = TRUNC(SYSDATE)");

    if (!query.exec()) {
        qWarning() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
    } else {
        if (query.next()) {
            n = query.value(0).toString();
        }
    }
    return n;

}
