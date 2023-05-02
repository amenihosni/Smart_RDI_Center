#ifndef CONFERENCE_H
#define CONFERENCE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
class Conference
{ private :
    int id,nbr;
  QDate date;
  QString adresse,nom ;
public:
    Conference();
    Conference(int,QDate, QString,QString);
    Conference(QDate, QString,QString);
    int get_id(){return id;}
    QDate get_date();
    QString get_adresse();
    QString get_nom(){return nom;}
    void setid(int i){id=i;};
    void setdate(QDate);
    void setadresse(QString);
    void setnom(QString n){ nom=n;}
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool veriefier();
    bool modifier();
   int vstatic(int,int);
   QSqlQueryModel * recherche(int,QString);
   QSqlQueryModel * tri();
   QSqlQueryModel * tri_mois();
   void  afficher_date(int,int,int);
   void  afficher_nom(QDate);
   void insertionvideo(QByteArray,int);
   QByteArray  lectureVideo(int);
   bool notification();
   void historique(QString);
   QSqlQueryModel* afficherhistorique();
   void ajout_nbr();
   void set_nbr(int n){nbr=n;}
   int   sorty_nbr();
   int get_nbr(){return nbr; }
   QString type_conference();
   ~Conference(){}

};

#endif // CONFERENCE_H
