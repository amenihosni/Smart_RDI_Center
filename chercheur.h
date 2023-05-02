#ifndef CHERCHEUR_H
#define CHERCHEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Chercheur
{
public:
    //constructeurs
    Chercheur(){}
    Chercheur(QString,QString,QString);
    Chercheur(int,QString,QString,QString);

    //getters
    int getid(){return id_chercheur;}
QString getnom(){return nom_chercheur;}
QString getprenom(){return prenom_chercheur;}
QString getdomaine(){return domaine;}
//setters
void setnom(QString n){nom_chercheur=n;}
void setprenom(QString p){prenom_chercheur=p;}
void setid(int id){this->id_chercheur=id;}
void setdomaine(QString domaine){this->domaine=domaine;}
//fonctionnalité
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
 bool modifier(int,QString,QString,QString);
  QSqlQueryModel * recherche(int id,QString nom,QString prenom,QString domaine);
  int nbChercheursDansDomaine(QString domaine);
QSqlQueryModel * tri();
QSqlQueryModel * tridesc();
void ajouterHistorique(QString, QString , int);
QSqlQueryModel* afficherHistorique();
bool suppHistorique(QDate);
QSqlQueryModel * afficherChercheurArticle();

     private:
    int id_chercheur;
   QString nom_chercheur;
   QString prenom_chercheur;
   QString domaine;
};

#endif // CHERCHEUR_H
